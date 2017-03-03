#pragma once
#include <glew.h>
#include <glm.hpp>

class Light
{
public:
	Light();
	Light(glm::vec3 a_position, glm::vec3 a_colour);
	~Light();

	// getters
	glm::vec3 position() { return m_vPosition; };
	glm::vec3 colour() { return m_vColour; };

private:
	glm::vec3 m_vPosition;
	glm::vec3 m_vColour;

};

