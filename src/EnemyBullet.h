#pragma once

#ifndef __ENEMY_BULLET__
#define __ENEMY_BULLET__

#include <vector>

#include "DisplayObject.h"
#include <SDL_hints.h>
/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/#include "Dragon.h"


class EnemyBullet : public DisplayObject
{
public:
	EnemyBullet();
	~EnemyBullet();

	void draw() override;
	void update() override;
	void clean() override;

	void setActive(bool active);
	bool isActive();

	void fire(glm::vec2 position);
	//setter
	void setSpeed(float newSpeed);
	//getter
	float getSpeed();
	void checkBounds();
	void reset();

private:

	Uint8 m_alpha;
	bool m_isActive;
	float m_speed;

};




#endif
