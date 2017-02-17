#version 330 core
in vec4 ourColor;
//in vec3 ourPosition;

out vec4 color;

void main()
{
	color = ourColor;
//	color = vec4(ourPosition, 1.0f);
}
