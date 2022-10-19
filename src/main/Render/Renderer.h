#pragma once

#include"main/GraphicsData/Shader.h"
#include"main/GraphicsData/VertexArray.h"
#include"main/GraphicsData/IndexBuffer.h"

enum class ViewPortType
{
    WINDOW,
    RENDER
};

class Renderer
{
public:
    void SetViewPortType(ViewPortType type);
    void DephEnabled(bool isEnabled);
    void Clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};