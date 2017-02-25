#include "Controller.h"

// key state
GLboolean	Controller::m_bKeys[1024];
bool		Controller::m_bClose = false;
// mouse movement
bool		Controller::m_bDoubleClick = false;
GLfloat		Controller::m_fOldXpos = 0;
GLfloat		Controller::m_fOldYpos = 0;
GLfloat		Controller::m_fXoffset = 0;
GLfloat		Controller::m_fYoffset = 0;
// scroll offsets
GLfloat		Controller::m_fScrollXoffset = 0;
GLfloat		Controller::m_fScrollYoffset = 0;
// debug
bool		Controller::m_bWireFrame = false;

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::keyCallback(GLFWwindow * a_window, int a_key, int a_scanCode, int a_action, int a_mode)
{
	// close the application
	if (a_key == GLFW_KEY_ESCAPE && a_action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(a_window, GL_TRUE);
		m_bClose = true;
	}
	// update key states
	if (a_action == GLFW_PRESS) {
		m_bKeys[a_key] = true;
	}
	else if (a_action == GLFW_RELEASE) {
		m_bKeys[a_key] = false;
	}
	if (a_key == GLFW_KEY_L && a_action == GLFW_PRESS)
	{
		// toggle wireFrame bool
		m_bWireFrame = !m_bWireFrame;
		// toggle wire frame based on bool state
		m_bWireFrame ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void Controller::mouseCallback(GLFWwindow* a_window, double a_xPos, double a_yPos)
{
	// record position of first click
	if (!m_bDoubleClick)
	{
		m_fOldXpos = a_xPos;
		m_fOldYpos = a_yPos;
		m_bDoubleClick = true;
	}
	// set offsets
	m_fXoffset = a_xPos - m_fOldXpos;
	m_fYoffset = m_fOldYpos - a_yPos;  // Reversed since y-coordinates go from bottom to left
	// set old position
	m_fOldXpos = a_xPos;
	m_fOldYpos = a_yPos;
}


void Controller::scrollCallback(GLFWwindow* a_window, double a_xOffset, double a_yOffset)
{
	m_fScrollXoffset = a_xOffset;
	m_fScrollYoffset = a_yOffset;
}
