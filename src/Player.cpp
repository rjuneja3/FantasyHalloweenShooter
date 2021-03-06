/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#include "Player.h"
#include "Game.h"
#include "Util.h"
#include "GLM/gtx/rotate_vector.hpp"
#include "PlayScene.h"
#include "Level1Scene.h"
#include "GLM/gtx/string_cast.hpp"
#include "ScoreBoardManager.h"


Player::Player() :
	m_maxSpeed(5.0f), m_currentDirection(0.0f), m_turnSpeed(2.0f), m_steerForce(0.1f), m_currentTile(NULL)
{
	TheTextureManager::Instance()->load("../Assets/player.png",
		"player", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("player");
	
	setWidth(size.x);
	setHeight(size.y);
	setPosition(getPosition());
	setVelocity(glm::vec2(0.0f, 0.0f));
	setAcceleration(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setType(GameObjectType::PLAYER);
	setState(SteeringState::IDLE);
	m_health = 25;

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		mBullets[i] = new Bullet();
	}
	m_powerUp = 0;
}


Player::~Player()
{
}

void Player::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("player", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), m_currentDirection, 255,true );
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		mBullets[i]->draw();
	}
}

void Player::m_checkState()
{
	switch (getState())
	{
	case SteeringState::IDLE:
		move();
		break;
	case SteeringState::SEEK:
		m_seek();
		//move();
		break;
	case SteeringState::ARRIVE:
		break;
	case SteeringState::AVOID:
		break;
	case SteeringState::FLEE:
		break;
	}
}

void Player::update()
{
	move();
	//handleFiring();
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		mBullets[i]->update();
	}
	setPowerUp(ScoreBoardManager::Instance()->getPowerUp());
}

void Player::handleFiring()
{
	int numberOfBullets = 10;
	if(m_powerUp == 0)
	{
		numberOfBullets = 10;
		for (int i = 0; i < numberOfBullets; i++)
		{
			if (!mBullets[i]->isActive())
			{
				mBullets[i]->fire(this->getPosition());
				break;
			}
		}
	}
	if(m_powerUp == 1)
	{
		numberOfBullets = 20;
		for (int i = 0; i < numberOfBullets; i++)
		{
			if (!mBullets[i]->isActive())
			{
				mBullets[i]->fire(glm::vec2(this->getPosition().x,
					this->getPosition().y + this->getHeight() * 1 / 3));
				mBullets[i + 1]->fire(glm::vec2(this->getPosition().x,
					this->getPosition().y - this->getHeight() * 1 / 3));
				break;
			}
		}
	}
	if(m_powerUp == 2)
	{
		numberOfBullets = 30;
		for (int i = 0; i < numberOfBullets; i++)
		{
			if (!mBullets[i]->isActive())
			{
				mBullets[i]->fire(glm::vec2(this->getPosition().x,
					this->getPosition().y), TOP);
				mBullets[i + 1]->fire(glm::vec2(this->getPosition().x,
					this->getPosition().y), MIDDLE);
				mBullets[i + 2]->fire(glm::vec2(this->getPosition().x,
					this->getPosition().y), BOTTOM);
				break;
			}
		}
	}

}



void Player::clean()
{
	delete m_currentTile;
	m_currentTile = NULL;
}

void Player::turnRight()
{
	m_currentDirection += m_turnSpeed;
	if (m_currentDirection >= 360)
	{
		m_currentDirection = 0;
	}

}

void Player::turnLeft()
{
	m_currentDirection -= m_turnSpeed;
	if (m_currentDirection < 0)
	{
		m_currentDirection = 359.0;
	}
}

void Player::move()
{
	if (Util::distance(getPosition(), m_target) > 1.0f) {
		glm::vec2 desired = Util::normalize(m_target - getPosition()) * m_maxSpeed;
		setVelocity(desired);


		glm::vec2 newPosition = getPosition() + getVelocity();
		setPosition(newPosition);
	}


}

Tile* Player::getTile()
{
	return m_currentTile;
}

void Player::setTile(Tile* newTile)
{
	m_currentTile = newTile;
}

void Player::setPowerUp(int value)
{
	m_powerUp = value;
}

glm::vec2 Player::getTarget()
{
	return m_target;
}

void Player::setTarget(glm::vec2 position)
{
	m_target = position;
}
//decrease life when hit on comet and check the life at the same time
void Player::decreaseLife()
{
	m_health -= 1;

	if(m_health <= 0)
	{
		TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
	}
}


void Player::m_checkBounds()
{

	if (getPosition().x > Config::SCREEN_WIDTH)
	{
		setPosition(glm::vec2(0.0f, getPosition().y));
	}

	if (getPosition().x < 0)
	{
		setPosition(glm::vec2(800.0f, getPosition().y));
	}

	if (getPosition().y > Config::SCREEN_HEIGHT)
	{
		setPosition(glm::vec2(getPosition().x, 0.0f));
	}

	if (getPosition().y < 0)
	{
		setPosition(glm::vec2(getPosition().x, 600.0f));
	}

}

void Player::m_reset()
{
	setIsColliding(false);
	int halfWidth = getWidth() * 0.5;
	int xComponent = rand() % (640 - getWidth()) + halfWidth + 1;
	int yComponent = -getHeight();
	setPosition(glm::vec2(xComponent, yComponent));
}

void Player::m_seek()
{
	glm::vec2 desired = Util::normalize(m_target - getPosition()) * m_maxSpeed;
	glm::vec2 steer = (desired - getVelocity());

	steer = Util::limitMagnitude(steer, m_steerForce);
	setAcceleration(steer);
}
