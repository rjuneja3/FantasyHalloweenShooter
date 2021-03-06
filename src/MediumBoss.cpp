/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#include "MediumBoss.h"
#include "Game.h"
#include "ScoreBoardManager.h"

MediumBoss::MediumBoss()
	:Enemy(
		"../Assets/Boss.png",
		"mediumEnemy",
		ENEMY, glm::vec2(Config::SCREEN_WIDTH*1.2, Config::SCREEN_HEIGHT*0.5))
{
	m_health = 50;

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		pEnemyBullets[i] = new EnemyBullet();
	}
}
MediumBoss::~MediumBoss()
= default;

void MediumBoss::update()
{
	if (getPosition().x >= Config::SCREEN_WIDTH * 0.9) {
		setPosition(glm::vec2((getPosition().x - 2), getPosition().y));
	}
	//move enemies up
	if (getMovingUp()) {
		setPosition(glm::vec2(getPosition().x, (getPosition().y - 2)));
		if (getPosition().y <= (300 - 200)) {
			setMovingUp(false);
		}
	}
	//move enemies down
	if (!getMovingUp()) {
		setPosition(glm::vec2(getPosition().x, (getPosition().y + 2)));
		if (getPosition().y >= (300 + 200)) {
			setMovingUp(true);
		}
	}

	if (m_health <= 0)
	{
		setAlpha(0);
		setIsColliding(false);
		setPosition(glm::vec2(0.0f, -getHeight()));
	}

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		pEnemyBullets[i]->update();
	}
}

void MediumBoss::decreaseHealth()
{
	m_health -= 1;
	if (m_health <= 0) {
		//increase the score when enemy dies
		ScoreBoardManager::Instance()->setScore(ScoreBoardManager::Instance()->getScore() + 500);

		ScoreBoardManager::Instance()->setEnemies("Decrease");
		if (ScoreBoardManager::Instance()->enemiesLeft() <= 0) {
			Game::Instance()->changeSceneState(NEXT_LEVEL_SCENE);
		}
	}
}

void MediumBoss::clean()
{
}

int MediumBoss::getHealth()
{
	return m_health;
}

void MediumBoss::handleFiring()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (!pEnemyBullets[i]->isActive())
		{
			std::cout << "ENEMYF IRES" << std::endl;
			pEnemyBullets[i]->fire(this->getPosition());
			break;
		}
	}
}

void MediumBoss::drawBullets()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		pEnemyBullets[i]->draw();
	}
}
