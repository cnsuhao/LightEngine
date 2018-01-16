#pragma once
#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/input/input.h"
#include "src/math/math.h"

namespace Light
{
	class LightEngine
	{
	public:
		Window* window;
		Input* input;

	public:
		LightEngine(const char* window_title, int window_width, int window_height);
		~LightEngine();
	};
}