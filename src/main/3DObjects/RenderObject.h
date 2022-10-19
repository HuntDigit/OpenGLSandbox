#pragma once
#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"

#include"main/GraphicsData/Shader.h"
#include"main/GraphicsData/Texture.h"
#include"main/GraphicsData/IndexBuffer.h"
#include"main/GraphicsData/VertexArray.h"
#include"main/GraphicsData/VertexBuffer.h"

class IRenderObject
{
public: 
    virtual const VertexArray&  getVertexArray()  const = 0;
    virtual const VertexBuffer& getVertexBuffer() const = 0;
    virtual const IndexBuffer&  getIndexBuffer()  const = 0;
    virtual Shader& getShader() = 0;
};

class RenderObject : public IRenderObject
{
protected:
	VertexArray va;
	VertexBuffer vb;
	VertexBufferLayout vbLayout;
	IndexBuffer ib;
	Shader shader;

	Texture* currentTexture;

public:
	RenderObject(float* p, size_t pSize, unsigned int* i, size_t iCount, std::string shfile);
	~RenderObject();

public:
	virtual void setTexture(Texture* texture, TextureType type);

	virtual const VertexArray& getVertexArray() const override;
	virtual const VertexBuffer& getVertexBuffer() const override;
	virtual const IndexBuffer& getIndexBuffer() const override;

	virtual Shader& getShader() override;

private:
	virtual void setColorTexture(Texture* texture);
	virtual void setNormalTexture(Texture* texture);
};