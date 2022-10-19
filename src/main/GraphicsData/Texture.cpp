#include <stb/stb_image.h>

#include "Texture.h"

Texture::Texture(const std::string& filepath)
	: m_RenderID(0), m_FilePath(filepath), m_LocalBuffer(nullptr),
	  m_Width(0), m_Height(0), m_BPP(0)
{
	stbi_set_flip_vertically_on_load(true);
	m_LocalBuffer = stbi_load(filepath.c_str(), &m_Width, &m_Height, &m_BPP, 4);

	CreateTexture2D();

	if (m_LocalBuffer)
		stbi_image_free(m_LocalBuffer);
}

Texture::Texture(unsigned char* buffer, int width, int height)
	: m_RenderID(0), m_LocalBuffer(buffer),
	m_Width(width), m_Height(height), m_BPP(1)
{
	CreateTexture2D();
}

Texture::~Texture()
{
	GLCall(glDeleteTextures(1, &m_RenderID));
	delete m_LocalBuffer;
}

void Texture::CreateTexture2D()
{
	GLuint ChanelType = GetChanelType(m_BPP);

	GLCall(glGenTextures(1, &m_RenderID));
	GLCall(glBindTexture(GL_TEXTURE_2D, m_RenderID));

	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));

	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, ChanelType, GL_UNSIGNED_BYTE, m_LocalBuffer));
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}

GLuint Texture::GetChanelType(int ch) 
{
	//TODO: Create assert if no chanel
	switch (ch)
	{
	case 1:
		return GL_RED;
	case 3:
		return GL_RGBA;
	case 4:
		return GL_RGBA;
	default:
		return GL_RGBA;
	}
}

void Texture::Bind(unsigned int slot) const
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glBindTexture(GL_TEXTURE_2D, m_RenderID));
}

void Texture::Unbind() const
{
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}