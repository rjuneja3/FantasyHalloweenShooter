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