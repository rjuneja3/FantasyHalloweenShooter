/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#pragma once
#ifndef __ENEMY__
#define __ENEMY__
#include "DisplayObject.h"
#include <SDL_hints.h>


class Enemy : public DisplayObject
{
public:
	Enemy(std::string imagePath = "../Assets/textures/StartButton.png",
		std::string enemyName = "enemy",
		GameObjectType type = ENEMY,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool isCentered = true);
	~Enemy() override;
	
	void draw() override;
	void update() override;
	void clean() override;

	void draw(int yEnemyPosition);
	void setActive(bool active);
	void setAlpha(Uint8 value);
	bool isActive();
	void setMovingUp(bool goingUp);
	
	
	bool getMovingUp();

	virtual void decreaseHealth() = 0;
	
	
private:
	std::string m_name;
	bool m_isCentered;
	bool m_isActive;
	Uint8 m_alpha;
	bool m_movingUp;
};


#endif
