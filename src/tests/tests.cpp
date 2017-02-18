#include "tests.h"
#include "Loader.h"
#include "Renderer.h"
#include "Shaderer.h"
// shaders
#include "StaticShader.h"
#include "UniformShader.h"
#include "IndexShader.h"
#include "TextureShader.h"
// textures
#include "ModelTexture.h"
#include "TexturedModel.h"



bool wireFrame = false;

void helloWorld()
{
	std::cout << "Starting OpenGL Test - 01" << std::endl;

	// create display
	DisplayManager * display = new DisplayManager();
	display->createDisplay();

	GLfloat green = 0.0f;
	GLfloat red = 0.0f;
	GLfloat blue = 0.0f;
	GLboolean maxColour = false;

	// time
	GLdouble prevTime = glfwGetTime();
	GLdouble currTime = 0;
	float deltaTime = 0;

	// draw loop
	while (currTime = glfwGetTime(), !glfwWindowShouldClose(display->window()))
	{
		// update delta time
		deltaTime = (float)(currTime - prevTime);
		//std::cout << "delta time = " << deltaTime << " modula time = " << (int)currTime % 3 << std::endl;

		// check and call events
		glfwPollEvents();

		// rendering commands
		screenColour(&red, &green, &blue, &maxColour);
		glClearColor(red, green, blue, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// swap the buffers
		glfwSwapBuffers(display->window());
		glfwSetKeyCallback(display->window(), key_callback);

		// update current time
		prevTime = currTime;
	}
	// Terminate GLFW
	glfwTerminate();
	std::cout << "Finished!!  - 01 \n\n" << std::endl;
}

void helloTriangle()
{
	//// Init GLFW
	//glfwInit();
	//// Set all the required options for GLFW
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//// Create a GLFWwindow object that we can use for GLFW's functions
	//GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	//glfwMakeContextCurrent(window);

	//// Set the required callback functions
	//glfwSetKeyCallback(window, key_callback);

	//// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	//glewExperimental = GL_TRUE;
	//// Initialize GLEW to setup the OpenGL Function pointers
	//glewInit();

	//// Define the viewport dimensions
	//int width, height;
	//glfwGetFramebufferSize(window, &width, &height);
	//glViewport(0, 0, width, height);

	// create display
	DisplayManager * display = new DisplayManager();
	display->createDisplay();

	// Build and compile our shader program
	Shaderer * shader = new Shaderer();
	GLuint shaderProgram = shader->buildShader();


	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f, // Left  
		0.5f, -0.5f, 0.0f, // Right 
		0.0f,  0.5f, 0.0f  // Top   
	};
	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	// Game loop
	while (!glfwWindowShouldClose(display->window()))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw our first triangle
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(display->window());
		// Check for key strokes
		glfwSetKeyCallback(display->window(), key_callback);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
}

void renderEngineTest()
{
	std::cout << "Starting OpenGL Test - 02" << std::endl;

	// initialise display
	DisplayManager * display = new DisplayManager();
	display->createDisplay();
	
	// initialise shader program
	StaticShader * staticShader = new StaticShader(0);

	// initialise loader and renderer
	Loader * loader = new Loader();
	Renderer * renderer = new Renderer();
	

	// initialise vertices for triangle
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions        
		0.5f, -0.5f, 0.0f,   // Bottom Right
		-0.5f, -0.5f, 0.0f,  // Bottom Left
		0.0f,  0.5f, 0.0f    // Top   
	};

	// load model to VAO
	RawModel * model = loader->loadToVAO(vertices, sizeof(vertices));

	// draw loop
	while (!glfwWindowShouldClose(display->window()))
	{
		// check and call events
		glfwPollEvents();

		// game logic

		// render
		renderer->prepare(0.0f, 0.3f, 0.3f);

		// starty using shader
		staticShader->start();
		
		// Draw triangle
		renderer->render(model);

		// stop using shader
		staticShader->stop();

		// update display
		display->updateDisplay();
		
		// check key presses
		glfwSetKeyCallback(display->window(), key_callback);

	}
	//clean up
	staticShader->cleanUp();
	loader->cleanUp();
	// Terminate GLFW
	glfwTerminate();
	std::cout << "Finished!!  - 02 \n\n" << std::endl;
}

