#include "tests.h"
#include "Loader.h"
#include "Renderer.h"

// Shaders
const GLchar* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
"}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

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

void renderEngineTest()
{
	std::cout << "Starting OpenGL Test - 02" << std::endl;

	// initialise display
	DisplayManager * display = new DisplayManager();
	display->createDisplay();

	// initialise loader
	Loader * loader = new Loader();
	Renderer * renderer = new Renderer();

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

	// initialise vertices for triangle
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f, // Left  
		0.5f, -0.5f, 0.0f, // Right 
		0.0f,  0.5f, 0.0f  // Top   
	};

	RawModel * model = loader->loadToVAO(vertices);

	// draw loop
	while (!glfwWindowShouldClose(display->window()))
	{
		// check and call events
		glfwPollEvents();

		// game logic
		// render
		renderer->prepare(1,0,0);
		renderer->render(model, shaderProgram);
		// swap the buffers
		glfwSwapBuffers(display->window());
		glfwSetKeyCallback(display->window(), key_callback);

	}
	// VAO VBO clean up
	loader->cleanUp();
	// Terminate GLFW
	glfwTerminate();
	std::cout << "Finished!!  - 02 \n\n" << std::endl;
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

