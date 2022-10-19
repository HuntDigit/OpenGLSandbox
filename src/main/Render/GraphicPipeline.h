#pragma once

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<vector>

#include"main/Control/Camera.h"
#include"main/Control/Control.h"

#include"main/Render/Renderer.h"
#include"main/3DObjects/CubeObject.h"

#include"main/Basic/Basic.h"
#include"main/UIElements/UINavigationController.h"

class GraphicPipeline final
{
private:
    Renderer m_Renderer;
    Camera m_Camera;
    Control m_Control;

	UINavigationController mainNavigationController;
public:
	GraphicPipeline(Renderer& renderer);
	~GraphicPipeline();

	void Update(float deltaTime);
	void Render();
    void RenderUI();
	void Events(GLFWwindow* window);;
};