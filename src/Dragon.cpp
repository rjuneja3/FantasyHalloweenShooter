
/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/#include "Dragon.h"
#include "Game.h"

Dragon::Dragon()
{
	m_alpha = 255;
	TheTextureManager::Instance()->load("../Assets/dragon (1).png",
		"Dragon", TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("Dragon");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(0.0f, 0.0f));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setAcceleration(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setActive(true);
	setType(GameObjectType::DRAGON);
	m_health = 2;
	m_angle = 0;
	m_rotationAngel = 0;
	reset();
	m_pPowerUp = new PowerUp();
}

Dragon::~Dragon()
{
}

void Dragon::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	//xComponent = 700;
	//yComponent = 300;

	TheTextureManager::Instance()->draw("Dragon", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), m_angle, m_alpha, true);
	//m_pPowerUp->draw();
}

void Dragon::update()
{
	
	glm::vec2 currentPosition = getPosition();
	move();
	if (getPosition().x <= 0 - getWidth())
	{
		reset();
	}
	if(m_health <= 0)
	{
		int randomNumber = (rand() % 10) + 1;
		int condition = (rand() % 10) + 1;
		//std::cout << "Random: " << randomNumber << " Condition: " << condition << std::endl;
		if(randomNumber == condition)
		{
			m_pPowerUp->start(getPosition());
		}
		reset();
		m_health = 2;
	}
	m_pPowerUp->update();
	//m_angle += m_rotationAngel;
	
}

void Dragon::clean()
{

}

void Dragon::move()
{
	setPosition(glm::vec2((getPosition().x - 10), getPosition().y));
}

void Dragon::reset()
{
	//m_rotationAngel = 0.1 * ((rand() % 10) + 1);
	//m_angle = (rand() % 179) + 1;
	glm::vec2 currentPosition = getPosition();
	m_alpha = 255;
	currentPosition.x = rand() % 500 + Config::SCREEN_WIDTH;
	currentPosition.y = rand() % (600 - getHeight()) + getHeight() * 0.5 + 1;
	if(m_health <= 0)
	{
		currentPosition.x += 250.0f;
	}
	setPosition(currentPosition);
}

void Dragon::getDamage()
{
	m_health--;
	//reset();
}

void Dragon::setActive(bool active)
{
	m_isActive = active;
}

bool Dragon::isActive()
{
	return m_isActive;
}

PowerUp* Dragon::getPowerUp()
{
	return m_pPowerUp;
}

