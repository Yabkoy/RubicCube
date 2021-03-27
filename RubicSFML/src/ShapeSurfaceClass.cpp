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

	for (int i = 0; i < 9; i++)
		block[i].setPosition(entryPointPosition);

	sf::Vector2f allOriginOfBlocks[9] =
	{
		sf::Vector2f(elementPadding, elementPadding),
		sf::Vector2f(0, elementPadding),
		sf::Vector2f(-elementPadding, elementPadding),

		sf::Vector2f(elementPadding, 0),
		sf::Vector2f(0, 0),
		sf::Vector2f(-elementPadding, 0),

		sf::Vector2f(elementPadding, -elementPadding),
		sf::Vector2f(0, -elementPadding),
		sf::Vector2f(-elementPadding, -elementPadding),
	};

	int elementDone = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			
			using namespace rc::matrixes;

			std::array<rc::Colors, 9> getArray = rc::getRubicSurfaceArray(numberOfInit, matrix1, matrix2, matrix3);

			block[elementDone].setFillColor(getSfColor(getArray[elementDone])); //ERROR HERE
			block[elementDone].setSize(sf::Vector2f(50, 50));
			block[elementDone].setOrigin(allOriginOfBlocks[elementDone].x + 25, allOriginOfBlocks[elementDone].y + 25);
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
	for (int i = 0; i < block.size(); i++)
		block[i].rotate(angle);

}

void sfmlGrap::surfaceShape::setSurfacePosition(const sf::Vector2f& position)
{
	for (int i = 0; i < block.size(); i++)
		block[i].setPosition(position);
}