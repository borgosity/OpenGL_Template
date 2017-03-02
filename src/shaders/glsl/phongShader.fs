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
	float direction = max(0, dot( normalize(vNormal.xyz), lightDirection ) );
	vec3 emission = normalize(cameraPos - vPosition.xyz);
	vec3 reflection = reflect(-lightDirection, vNormal.xyz);

	// specular
	float spec = max(0, dot(emission, reflection));
	vec3 specular = pow(spec, specPow) * vec3(texture(diffuse, TexCoord));

	color =  vec4(direction + specular, 1.0f);

}
