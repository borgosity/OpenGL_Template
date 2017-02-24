#pragma once
#include "Controller.h"
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>

// source includes
// display
#include "DisplayManager.h"
#include "Loader.h"
#include "Renderer.h"
#include "Camera.h"
// utility
#include "Maths.h"
// shaders
#include "ShaderProgram.h"
#include "Shaders.h"
// textures
#include "ModelTexture.h"
#include "TexturedModel.h"
#include "Texture.h"
// models
#include "Entity.h"
#include "DynamicModels.h"

class Application
{
public:
	Application();
	~Application();

	bool start();
	bool run();
	bool update();
	bool fixedUpdate();
	bool draw();
	bool stop();

private:
	
	Controller * m_controller;
	bool m_bWireframe;
	// display
	DisplayManager * m_display;
	Loader * m_loader;
	Renderer * m_renderer;
	Camera * m_camera;
	// textures
	ShaderProgram * m_shaderProgram;
	Texture * m_sunTexture;
	Texture * m_planetTexture;
	Texture * m_moonTexture;
	// models
	RawModel * m_rawModel;
	TexturedModel * m_sunModel;
	TexturedModel * m_planetModel;
	TexturedModel * m_moonModel;
	// planetary entities 
	Entity * m_sun;
	Entity * m_planet;
	Entity * m_moon;

	//private functions

};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
