#include "Maths.h"
#include <iostream>


Maths::Maths()
{
}


Maths::~Maths()
{
}


glm::mat4 Maths::createWorldTransformMatrix(glm::vec3 a_translation, glm::vec3 a_rotation, float a_scale)
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

//glm::mat4 Maths::createViewMatrix(Camera & a_camera)
//{
//	// create an identity matrix
//	glm::mat4 viewMatrix(1.0f);
//	// rotate
//	viewMatrix = glm::rotate(viewMatrix, glm::radians(a_camera.pitch()), glm::vec3(1, 0, 0));
//	viewMatrix = glm::rotate(viewMatrix, glm::radians(a_camera.yaw()), glm::vec3(0, 1, 0));
//	// translate
//	viewMatrix = glm::translate(viewMatrix, -a_camera.position());
//	// return new viewMatrix
//	return viewMatrix;
//}

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

float Maths::minElement(float * a_array, int a_size)
{
	float result = 0.0f;
		for (int i = 0; i < a_size; i++)
		{
			if (a_array[i] <= result){
				result = a_array[i];
			}
		}
	return result;
}

float Maths::maxElement(float * a_array, int a_size)
{
	float result = 0.0f;
	for (int i = 0; i < a_size; i++)
	{
		if (a_array[i] >= result) {
			result = a_array[i];
		}
	}
	return result;
}
