#include "Camera.h"



Camera::Camera()
{
	m_vPosition = glm::vec3(0, 0.5f, -2.0f);
	m_fPitch = 0.0f;
	m_fYaw = -10.0f; //set some initial offset to avoid camera pointing to the right
	m_fRoll = 0.0f;
	m_fSpeed = 5.0f;
	m_vFront = glm::vec3(0.0f, 0.0f, -1.0f);
	m_vUp = glm::vec3(0.0f, 0.0f, 0.0f);
}

Camera::Camera(glm::vec3 a_cameraPostion, GLfloat a_speed)
{
	m_vPosition = a_cameraPostion;
	m_fPitch = 0.0f;
	m_fYaw = -90.0f; //set some initial offset to avoid camera pointing to the right
	m_fRoll = 0.0f;
	m_fSpeed = a_speed;
	m_vFront = glm::vec3(0.0f, 0.0f, -1.0f);
	m_vUp = glm::vec3(0.0f, 0.1f, 0.0f);
}

Camera::~Camera()
{
}
// update camera
void Camera::update(GLfloat a_dt)
{
	// update camera view matrix
	m_mViewMatrix = glm::lookAt(m_vPosition, m_vPosition + m_vFront, m_vUp);
}
/// move camera into the scene
void Camera::moveForward(GLfloat a_dt)
{
	m_vPosition += (m_fSpeed * a_dt) * m_vFront;
}
/// move camera out of the scene
void Camera::moveBack(GLfloat a_dt)
{
	m_vPosition -= (m_fSpeed * a_dt) * m_vFront;
}
/// move camera to the left of the scene
void Camera::moveLeft(GLfloat a_dt)
{
	m_vPosition += glm::normalize(glm::cross(m_vFront, m_vUp)) * (m_fSpeed * a_dt);
}
/// move camera to the right of the scene
void Camera::moveRight(GLfloat a_dt)
{
	m_vPosition -= glm::normalize(glm::cross(m_vFront, m_vUp)) * (m_fSpeed * a_dt);
}
/// update the cameras pitch
void Camera::pitchUpdate(GLfloat a_xOffset)
{
	// increase pitch by offset
	m_fPitch += a_xOffset;
	// constrain up/down mouse movement
	if (m_fPitch > 89) m_fPitch = 89;
	if (m_fPitch < -89) m_fPitch = -89;
	// update cameras front
	updateFront();
}
/// update the cameras yaw
void Camera::yawUpdate(GLfloat a_yOffset)
{
	// increase yaw by offset
	m_fYaw += a_yOffset;
	// update cameras front
	updateFront();
}

/// 
/// Camera Front function calculates the direction the camera should face
///
void Camera::updateFront()
{
	glm::vec3 front;
	front.x = glm::cos(glm::radians(m_fYaw)) * glm::cos(glm::radians(m_fPitch));
	front.y = glm::sin(glm::radians(m_fPitch));
	front.z = glm::sin(glm::radians(m_fYaw)) * glm::cos(glm::radians(m_fPitch));
	m_vFront = glm::normalize(front);
}


