#include "../include/SFMLVisualization.h"

int main()
{
	std::cout << rc::blocks::AR1[2].b1 << std::endl;


	srand( time(NULL));
	sfmlGrap::mainSFMLVis();
	return 0;
}