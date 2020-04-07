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