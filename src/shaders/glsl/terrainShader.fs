// shadertype = glsl
#version 330 core
in vec3 vNormal;
in vec2 vTexCoord;
in vec3 vPosition;


out vec4 color;

// light
uniform vec3 lightDirection;

// Texture samplers
uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_perlin;

void main()
{
	//float height = vPosition.y;
	//if (height < 0.001f){
	//	color = vec4(0.0f,0.0f,0.5f,1.0);
	//}
	//else {
	//	color = vec4(0.0f,1.0f,0.0f,1.0);
	//}
    color = texture(texture_diffuse1, vTexCoord);
	color.a = 1.0f;
}
