#include "../include/selectingSurfaceEngine.h"


void selectingSurfaceEngine::renderBox()
{
	selectedIndexShape.setPosition(allPositionOfBlocks[positionIndex]);
}

void selectingSurfaceEngine::changeSelectBox(const sf::Keyboard::Key keyPressed)
{
	switch (keyPressed)
	{
		case sf::Keyboard::Left:
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
		case sf::Keyboard::Right:
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
		break;

		case sf::Keyboard::Up:
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
		break;

		case sf::Keyboard::Down:
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
		break;
	}
	renderBox();
}

selectingSurfaceEngine::selectingSurfaceEngine()
{
	selectedIndexShape.setSize(sf::Vector2f(150, 150));
	selectedIndexShape.setOutlineThickness(2);
	selectedIndexShape.setOrigin(sf::Vector2f((selectedIndexShape.getSize().x / 2)-20, (selectedIndexShape.getSize().y / 2)-20 ) );
	selectedIndexShape.setFillColor(sf::Color(0, 0, 0, 0));
	selectedIndexShape.setOutlineColor(sf::Color::Red);

}

void selectingSurfaceEngine::draw(sf::RenderTarget& mainTarget, sf::RenderStates states) const
{
	mainTarget.draw(selectedIndexShape);
}