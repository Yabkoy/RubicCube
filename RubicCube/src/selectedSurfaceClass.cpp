#include "../include/selectedSurfaceClass.h"

void sfmlGrap::selectedSurface::initPosition()
{

}


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
	bool executeCommand = true;

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
			else
			{
				executeCommand = false;
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
			else
			{
				executeCommand = false;
			}
		default:
			executeCommand = false;
			break;
	}


}