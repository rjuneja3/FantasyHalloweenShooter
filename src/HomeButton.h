/**
** ASSIGNMENT 2 - Web Game Programming
** Author: Rohan Juneja
** Student ID: 300987725
** Last modified by Rohan Juneja
** Last modified: April 6th 2020
** Revision History: 1
*/

#pragma once
#ifndef __HOME_BUTTON__
#define __HOME_BUTTON__

#include "Button.h"

class HomeButton : public Button
{
public:
	HomeButton();
	~HomeButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__HOME_BUTTON__) */