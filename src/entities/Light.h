#pragma once
#include <glew.h>
#include <glm.hpp>

class Light
{
public:
	Light();
	Light(glm::vec3 a_position, glm::vec3 a_colour);
	Light(glm::vec3 a_position, glm::vec3 a_colour, glm::vec3 a_direction, 
		  glm::vec3 a_ambient, glm::vec3 a_diffuse, glm::vec3 a_specular);
	~Light();

	// getters
	glm::vec3 position()	{ return m_vPosition; };
	glm::vec3 colour()		{ return m_vColour; };
	glm::vec3 direction()	{ return m_vDirection; };
	glm::vec3 ambient()		{ return m_vAmbient; };
	glm::vec3 diffuse()		{ return m_vDiffuse; };
	glm::vec3 specular()	{ return m_vSpecular; };

private:
	glm::vec3 m_vPosition;
	glm::vec3 m_vColour;
	glm::vec3 m_vDirection;
	glm::vec3 m_vAmbient;
	glm::vec3 m_vDiffuse;
	glm::vec3 m_vSpecular;
};

