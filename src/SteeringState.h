/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/
#pragma once
#ifndef __STEERING_STATE__
#define __STEERING_STATE__

enum SteeringState {
	NO_STATE = -1,
	IDLE,
	SEEK,
	ARRIVE,
	AVOID,
	FLEE,
	NUM_OF_STATES
};

#endif /* defined (__STEERING_STATE__)*/