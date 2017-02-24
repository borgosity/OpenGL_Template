#pragma once
#include <glew.h>
//#include <glfw3.h>
#include <glm.hpp>

#include "Loader.h"

struct Vertex3 
{
	glm::vec3 position;
	glm::vec3 colour;
	glm::vec2 texture; // texture co-ordinates
};
struct Vertex4
{
	glm::vec4 position;
	glm::vec4 colour;
	glm::vec2 texture; // texture co-ordinates
};

class DynamicModels
{
public:
	DynamicModels();
	~DynamicModels();

	static RawModel * grid(unsigned int a_rows, unsigned int a_columns);
	static RawModel * cube();

private:

};

