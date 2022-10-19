#pragma once

#include"imported/imgui/imgui.h"
#include"imported/imgui/imgui_impl_glfw.h"
#include"imported/imgui/imgui_impl_opengl3.h"

inline void ImGui_CleanUp()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}
inline void ImGui_NewFrameGroup()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}
inline void ImGui_RenderFrameGroup()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

class Singleton final
{
private:
	Singleton() {};
	~Singleton() {};

	Singleton(const Singleton& other) = delete;
	Singleton& operator=(const Singleton&) = delete;

public:
	float sBias = 2.0f;
	int sOctaves = 1;
	bool isNeedToUpdate = false;

	static Singleton& GetInstance() { static Singleton instance; return instance; }
};