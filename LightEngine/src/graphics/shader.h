#pragma once
#include <vector>
#include <iostream>
#include <glad/glad.h>
#include <GLFW\glfw3.h>
#include "../utilities/file_utilities.h"

namespace Light
{
	class Shader
	{
	public:
		GLuint shaderID;
		const char* vertPath;
		const char* fragPath;

	public:
		Shader(const char* vert_path, const char* frag_path);
		~Shader();
		void enable() const;
		void disable() const;

	private:
		GLuint load();
	};


}
