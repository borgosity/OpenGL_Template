#pragma once
class Controller
{
public:
	Controller();
	~Controller();

	void keyPress();
	void mouseMovement();
	void mouseClick();

private:
	bool m_bKeys[1024];
};

