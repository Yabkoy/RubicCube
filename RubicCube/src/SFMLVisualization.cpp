#include "../include/SFMLVisualization.h"

std::array<Colors, 9> getBlockArray(const int& surfaceIndex, const RubicMatrix* rm1, const RubicMatrix* rm2, const RubicMatrix* rm3)
{

	std::array<Colors, 9> returnTypes;
	switch (surfaceIndex)
	{
	case 0: //DEF ORANGE
	{
		returnTypes[0] = rm1[0].b3;
		returnTypes[1] = rm1[1].b2;
		returnTypes[2] = rm1[2].b1;

		returnTypes[3] = rm1[3].b2;
		returnTypes[4] = rm1[4].b1;
		returnTypes[5] = rm1[5].b1;

		returnTypes[6] = rm1[6].b3;
		returnTypes[7] = rm1[7].b1;
		returnTypes[8] = rm1[8].b1;
		break;
	}
	case 1: //DEF YELLOW
	{
		returnTypes[0] = rm1[0].b2;
		returnTypes[1] = rm1[1].b1;
		returnTypes[2] = rm1[2].b2;

		returnTypes[3] = rm2[0].b1;
		returnTypes[4] = rm2[1].b1;
		returnTypes[5] = rm2[2].b1;

		returnTypes[6] = rm3[0].b2;
		returnTypes[7] = rm3[1].b1;
		returnTypes[8] = rm3[2].b2;
		break;
	}
	case 2: //DEF RED
	{
		returnTypes[0] = rm3[0].b1;
		returnTypes[1] = rm3[1].b2;
		returnTypes[2] = rm3[2].b3;

		returnTypes[3] = rm3[3].b1;
		returnTypes[4] = rm3[4].b1;
		returnTypes[5] = rm3[5].b2;

		returnTypes[6] = rm3[6].b1;
		returnTypes[7] = rm3[7].b1;
		returnTypes[8] = rm3[8].b3;
		break;
	}
	case 3: //DEF WHITE
	{
		returnTypes[0] = rm1[6].b2;
		returnTypes[1] = rm1[7].b2;
		returnTypes[2] = rm1[8].b2;
		returnTypes[3] = rm2[6].b2;
		returnTypes[4] = rm2[7].b1;
		returnTypes[5] = rm2[8].b2;
		returnTypes[6] = rm3[6].b2;
		returnTypes[7] = rm3[7].b2;
		returnTypes[8] = rm3[8].b2;
		break;
	}
	case 4: //DEF GREEN
	{
		returnTypes[0] = rm1[0].b1;
		returnTypes[1] = rm2[3].b1;
		returnTypes[2] = rm3[0].b3;
		returnTypes[3] = rm1[3].b1;
		returnTypes[4] = rm2[3].b1;
		returnTypes[5] = rm3[3].b2;
		returnTypes[6] = rm1[6].b1;
		returnTypes[7] = rm2[6].b1;
		returnTypes[8] = rm3[6].b3;
		break;
	}
	case 5: //DEF BLUE
	{
		returnTypes[0] = rm1[2].b3;
		returnTypes[1] = rm2[2].b2;
		returnTypes[2] = rm3[2].b1;
		returnTypes[3] = rm1[5].b2;
		returnTypes[4] = rm2[5].b1;
		returnTypes[5] = rm3[5].b1;
		returnTypes[6] = rm1[8].b3;
		returnTypes[7] = rm2[8].b1;
		returnTypes[8] = rm3[8].b1;
		break;
	}
	default:
		break;
	}

	return returnTypes;
}

ThreeElementBlock AR1[6] =
{
	YELLOW, BLUE, RED, GREEN, ORANGE, WHITE,
};

ThreeElementBlock AR2[12] =
{
	{YELLOW, BLUE}, {YELLOW, RED}, {YELLOW, GREEN}, {YELLOW, ORANGE},
	{BLUE, RED}, {RED, GREEN}, {GREEN, ORANGE}, {ORANGE, BLUE},
	{BLUE, WHITE}, {RED, WHITE}, {GREEN, WHITE}, {ORANGE, WHITE},
};

