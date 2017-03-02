// shadertype = glsl
#version 330 core
in vec3 vPosition;
in vec3 vNormal;
in vec2 TexCoord;

out vec4 color;

// light
uniform vec3 lightDirection;
uniform vec3 lightColour;
uniform vec3 cameraPos;
uniform float specPow;


// Texture samplers
uniform sampler2D diffuse;
uniform sampler2D normal;

void main()
{
	float d = max(0, dot( normalize(vNormal.xyz), lightDirection ) );
	vec3 emission = normalize(cameraPos - vPosition.xyz);
	vec3 reflection = reflect(-lightDirection, vNormal.xyz);
	float specular = max(0, dot(emission, reflection));
	specular = pow(specular, specPow);

	color = texture(diffuse, TexCoord) * vec4(lightColour * d + lightColour * specular, 1);

}
