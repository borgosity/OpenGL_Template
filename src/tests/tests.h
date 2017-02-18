#pragma once
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>

// source includes
#include "DisplayManager.h"

// tests
void helloWorld();
void helloTriangle();
void renderEngineTest();	// using all classes
void indexBuffer();
void greenTriangleChange(); // static file 
void gtShaderTest();		// using all classes
void rainbowTri();
void multipleShaders();
void textures();
void texturesTute();

// miscellaneous functions
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void screenColour(GLfloat *red, GLfloat *green, GLfloat *blue, GLboolean *allColour);