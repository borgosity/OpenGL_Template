#pragma once
// std includes
#include <iostream>

// opengl includes
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

// source includes
#include "ConstValues.h"

class Mirror
{
public:
	Mirror();
	~Mirror();

	void update();

private:
	GLuint m_FBO; // frame buffer
	GLuint m_TBO; // texture buffer
	GLuint m_RBO; // render buffer

	void setupFBO();
	GLuint generateTexture(GLboolean a_depth, GLboolean a_stencil);
};

