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

	surfaceText.setFont("mainFont.otf");
	surfaceText.setText("Surface: 0");

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
		using rubicInstructions::reverseRubicMoveVectorAdd;
		using rubicInstructions::RubicMatrix;

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
				toReverseFunc = executeForSurface(mainSelector.getPositionIndex(), rubicEnum::FMoveDo, matrix1, matrix2, matrix3, toReverseFunc);
				reverseRubicMoveVectorAdd(movesCollection, toReverseFunc);
				break;
			case sf::Keyboard::R:
				toReverseFunc = executeForSurface(mainSelector.getPositionIndex(), rubicEnum::FPrimDo, matrix1, matrix2, matrix3, *toReverseFunc);
				reverseRubicMoveVectorAdd(movesCollection, toReverseFunc);
				break;
			
			case sf::Keyboard::L:
				toReverseFunc = executeForSurface(mainSelector.getPositionIndex(), rubicEnum::LMoveDo, matrix1, matrix2, matrix3, toReverseFunc);
				reverseRubicMoveVectorAdd(movesCollection, toReverseFunc);
				break;
			case sf::Keyboard::O:
				toReverseFunc = executeForSurface(mainSelector.getPositionIndex(), rubicEnum::LPrimDo, matrix1, matrix2, matrix3, toReverseFunc);
				reverseRubicMoveVectorAdd(movesCollection, toReverseFunc);
				break;

			case sf::Keyboard::N:
				toReverseFunc = executeForSurface(mainSelector.getPositionIndex(), rubicEnum::UMoveDo, matrix1, matrix2, matrix3, toReverseFunc);
				reverseRubicMoveVectorAdd(movesCollection, toReverseFunc);
				break;
			case sf::Keyboard::M:
				toReverseFunc = executeForSurface(mainSelector.getPositionIndex(), rubicEnum::UPrimDo, matrix1, matrix2, matrix3, toReverseFunc);
				reverseRubicMoveVectorAdd(movesCollection, toReverseFunc);
				break;

			case sf::Keyboard::X:
				toReverseFunc = executeForSurface(mainSelector.getPositionIndex(), rubicEnum::RMoveDo, matrix1, matrix2, matrix3, toReverseFunc);
				reverseRubicMoveVectorAdd(movesCollection, toReverseFunc);

				break;
			case sf::Keyboard::C:
				toReverseFunc = executeForSurface(mainSelector.getPositionIndex(), rubicEnum::RPrimDo, matrix1, matrix2, matrix3, toReverseFunc);
				reverseRubicMoveVectorAdd(movesCollection, toReverseFunc);
				break;

			case sf::Keyboard::A:
				toReverseFunc = executeForSurface(mainSelector.getPositionIndex(), rubicEnum::DMoveDo, matrix1, matrix2, matrix3, toReverseFunc);
				reverseRubicMoveVectorAdd(movesCollection, toReverseFunc);
				break;
			case sf::Keyboard::S:
				toReverseFunc = executeForSurface(mainSelector.getPositionIndex(), rubicEnum::DPrimDo, matrix1, matrix2, matrix3, toReverseFunc);
				reverseRubicMoveVectorAdd(movesCollection, toReverseFunc);
				break;
			case sf::Keyboard::Q:
				toReverseFunc = executeForSurface(mainSelector.getPositionIndex(), rubicEnum::BMoveDo, matrix1, matrix2, matrix3, toReverseFunc);
				reverseRubicMoveVectorAdd(movesCollection, toReverseFunc);
				break;
			case sf::Keyboard::W:
				toReverseFunc = executeForSurface(mainSelector.getPositionIndex(), rubicEnum::BPrimDo, matrix1, matrix2, matrix3, toReverseFunc);
				reverseRubicMoveVectorAdd(movesCollection, toReverseFunc);
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
			{
				static int lastIndex = 0;

				if (mainSelector.getVisibility() == true && lastIndex != mainSelector.getPositionIndex())
				{
					surfaceText.setText("Surface: "+ std::to_string(mainSelector.getPositionIndex()));
					lastIndex = mainSelector.getPositionIndex();

					//mainRubicSurafes[4].rotateSurface(90);

					//rubicInstructions::entryPointPositions rubicVecs(mainSelector.getPositionIndex());
					//for (int i = 0; i < 6; i++)
					//{
					//	
					//	mainRubicSurafes[i].setEntryPointPosition(rubicVecs.myRubicSurfacePositions[i]);
					//	mainRubicSurafes[i].initSurface();
					//}

				}

				mainSelector.setVisible(false);
				break;
			}
			case sf::Keyboard::BackSpace:

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

		RW->draw(surfaceText);

		RW->display();
	}
}

sfmlGrap::mainSFMLVis::~mainSFMLVis()
{
	delete RW;
}