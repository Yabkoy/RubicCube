#include "../include/SFMLVisualization.h"

void sfmlGrap::mainSFMLVis::executeStateInitialization()
{
	for (int i = 0; i < 6; i++)
		mainRubicSurafes[i].initSurface();
}

sfmlGrap::mainSFMLVis::mainSFMLVis()
{
	RW = new sf::RenderWindow(sf::VideoMode(WINDOW_W, WINDOW_H, 32), "Rubic Cube");

	rubicInstructions::entryPointPositions rubicVecs;

	RW->setVerticalSyncEnabled(true);

	for (int i = 0; i < 6; i++)
	{
		mainRubicSurafes[i].setEntryPointPosition(rubicVecs.myRubicSurfacePositions[i]);
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
		RW->draw(mainSelector);

		RW->display();
	}
}

sfmlGrap::mainSFMLVis::~mainSFMLVis()
{
	delete RW;
}