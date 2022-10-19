#pragma once

#include<GLFW/glfw3.h>

class Control
{
public:

	Control();
	~Control() = default;

	void Inputs(GLFWwindow* window);
};

