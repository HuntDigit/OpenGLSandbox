#include"main/Application/ApplicationManager.h"

ApplicationManager* ApplicationManager::s_AppInstance = nullptr;

int main(int argc, char** argv)
{
    ApplicationManager application;

    Renderer renderrer;
    renderrer.SetViewPortType(ViewPortType::WINDOW);
    renderrer.DephEnabled(true);

    GraphicPipeline defaultGraphicPipeline(renderrer);
    application.StartRunLoopApplication(defaultGraphicPipeline);

    return EXIT_SUCCESS;
}