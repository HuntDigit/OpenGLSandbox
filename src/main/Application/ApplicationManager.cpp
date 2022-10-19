#include "ApplicationManager.h"

ApplicationManager::ApplicationManager()
    : m_Window(nullptr)
{
    if (!glfwInit()) glfwTerminate();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    RenderSize size = getDisplayUnitSize();
    m_Window = glfwCreateWindow(size.Width, size.Height, "Hello GL", NULL, NULL);
    if (!m_Window) glfwTerminate();

    glfwMakeContextCurrent(m_Window);

    //TODO: If config vsync true
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) glfwTerminate();

    setupUI();
}

ApplicationManager::~ApplicationManager()
{
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void ApplicationManager::setupUI()
{
    const char* glsl_version = "#version 330";

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.FontGlobalScale = 2;

    auto& style = ImGui::GetStyle();
    style.ScaleAllSizes(2);

    ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void ApplicationManager::StartRunLoopApplication(GraphicPipeline& graphicPipeline)
{
    while (!glfwWindowShouldClose(m_Window))
    {
        graphicPipeline.Update(0.0f);
        graphicPipeline.Render();
        graphicPipeline.RenderUI();

        graphicPipeline.Events(m_Window);
    }
}

ApplicationManager& ApplicationManager::GetAppInstance()
{
    return *s_AppInstance;
}

RenderSize ApplicationManager::getDisplayUnitSize() const
{
    return { 1920, 1080, 1920, 1080 };
}
