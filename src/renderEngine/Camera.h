#pragma once
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>

enum MoveDirection {
	UP, DOWN, LEFT, RIGHT
};

class Camera
{
public:
	Camera();
	~Camera();

	void move();

	glm::vec3 position() { return m_vPosition; };
	GLfloat pitch() { return m_fPitch; };
	GLfloat yaw() { return m_fYaw; };
	GLfloat roll() { return m_fRoll; };

private:
	glm::vec3 m_vPosition;
	GLfloat m_fPitch;
	GLfloat m_fYaw;
	GLfloat m_fRoll;
};

