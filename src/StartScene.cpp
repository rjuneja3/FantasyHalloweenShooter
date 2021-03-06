/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#include "StartScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include "TileComparators.h"
#include <iomanip>

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
{
}

void StartScene::draw()
{
	m_pBackground->draw();
	m_pBackground1->draw();
	m_pStartLabel->draw();
	m_pStartButton->draw();
	m_pInstructionsButton->draw();
	
}

void StartScene::update()
{
	m_pBackground->update();
	m_pBackground1->update();
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();
	m_pInstructionsButton->setMousePosition(m_mousePosition);
	m_pInstructionsButton->ButtonClick();
}

void StartScene::clean()
{
	delete m_pStartLabel;
	
	removeAllChildren();
}

void StartScene::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;

			/*std::cout << "Mouse X: " << m_mousePosition.x << std::endl;
			std::cout << "Mouse Y: " << m_mousePosition.y << std::endl;
			std::cout << "---------------------------------------------" << std::endl;*/
			break;
		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(true);
				m_pInstructionsButton->setMouseButtonClicked(true);

				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
				m_pInstructionsButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			}
			break;

		default:
			break;
		}
	}
}

// this function is used for initialization
void StartScene::start()
{
	SDL_Color white = { 255, 255, 255, 255 };
	m_pStartLabel = new Label("Fantasy Halloween Shooter", "Consolas", 55, white, glm::vec2(400.0f, 100.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);
	m_pStartButton = new StartButton();
	m_pStartButton->setMouseButtonClicked(false);
	m_pInstructionsButton = new InstructionsButton();
	m_pInstructionsButton->setMouseButtonClicked(false);
	m_pBackground = new Background();
	m_pBackground1 = new Background1();

	addChild(m_pBackground);
	addChild(m_pBackground1);

	
}
