#include "../include/oneCubeSurface.h"

void oneCubeSurface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < 9; i++)
		target.draw(blocks[i]);
}

//sf::Vector2f allPositionOfBlocks[6] =
//{
//	sf::Vector2f(WINDOW_W / 2, WINDOW_H / 2),
//	sf::Vector2f(WINDOW_W / 2, (WINDOW_H / 2) - 180),
//	sf::Vector2f(WINDOW_W / 2, (WINDOW_H / 2) - 360),
//
//	sf::Vector2f(WINDOW_W / 2, (WINDOW_H / 2) + 180),
//	sf::Vector2f(WINDOW_W / 2 - 180, (WINDOW_H / 2)),
//	sf::Vector2f(WINDOW_W / 2 + 180, (WINDOW_H / 2)),
//};
//
//sf::Vector2f allOriginOfBlocks[9] =
//{
//	sf::Vector2f(45, 45),
//	sf::Vector2f(0, 45),
//	sf::Vector2f(-45, 45),
//
//	sf::Vector2f(45, 0),
//	sf::Vector2f(0, 0),
//	sf::Vector2f(-45, 0),
//
//	sf::Vector2f(45, -45),
//	sf::Vector2f(0, -45),
//	sf::Vector2f(-45, -45),
//};


sf::Vector2f oneCubeSurface::allOriginOfBlocks[9] =
{
	sf::Vector2f(45, 45),
	sf::Vector2f(0, 45),
	sf::Vector2f(-45, 45),

	sf::Vector2f(45, 0),
	sf::Vector2f(0, 0),
	sf::Vector2f(-45, 0),

	sf::Vector2f(45, -45),
	sf::Vector2f(0, -45),
	sf::Vector2f(-45, -45),
};


void oneCubeSurface::setMainSurfaceDisplaying(const int& surfaceIndex) 
{
	nowSurface = rc::getRubicSurfaceNumber(surfaceIndex, rc::matrixes::matrix1, rc::matrixes::matrix2, rc::matrixes::matrix3);

	for (int i = 0; i < 9; i++)
	{
		blocks[i].setPosition(surfacePosition);
		blocks[i].setOrigin(allOriginOfBlocks[i]);
		blocks[i].setSize(sf::Vector2f(40, 40));
		blocks[i].setFillColor(getSfColor(nowSurface[i]));
	}
}

oneCubeSurface::oneCubeSurface(const int& surfaceIndex, const sf::Vector2f& position) : surfacePosition(position)
{
	setMainSurfaceDisplaying(surfaceIndex);
}

void oneCubeSurface::setDisplayingSurface(const int& surfaceIndex)
{
	setMainSurfaceDisplaying(surfaceIndex);
}
	