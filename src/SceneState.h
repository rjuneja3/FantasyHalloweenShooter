
/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#pragma once
#ifndef __SCENE_STATE__
#define __SCENE_STATE__
enum SceneState
{
	NO_SCENE = -1,
	START_SCENE,
	LEVEL1_SCENE,
	PLAY_SCENE,
	END_SCENE,
	NEXT_LEVEL_SCENE,
	INSTRUCTIONS_SCENE,
	FINAL_LEVEL,
	TO_FINAL_LEVEL_SCENE,
	NUM_OF_SCENES
};
#endif /* defined (__SCENE_STATE__) */