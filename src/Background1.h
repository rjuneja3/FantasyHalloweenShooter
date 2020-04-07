/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/
#pragma once
#ifndef __BACKGROUND1__
#define __BACKGROUND1__
#include "DisplayObject.h"
#include "Scene.h"

#include "DisplayObject.h"
#include "TextureManager.h"

class Background1 : public DisplayObject
{


public:
	Background1();
	~Background1();

	void draw() override;
	void update() override;
	void clean() override;

	float getFlowingSpeed();
	glm::vec2 getStartingPosition();

	void setStartingPosition(glm::vec2 startingPosition);
	void setFlowingSpeed(float speed);

private:

	float m_flowingSpeed;
	glm::vec2 m_startingPosition;
};

#endif /* Defined background1*/