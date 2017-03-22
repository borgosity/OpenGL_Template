#include "Mirror.h"

Mirror::Mirror()
{
}


Mirror::~Mirror()
{
}

void Mirror::update()
{
}
///
/// Create Buffer Objects
///
void Mirror::setupFBO()
{
	// Framebuffer
	glGenFramebuffers(1, &m_FBO);
	glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);
	// Texturebuffer
	m_TBO = generateTexture(false, false);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_TBO, 0);
	// Renderbuffer
	glGenRenderbuffers(1, &m_RBO);
	glBindRenderbuffer(GL_RENDERBUFFER, m_RBO);
	// store depth and stencil in the same buffer
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, SCREEN_W, SCREEN_H);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	// attach buffer
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_RBO);
	// check if frame buffer is complete
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
		std::cout << "ERROR --> MIRROR: Framebuffer is not complete!" << std::endl;
	}
	// clear buffer
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

}
///
/// Generate Attachment Texture: 
/// - standard colour texture =  !a_depth && !stencil
/// - depth texture =  a_depth && !stencil
/// - stencil texture =  !a_depth && stencil
///
GLuint Mirror::generateTexture(GLboolean a_depth, GLboolean a_stencil)
{
	// What enum to use?
	GLenum attType;
	if (!a_depth && !a_stencil) {
		attType = GL_RGB;
	}
	else if (a_depth && !a_stencil) {
		attType = GL_DEPTH_COMPONENT;
	}
	else if (!a_depth && a_stencil) {
		attType = GL_STENCIL_INDEX;
	}

	// Generate texture ID 
	GLuint textureID;
	glGenTextures(1, &textureID);
	// bind data
	glBindTexture(GL_TEXTURE_2D, textureID);
	if (!a_depth && !a_stencil) {
		glTexImage2D(GL_TEXTURE_2D, 0, attType, SCREEN_W, SCREEN_H, 0, attType, GL_UNSIGNED_BYTE, NULL);
	}
	else {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, SCREEN_W, SCREEN_H, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, NULL);
	}
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);

	return textureID;
}
