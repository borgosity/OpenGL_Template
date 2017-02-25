#include "CameraController.h"



CameraController::CameraController()
{
	m_fOldXoffset = 0;
	m_fOldYoffset = 0;
	m_fOldScrollOffset = 0;
}


CameraController::~CameraController()
{
}

void CameraController::update(Camera & a_camera)
{
	keyPress(a_camera);
	mouseMovement(a_camera);
	mouseClick(a_camera);
}

void CameraController::keyPress(Camera & a_camera)
{
	if (m_bKeys[GLFW_KEY_W])
		a_camera.moveForward();
	if (m_bKeys[GLFW_KEY_S])
		a_camera.moveBack();
	if (m_bKeys[GLFW_KEY_A])
		a_camera.moveLeft();
	if (m_bKeys[GLFW_KEY_D])
		a_camera.moveRight();
}

void CameraController::mouseMovement(Camera & a_camera)
{
	if (m_fOldXoffset != m_fXoffset) {
		a_camera.pitchUpdate(m_fXoffset);
		m_fOldXoffset = m_fXoffset;
	}
	if (m_fOldYoffset != m_fYoffset) {
		a_camera.yawUpdate(m_fYoffset);
		m_fOldYoffset = m_fYoffset;
	}
}

void CameraController::mouseClick(Camera & a_camera)
{
}
