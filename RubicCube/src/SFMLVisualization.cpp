#include "../include/SFMLVisualization.h"

void sfmlGrap::mainSFMLVis::executeStateInitialization()
{
	for (int i = 0; i < 6; i++)
		mainRubicSurafes[i].initSurface();
}


//-- OtherClass

void sfmlGrap::selectedSurface::draw(sf::RenderTarget& mainTarget, sf::RenderStates states) const
{
	mainTarget.draw(selectedSurfaceShape);
}

sfmlGrap::selectedSurface::selectedSurface()
{
	selectedSurfaceShape.setSize(sf::Vector2f(190, 190));
	selectedSurfaceShape.setOrigin(sf::Vector2f(selectedSurfaceShape.getSize().x / 2, selectedSurfaceShape.getSize().y / 2));
	selectedSurfaceShape.setOutlineColor(sf::Color::Red);
	selectedSurfaceShape.setOutlineThickness(4);
	selectedSurfaceShape.setFillColor(sf::Color(0, 0, 0, 0));
	//selectedSurfaceShape.setPosition(myRubicSurfacePositions[0].x + 26, myRubicSurfacePositions[0].y + 26);
}

void sfmlGrap::selectedSurface::setPosition(const sf::Vector2f mainVec)
{
	selectedSurfaceShape.setPosition(mainVec);
}

void sfmlGrap::selectedSurface::moveSelectedBox(const KEYS& mainKey)
{
	//ORANGE 0
	//YELLOW 1
	//RED 2
	//WHITE 3
	//GREEN 4 
	//BLUE 5
	switch (mainKey)
	{
	case LEFT:
		if (positionIndex != 4)
		{
			if (positionIndex == 5)
			{
				positionIndex = 0;
			}
			else
			{
				positionIndex = 4;
			}
		}
		break;
	case RIGHT:
		if (positionIndex != 5)
		{
			if (positionIndex == 4)
			{
				positionIndex = 0;
			}
			else
			{
				positionIndex = 5;
			}
		}
	case UP:
		if (positionIndex != 2)
		{
			if (positionIndex == 4 || positionIndex == 5 || positionIndex == 0)
				positionIndex = 1;
			{
				switch (positionIndex)
				{
				case 3:
					positionIndex = 0;
					break;
				case 1:
					positionIndex = 2;
					break;
				}
			}
		}
	case DOWN:
		if (positionIndex != 3)
		{
			if (positionIndex == 4 || positionIndex == 5 || positionIndex == 0)
				positionIndex = 3;
			{
				switch (positionIndex)
				{
				case 1:
					positionIndex = 0;
					break;
				case 2:
					positionIndex = 1;
					break;
				}
			}
		}
	default:
		break;
	}
}

//-- OtherClass

sfmlGrap::mainSFMLVis::mainSFMLVis()
{
	RW = new sf::RenderWindow(sf::VideoMode(WINDOW_W, WINDOW_H, 32), "Rubic Cube");

	RW->setVerticalSyncEnabled(true);

	entrySurfacePoint = sf::Vector2f((WINDOW_W / 2) - 25, (WINDOW_W / 2) - 100);

	myRubicSurfacePositions[0] = sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y + 200); //ORANGE
		myRubicSurfacePositions[1] = sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y); //YELLOW
	myRubicSurfacePositions[2] = sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y - 200); //RED
	myRubicSurfacePositions[3] = sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y + 400); //WHITE
	myRubicSurfacePositions[4] = sf::Vector2f(entrySurfacePoint.x - 200, entrySurfacePoint.y + 200); //GREEN
	myRubicSurfacePositions[5] = sf::Vector2f(entrySurfacePoint.x + 200, entrySurfacePoint.y + 200); //BLUE
			


	for (int i = 0; i < 6; i++)
	{
		mainRubicSurafes[i].setEntryPointPosition(myRubicSurfacePositions[i]);
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
					break;
				case sf::Keyboard::R:
					FPrimDo(matrix1);
					break;
				case sf::Keyboard::L:
					LMoveDo(matrix1, matrix2, matrix3);
					break;
				case sf::Keyboard::O:
					LPrimDo(matrix1, matrix2, matrix3);
					break;

				case sf::Keyboard::N:
					UMoveDo(matrix1, matrix2, matrix3);
					break;
				case sf::Keyboard::M:
					UPrimDo(matrix1, matrix2, matrix3);
					break;

				case sf::Keyboard::X:
					RMoveDo(matrix1, matrix2, matrix3);
					
					break;
				case sf::Keyboard::C:
					RPrimDo(matrix1, matrix2, matrix3);
					break;

				case sf::Keyboard::A:
					DMoveDo(matrix1, matrix2, matrix3);
					break;
				case sf::Keyboard::S:
					DPrimDo(matrix1, matrix2, matrix3);
					break;
				case sf::Keyboard::Q:
					BMoveDo(matrix3);
					break;
				case sf::Keyboard::W:
					BPrimDo(matrix3);
					break;
				// ---- KEYS TO SURFACE MOVE ----
				case sf::Keyboard::Right:
					mainSelector.moveSelectedBox(selectedSurface::KEYS::RIGHT);
					break;				
				case sf::Keyboard::Left:
					mainSelector.moveSelectedBox(selectedSurface::KEYS::LEFT);
					break;				
				case sf::Keyboard::Up:
					mainSelector.moveSelectedBox(selectedSurface::KEYS::UP);
					break;				
				case sf::Keyboard::Down:
					mainSelector.moveSelectedBox(selectedSurface::KEYS::DOWN);
					break;
			}
			break;
		}


	}
	executeStateInitialization();

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
		RW->draw(selectedSurface);

		RW->display();
	}
}

sfmlGrap::mainSFMLVis::~mainSFMLVis()
{
	delete RW;
}