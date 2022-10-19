#include "UINavigationController.h"
#include "main/Basic/Basic.h"

UINavigationController::UINavigationController() : rootController(nullptr)
{
}

UINavigationController::UINavigationController(ViewController rootController)
	: rootController(&rootController)
{
	rootController.navigationController = this;
	viewControllers.push_back(rootController);
}

void UINavigationController::pushViewController(ViewController viewtController)
{
	viewtController.navigationController = this;
	viewControllers.push_back(viewtController);
}

void UINavigationController::popViewController()
{
	viewControllers.pop_back();
}

ViewController::ViewController() 
	: title("Default Title")
{
}

ViewController::~ViewController()
{
}

void ViewController::UpdateUI()
{
	ImGui::SetNextWindowSize({ 600,1080 }, ImGuiCond_Once);
	ImGui::SetNextWindowPos({ 0, 0 }, ImGuiCond_Once, { 0,0 });
	ImGui::Begin(title);

	if (ImGui::Button("FirstController", { 500, 100 }))
	{
		FirstController secondController = FirstController();
		secondController.title = "FirstController";
		navigationController->pushViewController(secondController);
	}

	ImGui::End();
}

FirstController::FirstController()
{
}

void FirstController::UpdateUI()
{
	ImGui::Begin(title);

	if (ImGui::Button("SecondController", { 500, 100 }))
	{
		SecondController secondController = SecondController();
		secondController.title = "SecondController";
		navigationController->pushViewController(secondController);
	}
	
	ImGui::End();
}



SecondController::SecondController()
{
}

void SecondController::UpdateUI()
{
	ImGui::Begin(title);

	if (ImGui::Button("Back To Previos", { 500, 100 }))
	{
		navigationController->popViewController();
	}

	ImGui::End();
}
