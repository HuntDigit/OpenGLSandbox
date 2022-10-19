#pragma once

#include <vector>

#include "main/GraphicsData/Texture.h"
#include "main/GraphicsData/Shader.h"

namespace RenderStorrage
{
	class TextureStorrage final
	{
	private:
		std::vector<Texture> m_TextureStorage;
	public:
		TextureStorrage();
		~TextureStorrage();

		void PushTexture(Texture& texture);
		void RemoveTexture(Texture& texture);
	};
}