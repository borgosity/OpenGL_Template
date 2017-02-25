#pragma once
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <iostream>

class Camera
{
public:
	Camera();
	~Camera();

	// camera movement
	void moveForward();
	void moveBack();
	void moveLeft();
	void moveRight();
	// camera angles
	void pitchUpdate(GLfloat a_xOffset);
	void yawUpdate(GLfloat a_yOffset);
	void rollUpdate(GLfloat a_zOffset);
	// getters
	glm::mat4	viewMatrix() { return m_mViewMatrix; };
	glm::mat4	viewMatrix(glm::mat4 a_viewMatrix) { return m_mViewMatrix; };
	glm::vec3	position() { return m_vPosition; };
	GLfloat		pitch() { return m_fPitch; };
	GLfloat		yaw() { return m_fYaw; };
	GLfloat		roll() { return m_fRoll; };

private:
	glm::mat4	m_mTransform;
	glm::mat4	m_mViewMatrix;
	glm::vec3	m_vPosition;
	GLfloat		m_fPitch;
	GLfloat		m_fYaw;
	GLfloat		m_fRoll;
};

