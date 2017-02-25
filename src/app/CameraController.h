#pragma once
#include "Controller.h"


class CameraController :
	public Controller
{
public:
	CameraController();
	virtual ~CameraController();

	void update(Camera & camera);

	void keyPress(Camera & a_camera) override;
	void mouseMovement(Camera & a_camera) override;
	void mouseClick(Camera & a_camera) override;
private:
	GLfloat m_fOldXoffset;
	GLfloat m_fOldYoffset;
	GLfloat m_fOldScrollOffset;

};

