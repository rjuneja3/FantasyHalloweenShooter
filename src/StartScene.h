/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "StartButton.h"
#include "Label.h"
#include "Background.h"
#include "Background1.h"
#include "HomeButton.h"
#include "InstructionsButton.h"

class StartScene : public Scene
{
public:
	// constructor
	StartScene();
	// destructor
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
	
	// getters
	glm::vec2 getMousePosition();
private:
	Label* m_pStartLabel;
	// game objects

	glm::vec2 m_mousePosition;
	Background* m_pBackground;
	Background1* m_pBackground1;
	StartButton* m_pStartButton;
	InstructionsButton* m_pInstructionsButton;
};

#endif /* defined (__START_SCENE__) */