#include "../include/SFMLVisualization.h"

void sfmlGrap::surfaceShape::draw(sf::RenderTarget& mainTarget, sf::RenderStates states) const
{
	mainTarget.draw(testRS);
}

sfmlGrap::surfaceShape::surfaceShape()
{
	testRS.setSize(sf::Vector2f(100, 100));
	testRS.setFillColor(sf::Color::Red);
}


sfmlGrap::mainSFMLVis::mainSFMLVis()
{
	RW = new sf::RenderWindow(sf::VideoMode(WINDOW_W, WINDOW_H, 32), "Rubic Cube");

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

		RW->draw(testSH);

		RW->display();
	}
}
