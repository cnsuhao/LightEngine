#include "LightEngine.h"

namespace Light
{
	LightEngine::LightEngine(const char* a_window_title, int a_window_width, int a_window_height)
	{
		window = new Window(a_window_title, a_window_width, a_window_height);
		glClearColor(0.7f, 0.7f, 0.7f, 1.0f);

		GLfloat vertices[] =
		{
			4, 3, 0,
			12, 3, 0,
			4, 6, 0,
			4, 6, 0,
			12, 6, 0,
			12, 3, 0
		};

		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);

		Matrix4 ortho = Matrix4::orthographic(0, 16, 0, 9, -1, 1);

		Shader shader("src/graphics/shaders/basic.vert", "src/graphics/shaders/basic.frag");
		shader.enable();
		glUniformMatrix4fv(glGetUniformLocation(shader.shaderID, "pr_matrix"), 1, GL_FALSE, ortho.underlyingArray);


		input = new Input(window);
	}

	LightEngine::~LightEngine()
	{
		delete window;
		delete input;
	}
}

