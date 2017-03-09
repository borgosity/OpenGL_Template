// shadertype = glsl
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;


out vec3 vNormal;
out vec2 vTexCoord;
out vec3 vPostion;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float time;

uniform sampler2D texture_perlin;

void main()
{
    vNormal = normal;

	vec3 pos = position;
	//pos.y += texture(texture_perlin, texCoord).r * 2.5f;
	pos.y += texture(texture_perlin, texCoord).r * sin(time + pos.x);


    vTexCoord = texCoord;
    gl_Position = projection * view * model * vec4(pos, 1.0f);
}
