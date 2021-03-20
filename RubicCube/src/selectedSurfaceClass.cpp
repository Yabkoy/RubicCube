#include "../include/selectedSurfaceClass.h"

void sfmlGrap::selectedSurface::initPosition()
{
	rubicInstructions::entryPointPositions rubicVecs(positionIndex);
	//std::cout << positionIndex << std::endl;
	//std::cout << rubicVecs.myRubicSurfacePositions[positionIndex].x + 25 << " - " << rubicVecs.myRubicSurfacePositions[positionIndex].y + 25 << std::endl;
	selectedSurfaceShape.setPosition(rubicVecs.myRubicSurfacePositions[positionIndex].x + 25, rubicVecs.myRubicSurfacePositions[positionIndex].y + 25);

}


void sfmlGrap::selectedSurface::draw(sf::RenderTarget& mainTarget, sf::RenderStates states) const
{
	mainTarget.draw(selectedSurfaceShape);
}

sfmlGrap::selectedSurface::selectedSurface()
{
	selectedSurfaceShape.setSize(sf::Vector2f(190, 190));
	selectedSurfaceShape.setOrigin(sf::Vector2f(selectedSurfaceShape.getSize().x / 2, selectedSurfaceShape.getSize().y / 2));
	selectedSurfaceShape.setOutlineThickness(1);
	selectedSurfaceShape.setOutlineColor(sf::Color::Green);
	selectedSurfaceShape.setFillColor(sf::Color(0, 0, 0, 0));

	initPosition();
}

void sfmlGrap::selectedSurface::setPosition(const sf::Vector2f mainVec)
{
	selectedSurfaceShape.setPosition(mainVec);
}

int sfmlGrap::selectedSurface::moveSelectedBox(const KEYS& mainKey)
{

	bool executeCommand = true;

	setVisible(true);

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
			else
			{
				executeCommand = false;
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
			else
			{
				executeCommand = false;
			}
			break;
		case UP:
			if (positionIndex != 2)
			{
				if (positionIndex == 4 || positionIndex == 5 || positionIndex == 0)
				{
					positionIndex = 1;
				}
				else
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
			else
			{
				executeCommand = false;
			}
			break;

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
			else
			{
				executeCommand = false;
			}
			break;
		default:
			executeCommand = false;
			break;
	}
	if (executeCommand == true)
		initPosition();
	
	return positionIndex;
}

void sfmlGrap::selectedSurface::setVisible(const bool& value)
{
	if (value == true)
	{
		selectedSurfaceShape.setOutlineThickness(4);
		selectedSurfaceShape.setOutlineColor(sf::Color::Red);
	}
	else
	{
		selectedSurfaceShape.setOutlineThickness(1);
		selectedSurfaceShape.setOutlineColor(sf::Color::Green);
	}

}

bool sfmlGrap::selectedSurface::getVisibility() const
{
	return (selectedSurfaceShape.getOutlineThickness() == 0) ? false : true;
}

int sfmlGrap::selectedSurface::getPositionIndex() const
{
	return positionIndex;
}