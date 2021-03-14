#include "../include/SFMLVisualization.h"


sfmlGrap::mainSFMLVis::mainSFMLVis()
{
	RW = new sf::RenderWindow(sf::VideoMode(WINDOW_W, WINDOW_H, 32), "Rubic Cube");

	RS.setSize(sf::Vector2f(100, 100));
	RS.setFillColor(sf::Color::Red);

	mainUpdateLoop();
}
sfmlGrap::mainSFMLVis::~mainSFMLVis()
{
	delete RW;
}

void sfmlGrap::mainSFMLVis::mainUpdateLoop()
{
	while (RW->isOpen())
	{
		if (RW->pollEvent(mainEvent))
		{
			if (mainEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				RW->close();
		}

		RW->clear(sf::Color::Black);

		RW->draw(RS);

		RW->display();
	}
}
