#include "Shaders.h"

 ShaderPath Shader::cameraShader =		{ "res/glsl/cameraShader.vert",		"res/glsl/cameraShader.frag" };
 ShaderPath Shader::colourShader =		{ "res/glsl/colourShader.vert",		"res/glsl/colourShader.frag" };
 ShaderPath Shader::dualTextureShader = { "res/glsl/dualTextureShader.vert",	"res/glsl/dualTextureShader.frag" };
 ShaderPath Shader::indexShader =		{ "res/glsl/indexShader.vert",		"res/glsl/indexShader.frag" };
 // lights
 ShaderPath Shader::lampShader =		{ "res/glsl/lights/lampShader.vert",		"res/glsl/lights/lampShader.frag" };
 ShaderPath Shader::lightShader =		{ "res/glsl/lights/lightingShader.vert",	"res/glsl/lights/lightingShader.frag" };
 ShaderPath Shader::pointLight =		{ "res/glsl/lights/pointLight.vert",		"res/glsl/lights/pointLight.frag" };
 ShaderPath Shader::spotLight =			{ "res/glsl/lights/spotLight.vert",			"res/glsl/lights/spotLight.frag" };
 ShaderPath Shader::spotLight_soft =	{ "res/glsl/lights/spotLight_soft.vert",	"res/glsl/lights/spotLight_soft.frag" };
 // particles
 ShaderPath Shader::particleShader =	{ "res/glsl/particles/particleShader.vert", "res/glsl/particles/particleShader.frag" };

 ShaderPath Shader::planeShader  =		{ "res/glsl/planeShader.vert",				"res/glsl/planeShader.frag" };
 ShaderPath Shader::terrainShader =		{ "res/glsl/terrainShader.vert",			"res/glsl/terrainShader.frag" };
 ShaderPath Shader::animeShader =		{ "res/glsl/animationShader.vert",			"res/glsl/animationShader.frag" };
 ShaderPath Shader::meshShader =		{ "res/glsl/meshShader.vert",				"res/glsl/meshShader.frag" };
 // other
 ShaderPath Shader::modelShader =		{ "res/glsl/other/modelShader.vert",		"res/glsl/other/modelShader.frag" };
 ShaderPath Shader::phongShader =		{ "res/glsl/other/phongShader.vert",		"res/glsl/other/phongShader.frag" };
 ShaderPath Shader::rippleShader =		{ "res/glsl/other/rippleShader.vert",		"res/glsl/other/rippleShader.frag" };
 ShaderPath Shader::staticShader =		{ "res/glsl/other/staticShader.vert",		"res/glsl/other/staticShader.frag" };
 ShaderPath Shader::textureShader =		{ "res/glsl/other/textureShader.vert",		"res/glsl/other/textureShader.frag" };
 ShaderPath Shader::transformShader =	{ "res/glsl/other/transformShader.vert",	"res/glsl/other/transformShader.frag" };
 ShaderPath Shader::uniformShader =		{ "res/glsl/other/uniformShader.vert",		"res/glsl/other/uniformShader.frag" };