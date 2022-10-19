#include "CubeObject.h"

float positions[] =
{
	-0.1f, -0.1f,  0.1f,   0.0,  0.0f ,
	-0.1f, -0.1f, -0.1f,   1.0,  0.0f ,
	 0.1f, -0.1f, -0.1f,   1.0,  1.0f ,
	 0.1f, -0.1f,  0.1f,   0.0,  1.0f ,
	-0.1f,  0.1f,  0.1f,   0.0,  0.0f ,
	-0.1f,  0.1f, -0.1f,   1.0,  0.0f ,
	 0.1f,  0.1f, -0.1f,   1.0,  1.0f ,
	 0.1f,  0.1f,  0.1f,   0.0,  1.0f 
};

unsigned int indices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};

CubeObject::CubeObject() : RenderObject(positions, sizeof(positions), indices, sizeof(indices) / sizeof(unsigned int), "res/shaders/default.shader")
{
    vbLayout.Push<float>(3);
	vbLayout.Push<float>(2);
    va.LinkBuffer(vb, vbLayout);
}

CubeObject::~CubeObject() {  }

Shader& CubeObject::getShader()
{
	return shader;
}