#include <iostream>

#include "main/Application/ApplicationManager.h"
#include "main/Render/GraphicPipeline.h"

GraphicPipeline::GraphicPipeline(Renderer& renderer)
    : m_Renderer(renderer), m_Camera(1920, 1080, { 0.0f, 0.0f, 1.0f }), m_Control(), mainNavigationController()
{
    FirstController firstController = FirstController();
    firstController.title = "First Controller";
    mainNavigationController.pushViewController(firstController);
}

GraphicPipeline::~GraphicPipeline()
{

    //UI
    ImGui_CleanUp();
}

void GraphicPipeline::Update(float deltaTime)
{
    //for (RenderObject* obj : renderObjects)
    //{
    //    Shader& shader = obj->getShader();
    //    shader.Bind();

    //    m_Camera.updateMatrix(45.0f, 0.01f, 100.0f);
    //    m_Camera.updateShader(shader);

    //    glm::mat4 model = glm::mat4(1.0f);
    //    shader.setUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
    //    shader.setUniform4fv("u_Model", model );

    //}
}

void GraphicPipeline::Render()
{
    m_Renderer.Clear();

    //current scene get current , get objects , get object.geometry , geometry.va|ib|sh

    //for (RenderObject* obj : renderObjects)
    //{
    //    m_Renderer.Draw(obj->getVertexArray(), obj->getIndexBuffer(), obj->getShader());
    //}
}

void GraphicPipeline::RenderUI()
{
    ImGui_NewFrameGroup();
    FirstController* currentController = dynamic_cast<FirstController*>(&mainNavigationController.viewControllers.back());
    currentController->UpdateUI();
    ImGui_RenderFrameGroup();
}

void GraphicPipeline::Events(GLFWwindow* window)
{
    m_Camera.Inputs(window);
    m_Control.Inputs(window);

    glfwSwapBuffers(window);
    glfwPollEvents();
}