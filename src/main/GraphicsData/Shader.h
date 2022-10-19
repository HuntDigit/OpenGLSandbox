#pragma once

#include<string>
#include<unordered_map>

#include"glm/glm.hpp"

struct ShaderProgramSource
{
	std::string vertex;
	std::string fragment;
};

class Shader
{
private:
	std::string m_Filepath;
	unsigned int m_RenderID;
	std::unordered_map<std::string, int> m_UniformLocationCache;

public:
	Shader() = default;
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void setUniform4fv(const std::string& name, glm::mat4 proj);
	void setUniform1i(const std::string& name, int t);
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

private:
	ShaderProgramSource ParseShader();
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	int GetUniformLocation(const std::string& name);

};
