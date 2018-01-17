#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace Light
{
	void GLClearError();
	bool GLLogCall(const char* function, const char* file, int line);

#define ASSERT(x) if (!(x)) __debugbreak();
#define GlCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))
}


