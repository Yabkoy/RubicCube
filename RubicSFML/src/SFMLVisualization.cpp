#include "../include/SFMLVisualization.h"


unsigned int sfmlGrap::mainSFMLVis::selectedSurfaceIndexes[36] =
{
	3, 1, 5, 4, 0, 2,
	1, 5, 4, 3, 0, 2,
	5, 4, 3, 1, 0, 2,
	4, 3, 1, 5, 0, 2,
	0, 1, 2, 4, 5, 3,
	2, 1, 0, 4, 3, 5,
};

//ORANGE 3, 1, 5, 4, 0, 2
//YELLOW 1, 5, 4, 3, 0, 2
//RED    5, 4, 3, 1, 0, 2
//WHITE  4, 3, 1, 5, 0, 2
//GREEN  0, 1, 2, 4, 5, 3
//BLUE   2, 1, 0, 4, 3, 5

sfmlGrap::mainSFMLVis::mainSFMLVis() : mainSurfaces
{
	{3, allPositionOfBlocks[0] }, {1, allPositionOfBlocks[1]}, {5, allPositionOfBlocks[2]},
	{4, allPositionOfBlocks[3]}, {0, allPositionOfBlocks[4]} , {2, allPositionOfBlocks[5]}, //NONE = -1, GREEN - 0 , YELLOW - 1, BLUE - 2, ORANGE - 3, WHITE - 4, RED - 5 
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
				case sf::Keyboard::Space:
					for (int i = 0; i < 6; i++)
					{
						mainSurfaces[i].setDisplayingSurface(selectedSurfaceIndexes[i+24]);
						rc::moves::allMovesArrayPointers[0];
					}
					break;
				case sf::Keyboard::Left:
					mainSelector.changeSelectBox(sf::Keyboard::Left);
					break;
				case sf::Keyboard::Right:
					mainSelector.changeSelectBox(sf::Keyboard::Right);
					break;
				case sf::Keyboard::Up:
					mainSelector.changeSelectBox(sf::Keyboard::Up);
					break;
				case sf::Keyboard::Down:
					mainSelector.changeSelectBox(sf::Keyboard::Down);
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
		RW->draw(mainSelector);

		RW->display();
	}
}

sfmlGrap::mainSFMLVis::~mainSFMLVis()
{
	delete RW;
}