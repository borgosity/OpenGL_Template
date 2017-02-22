#include "Maths.h"



Maths::Maths()
{
}


Maths::~Maths()
{
}


glm::mat4 Maths::createWorldRotationMatrix(glm::vec3 a_translation, glm::vec3 a_rotation, float a_scale)
{
	// create an identity matrix
	glm::mat4 matrix(1.0f);
	// rotate matrix arround all axis
	matrix = glm::rotate(matrix, glm::radians(a_rotation.x), glm::vec3(1, 0, 0));
	matrix = glm::rotate(matrix, glm::radians(a_rotation.y), glm::vec3(0, 1, 0));
	matrix = glm::rotate(matrix, glm::radians(a_rotation.z), glm::vec3(0, 0, 1));
	// translate matrix
	matrix = glm::translate(matrix, a_translation);
	// scale matrix uniformly on all axis
	if (a_scale > 0) {
		matrix = glm::scale(matrix, glm::vec3(a_scale, a_scale, a_scale));
	}
	// return transformed matrix
	return matrix;
}

glm::mat4 Maths::createTransormationMatrix(glm::vec3 a_translation, glm::vec3 a_rotation, float a_scale)
{
	// create an identity matrix
	glm::mat4 matrix(1.0f); 
	// translate matrix
	matrix = glm::translate(matrix, a_translation);
	// rotate matrix arround all axis
	matrix = glm::rotate(matrix, glm::radians(a_rotation.x), glm::vec3(1, 0, 0));
	matrix = glm::rotate(matrix, glm::radians(a_rotation.y), glm::vec3(0, 1, 0));
	matrix = glm::rotate(matrix, glm::radians(a_rotation.z), glm::vec3(0, 0, 1));
	// scale matrix uniformly on all axis
	if (a_scale > 0) {
		matrix = glm::scale(matrix, glm::vec3(a_scale, a_scale, a_scale));
	}
	// return transformed matrix
	return matrix;
}

glm::mat4 Maths::quaternionTransformation(glm::vec3 a_translation, glm::quat a_rotation, float a_scale)
{
	// create an identity matrix
	glm::mat4 matrix(1.0f);
	// translate matrix
	matrix = glm::translate(matrix, a_translation);
	// rotate matrix around quaterion
	matrix = matrix * glm::toMat4(a_rotation);

	// scale matrix uniformly on all axis
	if (a_scale > 0) {
		matrix = glm::scale(matrix, glm::vec3(a_scale, a_scale, a_scale));
	}
	// return transformed matrix
	return matrix;
}
