/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#pragma once
#ifndef __Player__
#define __Player__

#include <vector>

#include "DisplayObject.h"
#include "TextureManager.h"
#include "SoundManager.h"

#include "Tile.h"
#include "Scene.h"
#include "Bullet.h"

class Player :
	public DisplayObject
{
public:
	Player();
	~Player();

	// Inherited via GameObject
	void draw() override;

	void update() override;

	void clean() override;

	void turnRight();
	void turnLeft();
	void move();

	// pathfinding behaviours
	Tile* getTile();
	void setTile(Tile* newTile);
	void setPowerUp(int value);
	static const int MAX_BULLETS = 30;
	Bullet* mBullets[MAX_BULLETS];
	void handleFiring();
	glm::vec2 getTarget();
	void setTarget(glm::vec2 position);
	void decreaseLife();
private:

	void m_checkState();
	void m_checkBounds();

	void m_reset();

	//health
	int m_health;
	int m_powerUp;

	// steering behaviours
	void m_seek();
	float m_maxSpeed;
	double m_currentDirection;
	float m_turnSpeed;
	float m_steerForce;
	glm::vec2 m_target;

	Tile* m_currentTile;
};


#endif /* defined (__Player__) */

