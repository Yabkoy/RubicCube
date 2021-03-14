#include "../include/SFMLVisualization.h"

sfmlGrap::mainSFMLVis::mainSFMLVis()
{
	RW = new sf::RenderWindow(sf::VideoMode(WINDOW_W, WINDOW_H, 32), "Rubic Cube");
}
sfmlGrap::mainSFMLVis::~mainSFMLVis()
{
	delete RW;
}