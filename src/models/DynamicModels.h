#pragma once
#include <glew.h>
//#include <glfw3.h>
#include <glm.hpp>

#include "Loader.h"


class DynamicModels
{
public:
	DynamicModels();
	~DynamicModels();

	static void grid(RawModel & a_rawmodel, unsigned int a_rows, unsigned int a_columns);
	static RawModel * cube();
	static RawModel * square(GLfloat a_size);

private:
	static Loader * m_loader;
	//static Vertex * m_vertices;
	//static unsigned int * m_indices;
};

