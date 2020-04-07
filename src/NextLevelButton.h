/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#pragma once
#ifndef __NEXT_LEVEL_BUTTON__
#define __NEXT_LEVEL_BUTTON__

#include "Button.h"

class NextLevelButton : public Button
{
public:
	NextLevelButton();
	~NextLevelButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__Next_LEVEL_BUTTON__) */