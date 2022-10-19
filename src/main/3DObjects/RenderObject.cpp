#include "RenderObject.h"

RenderObject::RenderObject(float* p, size_t pSize, unsigned int* i, size_t iCount, std::string shfile)
	: va(),
	vb(p, pSize),
	vbLayout(),
	ib(i, iCount),
	shader(shfile),
	currentTexture(nullptr)
{
	//Default setup
}

RenderObject::~RenderObject()
{

}


void RenderObject::setTexture(Texture* texture, TextureType type)
{
	switch (type)
	{
	case TextureType::Color:
		setColorTexture(texture);
		break;
	case TextureType::Normal:
		setNormalTexture(texture);
		break;
	default:
		break;
	}

}

void RenderObject::setColorTexture(Texture* texture)
{
	currentTexture = texture;
	shader.Bind();
	currentTexture->Bind();
	shader.setUniform1i("u_Texture", 0);
}

void RenderObject::setNormalTexture(Texture* texture)
{
	currentTexture = texture;
	shader.Bind();
	currentTexture->Bind();
	shader.setUniform1i("u_Texture", 1);
}

const VertexArray& RenderObject::getVertexArray() const
{ 
	return va; 
}
const VertexBuffer& RenderObject::getVertexBuffer() const 
{ 
	return vb; 
}
const IndexBuffer& RenderObject::getIndexBuffer() const 
{ 
	return ib; 
}

Shader& RenderObject::getShader() 
{ 
	return shader; 
}