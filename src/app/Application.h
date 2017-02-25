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
#include "CameraController.h"
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

	bool run();
	virtual bool start();
	virtual bool update(GLfloat a_deltaTime);
	virtual bool fixedUpdate(GLfloat a_deltaTime);
	virtual bool draw(GLfloat a_deltaTime);
	virtual bool stop();

protected:
	void deltaTime();

private:
	// time
	GLfloat m_fDeltaTime;
	GLfloat m_fCurrentTime;
	GLfloat m_fPrevTime;

};
