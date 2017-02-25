#include "Camera.h"



Camera::Camera()
{
	m_vPosition = glm::vec3(0, 0, 0);
}


Camera::~Camera()
{
}

void Camera::moveForward()
{
	std::cout << "\n MOVE FORWARD" << std::endl;
	m_vPosition.z -= 0.001f;
}

void Camera::moveBack()
{
	std::cout << "\n MOVE BACK" << std::endl;
	m_vPosition.z += 0.001f;
}

void Camera::moveLeft()
{
	std::cout << "\n MOVE LEFT" << std::endl;
	m_vPosition.x -= 0.001f;
}

void Camera::moveRight()
{
	std::cout << "\n MOVE RIGHT" << std::endl;
	m_vPosition.x += 0.001f;
}

void Camera::pitchUpdate(GLfloat a_xOffset)
{
	std::cout << "\n PITCH CHANGE - " << a_xOffset << std::endl;
	m_fPitch += a_xOffset;
}

void Camera::yawUpdate(GLfloat a_yOffset)
{
	std::cout << "\n YAW CHANGE" << a_yOffset << std::endl;
	m_fYaw += a_yOffset;
}

void Camera::rollUpdate(GLfloat a_zOffset)
{
	std::cout << "\n ROLL CHANGE" << a_zOffset << std::endl;
	m_fRoll += a_zOffset;
}


