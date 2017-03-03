#include "Light.h"



Light::Light()
{
	m_vPosition = glm::vec3(0, 1, 0);
	m_vColour = glm::vec3(1, 1, 1);
}

Light::Light(glm::vec3 a_position, glm::vec3 a_colour)
{
	m_vPosition = a_position;
	m_vColour = a_colour;
}


Light::~Light()
{
}
