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


		Shader shader("src/graphics/shaders/basic.vert", "src/graphics/shaders/basic.frag");
		shader.enable();


		input = new Input(window);
	}

	// NOTE: LightEngine handles the deletion of all major components. Thus, while input is tied to a
	// Window object, this pointer should NOT be deleted from within Input. LightEngine is responsible for this
	LightEngine::~LightEngine()
	{
		delete window;
		delete input;
	}
}

