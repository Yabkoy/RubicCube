#include "../include/SFMLVisualization.h"

void sfmlGrap::mainSFMLVis::executeStateInitialization()
{
	for (int i = 0; i < 6; i++)
	{
		rubicInstructions::entryPointPositions rubicVecs(positionIndex);
		mainRubicSurafes[i].setEntryPointPosition(rubicVecs.myRubicSurfacePositions[i]);
		mainRubicSurafes[i].initSurface();
	}
}

sfmlGrap::mainSFMLVis::mainSFMLVis()
{
	RW = new sf::RenderWindow(sf::VideoMode(WINDOW_W, WINDOW_H, 32), "Rubic Cube");

	rubicInstructions::entryPointPositions rubicVecs(positionIndex);

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
	static std::vector<void(*)(rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*) > movesCollection;

	switch (mainEvent.type)
	{
		using namespace rubicInstructions::rubicMoves;
		using namespace rubicInstructions::rubicMatrixesArray;
		using rubicInstructions::reverseRubicMoveVectorAdd;

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
					FMoveDo(matrix1, matrix2, matrix3);
					reverseRubicMoveVectorAdd(movesCollection, FMoveDo);
					break;
				case sf::Keyboard::R:
					FPrimDo(matrix1, matrix2, matrix3);
					reverseRubicMoveVectorAdd(movesCollection, FPrimDo);
					break;
				case sf::Keyboard::L:
					LMoveDo(matrix1, matrix2, matrix3);
					reverseRubicMoveVectorAdd(movesCollection, LMoveDo);
					break;
				case sf::Keyboard::O:
					LPrimDo(matrix1, matrix2, matrix3);
					reverseRubicMoveVectorAdd(movesCollection, LPrimDo);
					break;

				case sf::Keyboard::N:
					UMoveDo(matrix1, matrix2, matrix3);
					reverseRubicMoveVectorAdd(movesCollection, UMoveDo);
					break;
				case sf::Keyboard::M:
					UPrimDo(matrix1, matrix2, matrix3);
					reverseRubicMoveVectorAdd(movesCollection, UPrimDo);
					break;

				case sf::Keyboard::X:
					RMoveDo(matrix1, matrix2, matrix3);
					reverseRubicMoveVectorAdd(movesCollection, RMoveDo);
					
					break;
				case sf::Keyboard::C:
					RPrimDo(matrix1, matrix2, matrix3);
					reverseRubicMoveVectorAdd(movesCollection, RPrimDo);
					break;

				case sf::Keyboard::A:
					DMoveDo(matrix1, matrix2, matrix3);
					reverseRubicMoveVectorAdd(movesCollection, DMoveDo);
					break;
				case sf::Keyboard::S:
					DPrimDo(matrix1, matrix2, matrix3);
					reverseRubicMoveVectorAdd(movesCollection, DPrimDo);
					break;
				case sf::Keyboard::Q:
					BMoveDo(matrix1, matrix2, matrix3);
					reverseRubicMoveVectorAdd(movesCollection, BMoveDo);
					break;
				case sf::Keyboard::W:
					BPrimDo(matrix1, matrix2, matrix3);
					reverseRubicMoveVectorAdd(movesCollection, BPrimDo);
					break;
				// ---- RANDOM KEY EXECUTE ----
				case sf::Keyboard::T:
				{
					//for(int i=0; i<20; i++)
					void(*nowMove)(rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*) = allMovesArrayPointers[rand() % 12];
					reverseRubicMoveVectorAdd(movesCollection, nowMove);
					nowMove(matrix1, matrix2, matrix3);

					break;
				}

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
				case sf::Keyboard::Enter:

					if (movesCollection.size() != 0)
					{
						(*movesCollection[movesCollection.size() - 1])(matrix1, matrix2, matrix3);
						movesCollection.erase(movesCollection.end() - 1);
					}

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