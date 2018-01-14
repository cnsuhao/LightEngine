#include "LightEngine.h"
#include "src\math\Vector3.h"

using namespace Light;

int main()
{
	LightEngine engine("Light Engine", 1920, 1080);

	std::cout << "\n" << result << std::endl;


	while (!engine.window->closed())
	{
		engine.window->clear();
		engine.window->update();
	}

	//system("PAUSE");
	return 0;
}