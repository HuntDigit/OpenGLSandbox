#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

#include "Shader.h"
#include "main/Render/Renderer.h"


Shader::Shader(const std::string& filepath)
	: m_Filepath(filepath), m_RenderID(0)
{
    ShaderProgramSource source = ParseShader();
    m_RenderID = CreateShader(source.vertex, source.fragment);
}

Shader::~Shader()
{
}

ShaderProgramSource Shader::ParseShader() 
{
    std::ifstream stream(m_Filepath);
    std::string line;
    std::stringstream ss[2];

    enum class ShaderType
    {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };

    ShaderType type = ShaderType::NONE;

    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos) 
        {
            if (line.find("vertex") != std::string::npos) 
            {
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos) 
            {
                type = ShaderType::FRAGMENT;
            }
        }
        else 
        {
            ss[(int)type] << line << '\n';
        }
    }

    auto vertex = ss[0].str();
    auto fragment = ss[1].str();

    return { vertex, fragment };
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    GLCall(glShaderSource(id, 1, &src, nullptr));
    GLCall(glCompileShader(id));

    int result;
    GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

    if (result == GL_FALSE) 
    {
        int length;
        GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
        char* message = (char*)malloc(length * sizeof(char));
        GLCall(glGetShaderInfoLog(id, length, &length, message));
        std::cout <<
            "Failed to compile " <<
            (type == GL_VERTEX_SHADER ? "vertex" : "fragment") <<
            " shader!" <<
            std::endl;
        std::cout << message << std::endl;
        GLCall(glDeleteShader(id));
        free(message);
        return 0;
    }

    return id;
}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER,   vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));

    GLCall(glLinkProgram(program));

    GLCall(glDetachShader(program, fs));
    GLCall(glDetachShader(program, vs));

    GLCall(glValidateProgram(program));

    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));

    return program;
}

void Shader::Bind() const
{
    GLCall(glUseProgram(m_RenderID));
}

void Shader::Unbind() const
{
    GLCall(glUseProgram(0));
}

void Shader::setUniform4fv(const std::string& name, glm::mat4 proj)
{
    glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &proj[0][0]);
}
void Shader::setUniform1i(const std::string& name, int t)
{
    GLCall(glUniform1i(GetUniformLocation(name), t));
}

void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
    GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}

int Shader::GetUniformLocation(const std::string& name)
{
    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
        return m_UniformLocationCache[name];

    GLCall(int location = glGetUniformLocation(m_RenderID, name.c_str()));
    if (location == -1)
        std::cout << "Warning: uniform '" << name << "' doesn't exist!" << std::endl;
    else
        m_UniformLocationCache[name] = location;
    return location;
}
