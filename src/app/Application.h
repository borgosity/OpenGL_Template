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
	virtual bool init();
	virtual bool start();
	virtual bool update(GLfloat a_deltaTime);
	virtual bool fixedUpdate(GLfloat a_deltaTime);
	virtual bool draw(GLfloat a_deltaTime);
	virtual bool stop();

protected:
	void deltaTime();

	template<typename T>
	void deallocate(T a_ptr);

private:
	// time
	GLdouble m_fDeltaTime;
	GLdouble m_fCurrentTime;
	GLdouble m_fPrevTime;

};

template<typename T>
inline void Application::deallocate(T a_ptr)
{
		delete a_ptr;
		a_ptr = nullptr;
}
