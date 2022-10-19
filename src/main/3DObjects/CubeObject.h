#pragma once

#include "RenderObject.h"

class CubeObject : public RenderObject
{

public:
	CubeObject();
	~CubeObject();

	virtual Shader& getShader() override;

};


