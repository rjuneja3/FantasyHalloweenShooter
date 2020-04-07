
#pragma once
#ifndef __INSTRUCTIONS_SCENE__
#define __INSTRUCTIONS_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Background.h"
#include "Background1.h"
#include "HomeButton.h"



class InstructionsScene : public Scene
{
public:
	InstructionsScene();
	~InstructionsScene();

	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
	static const int MAX_COMETS = 4;
	static const int MAX_SMALL_ENEMIES = 3;



	// getters
	glm::vec2 getMousePosition();


private:
	// game objects

	glm::vec2 m_mousePosition;

	int m_mouseRegister;
	
	Background* m_pBackground;
	Background1* m_pBackground1;
	Label* m_pInstructionsTitleLabel;
	
	Label* m_pInstructionsContentLabel1;
	Label* m_pInstructionsContentLabel2;
	Label* m_pInstructionsContentLabel3;
	Label* m_pInstructionsContentLabel4;
	Label* m_pInstructionsContentLabel5;
	Label* m_pInstructionsContentLabel6;
	//******************
	HomeButton * m_pHomeButton;
};

#endif /* defined (__INSTRUCTIONS_SCENE__) */
