#pragma once

#include <iostream>
// opengl includes
#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>

class DisplayManager
{
public:
	DisplayManager();
	~DisplayManager();

	void createDisplay();
	void updateDisplay();
	void closeDisplay();
	GLFWwindow * window() { return m_window; };

private:
	// Window dimensions
	const GLuint WIDTH = 800, HEIGHT = 600, FPS_CAP = 120;
	GLFWwindow * m_window;
};

