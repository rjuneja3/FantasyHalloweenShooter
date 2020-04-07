/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"

#include "Player.h"
#include "Bullet.h"
#include "Background.h"
#include "Background1.h"
#include "Dragon.h"
#include "SmallEnemy.h"
#include "MediumBoss.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();

	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
	static const int MAX_DRAGONS = 5;
	static const int MAX_SMALL_ENEMIES = 3;

	

	// getters
	glm::vec2 getMousePosition();
	

private:
	// game objects

	glm::vec2 m_mousePosition;

	int m_mouseRegister;
	Player* m_pPlayer;
	Bullet* m_pBullet;
	Background* m_pBackground;
	Background1* m_pBackground1;
	
	Dragon* m_pDragon[MAX_DRAGONS];
	SmallEnemy* m_pSmallEnemies[MAX_SMALL_ENEMIES];
	MediumBoss* m_pMediumBoss;
	Label* m_pLabel;
};

#endif /* defined (__LEVEL_1_SCENE__) */
