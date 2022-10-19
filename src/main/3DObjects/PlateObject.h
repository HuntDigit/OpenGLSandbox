#pragma once

#include "RenderObject.h"

class PlateObject : public RenderObject
{
public:
	PlateObject();
	~PlateObject() = default;

	virtual Shader& getShader() override;
};