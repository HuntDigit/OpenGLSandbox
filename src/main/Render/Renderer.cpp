#include <iostream>

#include "Renderer.h"


void GLClearError() 
{
    while (glGetError() != GL_NO_ERROR) {};
}

bool GLLogCall(const char* function, const char* file, int line) 
{
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] (" << std::hex << error << "): " << function <<
            " " << file << ":" << line << std::endl;
        return false;
    }
    return true;
}

void Renderer::SetViewPortType(ViewPortType type) 
{
    switch (type)
    {
    case ViewPortType::WINDOW:
        GLCall(glViewport(0, 0, 1920, 1080));
        return;
    case ViewPortType::RENDER:
        GLCall(glViewport(0, 0, 1920, 1080));
        return;
    default:
        GLCall(glViewport(0, 0, 1024, 800));
        return;
    }
}

void Renderer::DephEnabled(bool isEnabled)
{
    if (isEnabled) 
        GLCall(glEnable(GL_DEPTH_TEST))
    else
        GLCall(glDisable(GL_DEPTH_TEST))
}

void Renderer::Clear() const 
{
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    GLCall(glClearColor(0.2f, 0.2f, 0.2f, 0.0f));
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
    shader.Bind();
    va.Bind();
    ib.Bind();

    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
