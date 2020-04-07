/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#pragma once
#include "DisplayObject.h"
#ifndef __POWER_UP__

class PowerUp : public DisplayObject
{
public:
	PowerUp();
	~PowerUp();
	void draw() override;
	void update() override;
	void clean() override;
	void start(glm::vec2 position);
	void reset();
	bool isActive;
private:
	float m_alpha;
};
#endif
