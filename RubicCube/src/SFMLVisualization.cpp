#include "../include/SFMLVisualization.h"

void sfmlGrap::mainSFMLVis::executeStateInitialization(const std::string& message)
{
	std::cout << message << std::endl;
	for (int i = 0; i < 6; i++)
		mainRubicSurafes[i].initSurface();
}

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
			using namespace rubicInstructions::rubicMatrixesArray;
			
			std::array<Colors, 9> getArray = rubicInstructions::getRubicSurfaceArray(numberOfInit, matrix1, matrix2, matrix3);

			block[elementDone].setFillColor(rubicInstructions::getSfColor(getArray[elementDone])); //ERROR HERE
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

	RW->setVerticalSyncEnabled(true);

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


void sfmlGrap::mainSFMLVis::executePollEvent(sf::Event& mainEvent)
{
	switch (mainEvent.type)
	{
		using namespace rubicInstructions::rubicMoves;
		using namespace rubicInstructions::rubicMatrixesArray;
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
				case sf::Keyboard::F:
					FMoveDo(matrix1);
					executeStateInitialization("F Move");
					break;
				case sf::Keyboard::R:
					FPrimDo(matrix1);
					executeStateInitialization("F Prim Do");
					break;
				case sf::Keyboard::L:
					LMoveDo(matrix1, matrix2, matrix3);
					executeStateInitialization("L Move");
					break;
				case sf::Keyboard::O:
					LPrimDo(matrix1, matrix2, matrix3);
					executeStateInitialization("L Prim Move");
					break;
				case sf::Keyboard::N:
					UMoveDo(matrix1, matrix2, matrix3);
					executeStateInitialization("U Move");
					break;
				case sf::Keyboard::M:
					UPrimDo(matrix1, matrix2, matrix3);
					executeStateInitialization("U Prim Move");
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
			RW->draw(mainRubicSurafes[i]);

		RW->display();
	}
}

sfmlGrap::mainSFMLVis::~mainSFMLVis()
{
	delete RW;
}