#include <iostream>

#include "Camera.h"
#include "main/Basic/Basic.h"

Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;
	Position = position;
}

void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Orientation, Up);
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	cameraMatrix = projection * view;
}

void Camera::updateShader(Shader& shader)
{
	shader.Bind();
	shader.setUniform4fv("u_Camera", cameraMatrix);
}

void Camera::Inputs(GLFWwindow* window)
{
	if (ImGui::IsKeyDown(ImGuiKey_W))
	{
		Position += speed * Orientation;
	}
	if (ImGui::IsKeyDown(ImGuiKey_A))
	{
		Position += speed * -glm::normalize(glm::cross(Orientation, Up));
	}
	if (ImGui::IsKeyDown(ImGuiKey_S))
	{
		Position += speed * -Orientation;
	}
	if (ImGui::IsKeyDown(ImGuiKey_D))
	{
		Position += speed * glm::normalize(glm::cross(Orientation, Up));
	}
	if (ImGui::IsKeyDown(ImGuiKey_Space))
	{
		Position += speed * Up;
	}
	if (ImGui::IsKeyDown(ImGuiKey_LeftCtrl))
	{
		Position += speed * -Up;
	}
	if (ImGui::IsKeyDown(ImGuiKey_LeftShift))
	{
		speed = 0.05f;
	}
	if (ImGui::IsKeyDown(ImGuiKey_LeftAlt))
	{
		speed = 0.0005f;
	} 
	bool lar = ImGui::IsKeyReleased(ImGuiKey_LeftAlt);
	bool lsr = ImGui::IsKeyReleased(ImGuiKey_LeftShift);

	if (lar && lsr)
	{
		speed = 0.01f;
	}


	
	if (ImGui::IsMouseDown(ImGuiMouseButton_Right))
	{
		ImGui::SetMouseCursor(ImGuiMouseCursor_None);
		//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (firstClick)
		{
			glfwSetCursorPos(window, (width / 2), (height / 2));
			firstClick = false;
		}

		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
		float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

		glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));

		if (abs(glm::angle(newOrientation, Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			Orientation = newOrientation;
		}

		Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);

		glfwSetCursorPos(window, (width / 2), (height / 2));
	}
	else if (ImGui::IsMouseReleased(ImGuiMouseButton_Right))
	{
		ImGui::SetMouseCursor(ImGuiMouseCursor_Arrow);
		//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		firstClick = true;
	}
}
