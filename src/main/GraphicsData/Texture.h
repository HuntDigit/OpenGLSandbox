#pragma once

#include "main/Render/Renderer.h"

enum class TextureType {
	Color,
	Normal
};

class Texture
{
private:
	unsigned int m_RenderID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
public:
	Texture(const std::string& filepath);
	Texture(unsigned char* buffer, int width, int height);
	~Texture();

	void CreateTexture2D();
	GLuint GetChanelType(int ch);

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline int GetWidth() const  { return m_Width;  }
	inline int GetHeight() const { return m_Height; }
};