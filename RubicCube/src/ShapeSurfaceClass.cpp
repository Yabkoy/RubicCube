#include "../include/ShapeSurfaceClass.h"


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

void sfmlGrap::surfaceShape::rotateSurface(const float& angle)
{
	for(int i=0; i<block.size(); i++)
		block[i].rotate(angle);
	
}