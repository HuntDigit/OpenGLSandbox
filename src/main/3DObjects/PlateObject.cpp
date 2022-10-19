#include "PlateObject.h"

float positions2[] =
{
	-0.5f, -0.5f,  0.5f,   0.0,  0.0f ,
	-0.5f, -0.5f, -0.5f,   1.0,  0.0f ,
	 0.5f, -0.5f, -0.5f,   1.0,  1.0f ,
	 0.5f, -0.5f,  0.5f,   0.0,  1.0f 
};

unsigned int indices2[] =
{
	0, 1, 2,
	0, 2, 3
};

PlateObject::PlateObject() : RenderObject(positions2, sizeof(positions2), indices2, sizeof(indices2) / sizeof(unsigned int), "res/shaders/default.shader")
{
	vbLayout.Push<float>(3);
	vbLayout.Push<float>(2);
	va.LinkBuffer(vb, vbLayout);
}

Shader& PlateObject::getShader()
{
	return shader;
}