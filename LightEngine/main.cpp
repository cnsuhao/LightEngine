#pragma once
#include "LightEngine.h"

using namespace Light;

int main()
{
	LightEngine engine("Light Engine", 1920, 1080);
	
	while (!engine.window->closed())
	{
		engine.window->clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		engine.window->update();
	}

	//system("PAUSE");
	return 0;
}