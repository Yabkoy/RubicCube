#include "../include/SFMLVisualization.h"

/// TODO: Rubic Cube instructions need to move:

std::string getStringNamFromRubicElemnt(const Colors& element)
{
	switch (element)
	{
	case GREEN:
		return  "GREEN";
		break;
	case YELLOW:
		return  "YELLOW";
		break;
	case BLUE:
		return  "BLUE";
		break;
	case ORANGE:
		return  "ORANGE";
		break;
	case WHITE:
		return  "WHITE";
		break;
	case RED:
		return  "RED";
		break;
	default:
		return  "NONE";
		break;
	}
}

std::ostream& operator<<(std::ostream& stream, const Colors& col)
{
	stream << getStringNamFromRubicElemnt(col);
	return stream;
}



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

void LPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
{
	RubicMatrix nowStatematrix1[9];
	RubicMatrix nowStatematrix2[9];
	RubicMatrix nowStatematrix3[9];

	// Array Copy Statement ---------------
	for (int i = 0; i < 9; i++)
		nowStatematrix1[i] = matrix1[i];
	for (int i = 0; i < 9; i++)
		nowStatematrix2[i] = matrix2[i];
	for (int i = 0; i < 9; i++)
		nowStatematrix3[i] = matrix3[i];
	// ------------------------------------

	matrix1[0].b3 = nowStatematrix1[6].b2;
	matrix1[3].b2 = nowStatematrix2[6].b2;
	matrix1[6].b3 = nowStatematrix3[6].b2;

	matrix1[0].b2 = nowStatematrix1[6].b3;
	matrix2[0].b1 = nowStatematrix1[3].b2;
	matrix3[0].b2 = nowStatematrix1[0].b3;

	matrix3[0].b1 = nowStatematrix1[0].b2;
	matrix3[3].b1 = nowStatematrix2[0].b1;
	matrix3[6].b1 = nowStatematrix3[0].b2;

	matrix1[6].b2 = nowStatematrix3[0].b1;
	matrix2[6].b2 = nowStatematrix3[3].b1;
	matrix3[6].b2 = nowStatematrix3[6].b1;

	// ===================================

	matrix1[0].b1 = nowStatematrix1[6].b1;
	matrix2[0].b2 = nowStatematrix1[3].b1;
	matrix3[0].b3 = nowStatematrix1[0].b1;

	matrix1[3].b1 = nowStatematrix2[6].b1;
	matrix3[3].b2 = nowStatematrix2[0].b2;

	matrix1[6].b1 = nowStatematrix3[6].b3;
	matrix2[6].b1 = nowStatematrix3[3].b2;

	matrix3[6].b3 = nowStatematrix3[0].b3;
}

//ENDTODO here is sfmlMainThings

void sfmlGrap::surfaceShape::draw(sf::RenderTarget& mainTarget, sf::RenderStates states) const
{
	for (int i = 0; i < block.size(); i++)
		mainTarget.draw(block[i]);
}

sfmlGrap::surfaceShape::surfaceShape(const sf::Vector2f& entryPointPosition) {}

void sfmlGrap::surfaceShape::initSurface()
{
	static int numberOfInit = 0; //BAD Code don't write this
	numberOfInit = (numberOfInit > 5) ? 0 : numberOfInit;

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
			std::array<Colors, 9> getArray = getBlockArray(numberOfInit, matrix1, matrix2, matrix3);

			block[elementDone].setFillColor(getSfColor(getArray[elementDone])); //ERROR HERE
			block[elementDone].setSize(sf::Vector2f(50, 50));
			block[elementDone].setPosition(allPositionsOfBlocks[elementDone]);
			elementDone++;
		}
	}
	numberOfInit++;
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
		sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y + 180), //dol
		sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y), //srodek
		sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y - 180), //gora

		sf::Vector2f(entrySurfacePoint.x - 360, entrySurfacePoint.y), //lewo 2
		sf::Vector2f(entrySurfacePoint.x - 180, entrySurfacePoint.y), //lewo 1
		
		sf::Vector2f(entrySurfacePoint.x + 180, entrySurfacePoint.y), //po prawej
		
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
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				LPrimDo(matrix1, matrix2, matrix3);
				std::cout << "123" << std::endl;
				for (int i = 0; i < 6; i++)
					mainRubicSurafes[i].initSurface();
			}
		}

		RW->clear(sf::Color::Black);

		for (int i = 0; i < 6; i++)
			RW->draw(mainRubicSurafes[i]);

		RW->display();
	}
}
