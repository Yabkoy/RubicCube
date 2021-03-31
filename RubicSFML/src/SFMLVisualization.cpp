#include "../include/SFMLVisualization.h"

sfmlGrap::mainSFMLVis::mainSFMLVis() : mainSurfaces
{
	{3, allPositionOfBlocks[0] }, {1, allPositionOfBlocks[1]}, {5, allPositionOfBlocks[2]},
	{4, allPositionOfBlocks[3]}, {0, allPositionOfBlocks[4]} , {2, allPositionOfBlocks[5]}, 
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