void indexBuffer()
{
	// initialise display
	DisplayManager * display = new DisplayManager();
	display->createDisplay();

	// initialise shader program
	StaticShader * staticShader = new StaticShader(0);

	// initialise loader and renderer
	Loader * loader = new Loader();
	Renderer * renderer = new Renderer();


	// initialise vertices for triangle
	// Set up vertex data (and buffer(s)) and attribute pointers
	//GLfloat vertices[] = {
	//	// First triangle
	//	0.5f,  0.5f, 0.0f,  // Top Right
	//	0.5f, -0.5f, 0.0f,  // Bottom Right
	//	-0.5f,  0.5f, 0.0f,  // Top Left 
	//	// Second triangle
	//	0.5f, -0.5f, 0.0f,  // Bottom Right
	//	-0.5f, -0.5f, 0.0f,  // Bottom Left
	//	-0.5f,  0.5f, 0.0f   // Top Left
	//};
	GLfloat vertices[] = {
		0.5f,  0.5f, 0.0f,  // Top Right
		0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  // Bottom Left
		-0.5f,  0.5f, 0.0f   // Top Left 
	};
	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3,   // First Triangle
		1, 2, 3    // Second Triangle
	};

	// load model to VAO
	RawModel * model = loader->loadToVAO(vertices, sizeof(vertices), indices, sizeof(indices));

	// draw loop
	while (!glfwWindowShouldClose(display->window()))
	{
		// check and call events
		glfwPollEvents();

		// game logic

		// render
		renderer->prepare(0.0f, 0.3f, 0.3f);

		// starty using shader
		staticShader->start();

		// Draw triangle
		renderer->renderInd(model);

		// stop using shader
		staticShader->stop();

		// update display
		display->updateDisplay();

		// check key presses
		glfwSetKeyCallback(display->window(), key_callback);

	}
	//clean up
	staticShader->cleanUp();
	loader->cleanUp();
	// Terminate GLFW
	glfwTerminate();
}

void greenTriangleChange()
{
	const GLchar* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"layout (location = 1) in vec3 color;\n"
		"out vec3 ourColor;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position, 1.0);\n"
		"ourColor = color;\n"
		"}\0";
	const GLchar* fragmentShaderSource = "#version 330 core\n"
		"out vec4 color;\n"
		"uniform vec4 ourColor;\n"
		"void main()\n"
		"{\n"
		"color = ourColor;\n"
		"}\n\0";

	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, 800, 600);


	// Build and compile our shader program
	// Vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// Check for compile time errors
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// Fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// Check for compile time errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// Link shaders
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// Check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions        
		0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  // Bottom Left
		0.0f,  0.5f, 0.0f   // Top 
	};
	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0); // Unbind VAO


						  // Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Be sure to activate the shader
		glUseProgram(shaderProgram);

		// Update the uniform color
		GLfloat timeValue = glfwGetTime();
		GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
		GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
		glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

		// Draw the triangle
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
}

void gtShaderTest()
{
	// create display
	DisplayManager * display = new DisplayManager();
	display->createDisplay();


	// Build and compile our shader program
	UniformShader * shader = new UniformShader();

	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions        
		0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  // Bottom Left
		0.0f,  0.5f, 0.0f   // Top 
	};
	// create VAO
	Loader * loader = new Loader();
	// load model to VAO
	RawModel * model = loader->loadToVAO(vertices, sizeof(vertices));
	Renderer * renderer = new Renderer();


						  // Game loop
	while (!glfwWindowShouldClose(display->window()))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		renderer->prepare(0.2f, 0.3f, 0.3f);

		// Be sure to activate the shader
		shader->start();
		// Update the uniform color
		GLfloat timeValue = glfwGetTime();
		GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
		shader->uniform4f("ourColor", glm::vec4(0.0f, greenValue, 0.0f, 1.0f));
		// Draw the triangle
		renderer->render(model);
		// stop using shader
		shader->stop();
		// Swap the screen buffers
		display->updateDisplay();
		// check key presses
		glfwSetKeyCallback(display->window(), key_callback);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	loader->cleanUp();
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
}

void rainbowTri()
{
	std::cout << "Starting Rainbow Triangle Test" << std::endl;

	// initialise display
	DisplayManager * display = new DisplayManager();
	display->createDisplay();
	// initialise shader program
	IndexShader * indexShader = new IndexShader();

	// initialise loader and renderer
	Loader * loader = new Loader();
	Renderer * renderer = new Renderer();


	// initialise vertices for triangle
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions         // Colors
		0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // Bottom Left
		0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // Top   
	};

	// load model to VAO
	RawModel * model = loader->loadToVAO(vertices, sizeof(vertices), 2);

	// draw loop
	while (!glfwWindowShouldClose(display->window()))
	{
		// check and call events
		glfwPollEvents();

		// game logic

		// render
		renderer->prepare(0.0f, 0.3f, 0.3f);

		// starty using shader
		indexShader->start();

		// Draw triangle
		renderer->render(model);

		// stop using shader
		indexShader->stop();

		// update display
		display->updateDisplay();

		// check key presses
		glfwSetKeyCallback(display->window(), key_callback);

	}
	//clean up
	indexShader->cleanUp();
	loader->cleanUp();
	// Terminate GLFW
	glfwTerminate();
	std::cout << "Finished!! \n\n" << std::endl;
}