ThreeElementBlock AR3[8] =
{
	{BLUE, YELLOW, RED}, {RED, YELLOW, GREEN}, {GREEN, YELLOW, ORANGE}, {ORANGE, YELLOW, BLUE},
	{BLUE, WHITE, RED}, {RED, WHITE , GREEN}, {GREEN, WHITE, ORANGE}, {ORANGE, WHITE, BLUE},
};


RubicMatrix matrix1[9] = //0, 3, 6
{
	AR3[2], AR2[3], AR3[3],
	AR2[6], AR1[4], AR2[7],
	AR3[6], AR2[11], AR3[7],
};

RubicMatrix matrix2[9] =
{
	AR2[2], AR1[0], AR2[0],
	AR1[3], Colors::NONE, AR1[1],
	AR2[10], AR1[5], AR2[8],
};
RubicMatrix matrix3[9] =
{
	AR3[1], AR2[1], AR3[0],
	AR2[5], AR1[2], AR2[4],
	AR3[5], AR2[9], AR3[4]
};


void sfmlGrap::surfaceShape::draw(sf::RenderTarget& mainTarget, sf::RenderStates states) const
{
	for (int i = 0; i < block.size(); i++)
		mainTarget.draw(block[i]);
}

sfmlGrap::surfaceShape::surfaceShape(const sf::Vector2f& entryPointPosition)
{

}


void sfmlGrap::surfaceShape::initSurface()
{
	const int elementPadding = 60;

	sf::Vector2f allPositionsOfBlocks[9] =
	{
		sf::Vector2f(entryPointPosition.x - elementPadding, entryPointPosition.y - elementPadding),
		sf::Vector2f(entryPointPosition.x, entryPointPosition.y - elementPadding),
		sf::Vector2f(entryPointPosition.x + elementPadding, entryPointPosition.y - elementPadding),

		sf::Vector2f(entryPointPosition.x - elementPadding, entryPointPosition.y),
		sf::Vector2f(entryPointPosition.x, entryPointPosition.y),
		sf::Vector2f(entryPointPosition.x + elementPadding, entryPointPosition.y),

		sf::Vector2f(entryPointPosition.x - elementPadding, entryPointPosition.y + elementPadding),
		sf::Vector2f(entryPointPosition.x, entryPointPosition.y + elementPadding),
		sf::Vector2f(entryPointPosition.x + elementPadding, entryPointPosition.y + elementPadding),

		
	};

	int elementDone = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::array<Colors, 9> getArray = getBlockArray(5, matrix1, matrix2, matrix3);

			block[elementDone].setFillColor(getSfColor(getArray[elementDone])); //ERROR HERE
			block[elementDone].setSize(sf::Vector2f(50, 50));
			block[elementDone].setPosition(allPositionsOfBlocks[elementDone]);
			elementDone++;
		}
	}
}
void sfmlGrap::surfaceShape::setEntryPointPosition(const sf::Vector2f& epp)
{
	entryPointPosition = epp;
}


sfmlGrap::mainSFMLVis::mainSFMLVis()
{
	RW = new sf::RenderWindow(sf::VideoMode(WINDOW_W, WINDOW_H, 32), "Rubic Cube");

	sf::Vector2f entrySurfacePoint = sf::Vector2f((WINDOW_W / 2) + 25, (WINDOW_W / 2) - 25);
	sf::Vector2f surfacesGenPositions[6] =
	{
		sf::Vector2f(entrySurfacePoint.x + 180, entrySurfacePoint.y),
		sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y),
		sf::Vector2f(entrySurfacePoint.x - 180, entrySurfacePoint.y),
		sf::Vector2f(entrySurfacePoint.x - 360, entrySurfacePoint.y),

		sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y - 180),
		sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y + 180),
	};

	for (int i = 0; i < 6; i++)
	{
		mainRubicSurafes[i].setEntryPointPosition(surfacesGenPositions[i]);
		mainRubicSurafes[i].initSurface();
	}


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

		for (int i = 0; i < 6; i++)
			RW->draw(mainRubicSurafes[i]);

		RW->display();
	}
}
