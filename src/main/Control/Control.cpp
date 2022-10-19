#include "Control.h"

#include <iostream>
#include <thread>
#include <chrono>

#include "main/Basic/Basic.h"

Control::Control()
{

}

void Control::Inputs(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
	{
		Singleton::GetInstance().sBias += 0.25;
		std::cout << "sBias: " << Singleton::GetInstance().sBias << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
	{
		Singleton::GetInstance().sBias -= 0.25;
		std::cout << "sBias: " << Singleton::GetInstance().sBias << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
	{
		Singleton::GetInstance().sOctaves += 1;
		std::cout << "sOctaves: " << Singleton::GetInstance().sOctaves << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
	{
		Singleton::GetInstance().sOctaves -= 1;
		std::cout << "sOctaves: " << Singleton::GetInstance().sOctaves << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
	{
		Singleton::GetInstance().isNeedToUpdate = true;
		std::cout << "isNeedToUpdate: " << Singleton::GetInstance().isNeedToUpdate << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));

	}
}
