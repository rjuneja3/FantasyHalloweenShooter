/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#pragma once
#ifndef __GAME_OBJECT_TYPE__
#define __GAME_OBJECT_TYPE__
enum GameObjectType {
	NONE = -1,
	PLAYER,
	BULLET,
	ENEMY,
	SHIP,
	COMET,	
	START_BUTTON,
	NEXT_LEVEL_BUTTON,
	INSTRUCTIONS_BUTTON,
	BACK_GROUND,
	POWER_UP,
	DRAGON,
	NUM_OF_TYPES
};

#endif /* defined (__GAME_OBJECT_TYPE__)*/