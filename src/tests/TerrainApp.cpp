#include "TerrainApp.h"



TerrainApp::TerrainApp()
{
}


TerrainApp::~TerrainApp()
{
	// display
	deallocate(m_display);
	deallocate(m_loader);
	deallocate(m_renderer);
	deallocate(m_camera);
	deallocate(m_cameraController);
	// shaders
	deallocate(m_colourSP);
	deallocate(m_cameraSP);
	deallocate(m_rippleSP);
	// textures
	deallocate(m_groundTexture);
	// models
	deallocate(m_gridModel);
	deallocate(m_cubeModel);
	deallocate(m_groundModel);
	// entities 
	deallocate(m_ground);
}

bool TerrainApp::start()
{
	std::cout << "\n### --> Start TerrainApp" << std::endl;

	// camera
	m_camera = new Camera(glm::vec3(0, -0.5f, 1.5f), CAM_SPEED, FOV, NEAR_PLANE, FAR_PLANE);
	m_cameraController = new CameraController();

	// initialise display
	m_display = new DisplayManager("Example App", SCREEN_W, SCREEN_H);
	m_display->createDisplay();

	// Set the required callback functions for user input
	glfwSetKeyCallback(m_display->window(), Controller::keyCallback);
	glfwSetCursorPosCallback(m_display->window(), Controller::mouseCallback);
	glfwSetScrollCallback(m_display->window(), Controller::scrollCallback);

	// Build and compile our shader program
	// initialise shader program
	m_colourSP = new ShaderProgram(Shader::colourShader);
	m_cameraSP = new ShaderProgram(Shader::cameraShader);
	m_rippleSP = new ShaderProgram(Shader::rippleShader);

	// load model to VAO
	m_loader = new Loader();
	m_renderer = new Renderer();

	// create grid model
	m_gridModel = new RawModel();
	DynamicModels::grid(*m_gridModel, 10, 20);
	
	m_cubeModel = DynamicModels::square(1);

	// create textures
	m_groundTexture = new Texture("res/textures/Sun.png");

	// add textures to cube models
	m_groundModel = new TexturedModel(*m_gridModel, *m_groundTexture, *m_groundTexture, m_colourSP->ID());

	// create planetary entities 
	m_ground = new Entity(m_groundModel, glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), 1.0f);


	return true;
}

bool TerrainApp::update(GLfloat a_deltaTime)
{

	m_cameraController->update(*m_camera, a_deltaTime);
	
	return true;
}

bool TerrainApp::fixedUpdate(GLfloat a_deltaTime)
{
	return true;
}

bool TerrainApp::draw(GLfloat a_deltaTime)
{
	GLdouble time = glfwGetTime();
	// Render
	// Clear the colorbuffer
	m_renderer->prepare(0.0f, 0.3f, 0.2f);

	//==================== ripple grid =============================
	// Activate shader
	m_rippleSP->start();
	// pass uniform data
	m_rippleSP->uniformFloat("time", time * 1.5);
	m_rippleSP->uniformFloat("heightScale", 0.5f);
	// pass camera position to shader 
	m_rippleSP->uniformMat4("view", m_camera->viewMatrix());
	// pass camera projection to shader
	m_rippleSP->uniformMat4("projection", m_camera->projection());

	// ================== ground  ================
	// create transform, with rotation changed over time
	m_ground->transform(Maths::createTransormationMatrix(glm::vec3(-2.5, 0, -2.5), glm::vec3(0, 0, 0), 0.4f));
	m_renderer->renderEntity(m_ground, m_rippleSP);

	// De-activate shader
	m_rippleSP->stop();

	// Swap the screen buffers
	glfwSwapBuffers(m_display->window());

	return true;
}

bool TerrainApp::stop()
{
	// Properly de-allocate all resources once they've outlived their purpose

	m_loader->cleanUp();
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return true;
}

