#include "../include/SFMLVisualization.h"

sfmlGrap::mainSFMLVis::mainSFMLVis() : mainSurfaces
{
	{rc::ORANGE, allPositionOfBlocks[0] }, {rc::YELLOW, allPositionOfBlocks[1]}, {rc::RED, allPositionOfBlocks[2]},
	{rc::WHITE, allPositionOfBlocks[3]}, {rc::GREEN, allPositionOfBlocks[4]} , {rc::BLUE, allPositionOfBlocks[5]},
}
{
	RW = new sf::RenderWindow(sf::VideoMode(WINDOW_W, WINDOW_H, 32), "Rubic Cube");

	RW->setVerticalSyncEnabled(true);

	mainUpdateLoop();
}

void sfmlGrap::mainSFMLVis::executePollEvent(sf::Event& mainEvent)
{
	switch (mainEvent.type)
	{
		
		case sf::Event::Closed:
			RW->close();
			break;
		case sf::Event::KeyPressed:
		{
			switch (mainEvent.key.code)
			{
				case sf::Keyboard::Escape:
				RW->close();
				break;
			}
			break;
		}

	}
}

void sfmlGrap::mainSFMLVis::mainUpdateLoop()
{
	while (RW->isOpen())
	{
		if (RW->pollEvent(mainEvent))
		{
			executePollEvent(mainEvent);
		}

		RW->clear(sf::Color::Black);
		
		for (int i = 0; i < 6; i++)
			RW->draw(mainSurfaces[i]);

		RW->display();
	}
}

sfmlGrap::mainSFMLVis::~mainSFMLVis()
{
	delete RW;
}