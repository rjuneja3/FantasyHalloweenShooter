/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/
#pragma once
#ifndef __Dragon__
#define __Dragon__

#include <vector>

#include "DisplayObject.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include "PowerUp.h"

class Dragon:public DisplayObject
{
public:
	Dragon();
	~Dragon();
	void draw() override;
	void update() override;
	void clean() override;
	void move();
	void reset();
	void getDamage();
	void setActive(bool active);
	bool isActive();
	PowerUp* getPowerUp();
private:
	float m_maxSpeed;
	double m_currentDirection;
	Uint8 m_alpha;
	bool m_isActive;
	int m_health;
	float m_angle;
	float m_rotationAngel;

	PowerUp* m_pPowerUp;
};

#endif
