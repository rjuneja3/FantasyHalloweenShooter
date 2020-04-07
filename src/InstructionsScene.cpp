/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#include "InstructionsScene.h"
#include "Game.h"
#include <iostream>
#include "Background.h"
#include "Background1.h"
#include "CollisionManager.h"
#include "ScoreBoardManager.h"
#include "HomeButton.h"

InstructionsScene::InstructionsScene()
{
	start();
}

InstructionsScene::~InstructionsScene()
{
}
//Draw the gameobjects for the scene
void InstructionsScene::draw()
{

	m_pBackground->draw();
	m_pBackground1->draw();
	m_pInstructionsTitleLabel->draw();
	m_pInstructionsContentLabel1->draw();
	m_pInstructionsContentLabel2->draw();
	m_pInstructionsContentLabel3->draw();
	m_pInstructionsContentLabel4->draw();
	m_pInstructionsContentLabel5->draw();
	m_pInstructionsContentLabel6->draw();
	m_pHomeButton->draw();
}



void InstructionsScene::update()
{

	m_pBackground->update();
	m_pBackground1->update();
	m_pHomeButton->setMousePosition(m_mousePosition);
	m_pHomeButton->ButtonClick();

}



void InstructionsScene::clean()
{
	delete m_pInstructionsTitleLabel;
	delete m_pInstructionsContentLabel1;
	delete m_pInstructionsContentLabel2;
	delete m_pInstructionsContentLabel3;
	delete m_pInstructionsContentLabel4;
	delete m_pInstructionsContentLabel5;
	delete m_pInstructionsContentLabel6;
	removeAllChildren();
}

void InstructionsScene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				//check the button and register the click
				if (m_mouseRegister < 1) {
					m_mouseRegister = 1;
					m_pHomeButton->setMouseButtonClicked(true);
				}
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_mouseRegister = 0;
				m_pHomeButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;

			case SDLK_w:

				break;
			case SDLK_s:

				break;
			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}

			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:

				break;

			case SDLK_s:

				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}

			break;
		default:
			break;
		}
	}
}

void InstructionsScene::start()
{
	// allocates memory on the heap for this game object


	m_pBackground = new Background();
	m_pBackground1 = new Background1();
	SDL_Color white = { 255, 255, 255, 255 };
	m_pInstructionsTitleLabel = new Label("Instructions: ", "Consolas", 70, white, glm::vec2(400.0f, 30.0f));
	m_pInstructionsContentLabel1 = new Label("Use Mouse Left click to shoot.", "Consolas", 20, white, glm::vec2(400.0f, 150.0f));
	m_pInstructionsContentLabel2 = new Label("Killing each Enemy gives you 100 Points!", "Consolas", 20, white, glm::vec2(400.0f, 175.0f));
	m_pInstructionsContentLabel3 = new Label("Use mouse to move around the scene. ", "Consolas", 20, white, glm::vec2(400.0f, 200.0f));
	m_pInstructionsContentLabel4 = new Label("Keep shooting em'!", "Consolas", 20, white, glm::vec2(400.0f, 225.0f));
	m_pInstructionsContentLabel5 = new Label("Score 5000 points to move to next level.", "Consolas", 30, white, glm::vec2(400.0f, 450.0f));
	m_pInstructionsContentLabel6 = new Label("Press 'Esc' to exit the game anytime", "Consolas", 30, white, glm::vec2(400.0f, 500.0f));
	m_pHomeButton = new HomeButton();
	m_pHomeButton->setMouseButtonClicked(false);

	m_pHomeButton->setParent(this);
	m_pBackground->setParent(this);
	m_pBackground1->setParent(this);

	addChild(m_pHomeButton);
	addChild(m_pBackground);
	addChild(m_pBackground1);

}

glm::vec2 InstructionsScene::getMousePosition()
{
	return m_mousePosition;
}

