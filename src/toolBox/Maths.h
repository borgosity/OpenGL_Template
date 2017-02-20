#pragma once

#include <glm.hpp>
#include <gtx\transform.hpp>

class Maths
{
public:
	Maths();
	~Maths();

	static glm::mat4 createTransormationMatrix(glm::vec3 a_translation, glm::vec3 a_rotation, float a_scale);
};

