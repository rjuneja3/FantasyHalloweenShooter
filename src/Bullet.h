#pragma once

#ifndef __BULLET__
#define __BULLET__

#include <vector>

#include "DisplayObject.h"
#include <SDL_hints.h>
#include "Dragon.h"

enum BulletPosition
{
	TOP,
	MIDDLE,
	BOTTOM
};

class Bullet : public DisplayObject
{
public:
	Bullet();
	~Bullet();

	void draw() override;
	void update() override;
	void clean() override;

	void setActive(bool active);
	bool isActive();

	void fire(glm::vec2 position);
	void fire(glm::vec2 position, BulletPosition bulletPosition);
	//setter
	void setSpeed(float newSpeed);
	//getter
	float getSpeed();
	void checkBounds();
	void setDragon(Dragon* pdragon);
	void reset();

private:

	Uint8 m_alpha;
	bool m_isActive;
	Dragon* m_pDragon;
	float m_speed;
	
	BulletPosition m_bulletPosition;


};




#endif
