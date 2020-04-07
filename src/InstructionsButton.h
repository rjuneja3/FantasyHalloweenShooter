/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#pragma once
#ifndef __INSTRU_BUTTON__
#define __INSTRU_BUTTON__

#include "Button.h"

class InstructionsButton : public Button
{
public:
	InstructionsButton();
	~InstructionsButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__INSTRUCTIONS_BUTTON__) */