void multipleShaders()
{
	std::cout << "Starting Rainbow Triangle Test" << std::endl;

	// initialise display
	DisplayManager * display = new DisplayManager();
	display->createDisplay();

	// initialise loader and renderer
	Loader * loader = new Loader();
	Renderer * renderer = new Renderer();

	// initialise shader program
	UniformShader * uniformShader = new UniformShader();
	IndexShader * indexShader = new IndexShader();

	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat verticesA[] = {
		// Positions        
		0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  // Bottom Left
		0.0f,  0.5f, 0.0f   // Top 
	};

	// initialise vertices for triangle
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat verticesB[] = {
		// Positions         // Colors
		0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // Bottom Left
		0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // Top   
	};

	// load model to VAO
	RawModel * modelA = loader->loadToVAO(verticesA, sizeof(verticesA));
	RawModel * modelB = loader->loadToVAO(verticesB, sizeof(verticesB), 2);
	// draw loop
	while (!glfwWindowShouldClose(display->window()))
	{
		// check and call events
		glfwPollEvents();

		// game logic

		// render
		renderer->prepare(0.0f, 0.3f, 0.3f);

		// starty using shader
		uniformShader->start();
		GLfloat timeValue = glfwGetTime();
		GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
		uniformShader->uniform4f("ourColor", glm::vec4(0.0f, greenValue, 0.0f, 1.0f));
		// Draw triangle
		renderer->render(modelA);
		// stop using shader
		uniformShader->stop();

		// starty using shader
		indexShader->start();
		// Draw triangle
		renderer->render(modelB);
		// stop using shader
		indexShader->stop();

		// update display
		display->updateDisplay();

		// check key presses
		glfwSetKeyCallback(display->window(), key_callback);

	}
	//clean up
	indexShader->cleanUp();
	loader->cleanUp();
	// Terminate GLFW
	glfwTerminate();
	std::cout << "Finished!!  - 02 \n\n" << std::endl;
}

void textures()
{
	// initialise display
	DisplayManager * display = new DisplayManager();
	display->createDisplay();

	// initialise shader program
	TextureShader * textureShader = new TextureShader();

	// initialise loader and renderer
	Loader * loader = new Loader();
	Renderer * renderer = new Renderer();


	// initialise vertices for triangle
	GLfloat vertices[] = {
		// Positions          // Colors           // Texture Coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // Top Right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // Bottom Right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // Bottom Left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // Top Left  
	};
	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};

	// load model to VAO
	RawModel * model = loader->loadTextureVAO(vertices, sizeof(vertices), indices, sizeof(indices));
	ModelTexture * texture = new ModelTexture(loader->loadTexture("res/textures/container.jpg", 512, 512));
	TexturedModel * texturedModel = new TexturedModel(*model, *texture);


	// draw loop
	while (!glfwWindowShouldClose(display->window()))
	{
		// check and call events
		glfwPollEvents();

		// game logic

		// render
		renderer->prepare(0.0f, 0.3f, 0.3f);

		// starty using shader
		textureShader->start();

/***********************************************************************************

OpenGL 3D Game Tutorial 6: Texturing
7m:20s

************************************************************************************/
		// Draw triangle
		renderer->renderTexture(texturedModel);

		// stop using shader
		textureShader->stop();

		// update display
		display->updateDisplay();

		// check key presses
		glfwSetKeyCallback(display->window(), key_callback);

	}
	//clean up
	textureShader->cleanUp();
	loader->cleanUp();
	// Terminate GLFW
	glfwTerminate();

}

void texturesTute()
{
	// initialise display
	DisplayManager * display = new DisplayManager();
	display->createDisplay();

	// initialise shader program
	TextureShader * textureShader = new TextureShader();


	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions          // Colors           // Texture Coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left 
	};
	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO


	// Load and create a texture 
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
										   // Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load image, create texture and generate mipmaps
	int width, height;
	unsigned char* image = SOIL_load_image("res/textures/container.jpg", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.


									 // Game loop
	while (!glfwWindowShouldClose(display->window()))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Bind Texture
		glBindTexture(GL_TEXTURE_2D, texture);

		// Activate shader
		textureShader->start();

		// Draw container
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		textureShader->stop();

		// Swap the screen buffers
		glfwSwapBuffers(display->window());
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
}

/// key press callback function
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// When a user presses the escape key, we set the WindowShouldClose property to true, 
	// closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
		std::cout << "Escape Key Pressed" << std::endl;
	}

	if (key == GLFW_KEY_W && action == GLFW_PRESS)
	{
		// toggle wireFrame bool
		wireFrame = !wireFrame; 
		// toggle wire frame based on bool state
		wireFrame ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

/// function that alternates screens background colour
void screenColour(GLfloat *red, GLfloat *green, GLfloat *blue, GLboolean *allColour)
{
	//std::cout << "red = " << *red << " green = " << *green << " blue = " << *blue << std::endl;
	if (*red >= 1.0f && *green >= 1.0f && *blue >= 1.0f)
	{
		*allColour = true;
		//std::cout << " - allColour = true" << std::endl;
	}
	if (*red <= 0 && *green <= 0 && *blue <= 0)
	{
		*allColour = false;
		//std::cout << " - allColour = false" << std::endl;
	}
	// change red
	if (!*allColour)
	{
		if (*red < 1.0f)
		{
			*red += 0.01f;
		}
		else if (*green < 1.0f)
		{
			*green += 0.01f;
		}
		else if (*blue < 1.0f)
		{
			*blue += 0.01f;
		}
	}
	else if (*allColour)
	{
		if (*blue > 0.0f)
		{
			*blue -= 0.01f;
		}
		else if (*green > 0.0f)
		{
			*green -= 0.01f;
		}
		else if (*red > 0.0f)
		{
			*red -= 0.01f;
		}
	}



}

