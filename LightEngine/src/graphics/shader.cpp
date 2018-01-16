#include "shader.h"

namespace Light
{
	Shader::Shader(const char* a_vert_path, const char* a_frag_path) :
		vertPath(a_vert_path), fragPath(a_frag_path)
	{
		shaderID = load();
	}

	Shader::~Shader()
	{
		glDeleteProgram(shaderID);
	}

	GLuint Shader::load()
	{
		// Create shader program and shaders
		GLuint program = glCreateProgram();
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

		std::string vertSourceString = FileUtilities::read_file(vertPath);
		std::string fragSourceString = FileUtilities::read_file(fragPath);

		// Read shader source files
		const char* vertSource = vertSourceString.c_str();
		const char* fragSource = fragSourceString.c_str();


		glShaderSource(vertex, 1, &vertSource, NULL);
		glCompileShader(vertex);

		GLint result;
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

		// Check if the vertex shader compiled correctly
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);
			std::cout << "Failed to compile vertex shader!" << std::endl << &error[0] << std::endl;
			glDeleteShader(vertex);
			return 0;
		}

		glShaderSource(fragment, 1, &fragSource, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

		// Check if the fragment shader compiled correctly
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);
			std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
			glDeleteShader(fragment);
			return 0;
		}

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertex);
		glDeleteShader(fragment);
		
		return program;
	}

	void Shader::enable() const
	{
		glUseProgram(shaderID);
	}

	void Shader::disable() const
	{
		glUseProgram(0);
	}

}