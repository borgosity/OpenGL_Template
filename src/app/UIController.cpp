#include "UIController.h"



UIController::UIController()
{
}


UIController::~UIController()
{
}
/// update  Camera Controller
void UIController::update(GLfloat a_dt)
{
	// check for use input
	keyPress(a_dt);

}
/// User Keypress check
void UIController::keyPress(Camera & a_camera, GLfloat a_dt)
{

}

void UIController::mouseMovement(Camera & a_camera)
{
}

void UIController::mouseScroll(Camera & a_camera)
{
}

void UIController::keyPress(GLfloat a_dt)
{
	// check if keys state has changed
	if (m_bKeys[GLFW_KEY_M])
		m_bMapToggle = !m_bMapToggle;
}

