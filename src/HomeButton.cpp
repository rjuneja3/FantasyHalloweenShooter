#include "Player.h"
#include "Game.h"
#include "HomeButton.h"

HomeButton::HomeButton()
// call super constructor
	:Button(
		"../Assets/home.png",
		"HomeButton",
		START_BUTTON, glm::vec2(700.0f, 70.0f)), m_isClicked(false)
{

}

HomeButton::~HomeButton()
{
}

bool HomeButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			std::cout << "Mouse Button Clicked!" << std::endl;
			m_isClicked = true;
			TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}


