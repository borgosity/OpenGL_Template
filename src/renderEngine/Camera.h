#pragma once
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <iostream>


class Camera
{
public:
	Camera();
	Camera(glm::vec3 a_cameraPostion, GLfloat a_speed);
	~Camera();

	void update(GLfloat a_dt);

	// camera movement
	void moveForward(GLfloat a_dt);
	void moveBack(GLfloat a_dt);
	void moveLeft(GLfloat a_dt);
	void moveRight(GLfloat a_dt);
	// camera angles
	void pitchUpdate(GLfloat a_xOffset);
	void yawUpdate(GLfloat a_yOffset);

	// set camera fowrard direction
	void updateFront();

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
	glm::vec3	m_vFront;
	glm::vec3	m_vPosition;
	glm::vec3	m_vUp;
	GLfloat		m_fSpeed;
	GLfloat		m_fPitch;
	GLfloat		m_fYaw;
	GLfloat		m_fRoll;
};

