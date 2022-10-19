#pragma once

#define ASSERT(con) if (!(con)) __debugbreak();
#if 1
#define GLCall(fun) GLClearError();\
    fun;\
    ASSERT(GLLogCall(#fun, __FILE__, __LINE__))
#else
#define GLCall(fun); fun
    
#endif

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);