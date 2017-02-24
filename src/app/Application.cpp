#include "Application.h"



Application::Application()
{
}


Application::~Application()
{
}

bool Application::start()
{
	std::cout << "\n### --> Start Application" << std::endl;

	// initialise display
	m_display = new DisplayManager();
	m_display->createDisplay();

	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);

	// Build and compile our shader program
	// initialise shader program
	m_shaderProgram = new ShaderProgram(Shader::cameraShader);

	// load model to VAO
	m_loader = new Loader();
	m_renderer = new Renderer(m_shaderProgram);

	// create cube model
	m_rawModel = DynamicModels::cube();

	// create textures
	m_sunTexture = new Texture("res/textures/Sun.png");
	m_planetTexture = new Texture("res/textures/M-Class.png");
	m_moonTexture = new Texture("res/textures/Moon.png");

	// add textures to cube models
	m_sunModel = new TexturedModel(*m_rawModel, *m_sunTexture, *m_sunTexture, m_shaderProgram->ID());
	m_planetModel = new TexturedModel(*m_rawModel, *m_planetTexture, *m_planetTexture, m_shaderProgram->ID());
	m_moonModel = new TexturedModel(*m_rawModel, *m_moonTexture, *m_moonTexture, m_shaderProgram->ID());

	// create planetary entities 
	m_sun = new Entity(m_sunModel, glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), 1.0f);
	m_planet = new Entity(m_planetModel, glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), 1.0f);
	m_moon = new Entity(m_moonModel, glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), 1.0f);

	// camera projection matrix ## NOW HANDLED IN THE RENDERER

	// camera position
	m_cameraPosition = glm::translate(m_cameraPosition, glm::vec3(0.0f, 0.5f, -2.0f));

	return true;
}

bool Application::run()
{
	// initialise everything
	start();

	// application loop
	while (!glfwWindowShouldClose(m_display->window()))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// application updates
		update();
		fixedUpdate();

		// draw application
		draw();

		// check for key presses
		//glfwSetKeyCallback(m_display->window(), key_callback);
	}
	return true;
}

bool Application::update()
{
	return true;
}

bool Application::fixedUpdate()
{
	return true;
}

bool Application::draw()
{
	GLdouble time = glfwGetTime();
	// Render
	// Clear the colorbuffer
	m_renderer->prepare(0.0f, 0.0f, 0.0f);

	// Activate shader
	m_shaderProgram->start();

	// pass camera position to shader 
	m_shaderProgram->uniformMat4("view", m_cameraPosition);

	// ## NOW HANDLED IN THE RENDERER
	// pass camera projection to shader
	/*shaderProgram->uniformMat4("projection", cameraProjection);*/

	// ================== sun  ================
	// create transform, with rotation changed over time
	m_sun->transform(Maths::createTransormationMatrix(glm::vec3(0, 0, 0), glm::vec3(0, time * -15.0f, 0), 0.3f));
	m_renderer->renderEntity(m_sun, m_shaderProgram);

	// ================== planet  ================
	// set transform with local and world rotation changed over time
	m_planet->transform(Maths::createWorldRotationMatrix(glm::vec3(0, 0, 0), glm::vec3(0, time * -25.0f, 0), 0) *
		Maths::createTransormationMatrix(glm::vec3(0.45f, 0, -0.45f), glm::vec3(0, time * -25.0f, 0), 0.2f));
	m_renderer->renderEntity(m_planet, m_shaderProgram);

	// ================== moon  ================
	// multiple planets transformation by world rotation changed over time 
	// - scale and translate value need to be increased above the norm to achieve similar sizing and distance
	m_moon->transform(m_planet->transform() * Maths::createWorldRotationMatrix(glm::vec3(0.8f, 0, -0.8f), glm::vec3(0, time * -75.0f, 0), 0.5f));
	m_renderer->renderEntity(m_moon, m_shaderProgram);

	// Swap the screen buffers
	glfwSwapBuffers(m_display->window());
	
	return true;
}

bool Application::stop()
{
	// Properly de-allocate all resources once they've outlived their purpose

	m_loader->cleanUp();
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return true;
}

