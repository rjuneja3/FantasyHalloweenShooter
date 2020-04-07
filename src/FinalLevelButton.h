/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#pragma once
#ifndef __FINAL_LEVEL_BUTTON__
#define __FINAL_LEVEL_BUTTON__

#include "Button.h"

class FinalLevelButton : public Button
{
public:
	FinalLevelButton();
	~FinalLevelButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__FINAL_LEVEL_BUTTON__) */