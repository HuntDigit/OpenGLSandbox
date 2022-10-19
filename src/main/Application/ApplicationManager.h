#pragma once

#include"main/Render/Renderer.h"
#include"main/Storrage/RenderStorrage.h"
#include"main/Render/GraphicPipeline.h"

enum class DisplayType
{
	WINDOW,
	BORDERED,
	FULLSCREEN
};

struct RenderSize
{
	unsigned int Width;
	unsigned int Height;

	unsigned int RenderWidth;
	unsigned int RenderHeight;
};

class ApplicationManager
{
public:
	RenderStorrage::TextureStorrage textureStorrage;

public:
	ApplicationManager();
	~ApplicationManager();

public:
	void StartRunLoopApplication(GraphicPipeline& graphicPipeline);
	static ApplicationManager& GetAppInstance(); 

private:
	void setupUI();
	RenderSize getDisplayUnitSize() const;

private:
	GLFWwindow* m_Window;
	static ApplicationManager* s_AppInstance;
};

