#include "../include/oneCubeSurface.h"

void oneCubeSurface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < 9; i++)
		target.draw(blocks[i]);
}


oneCubeSurface::oneCubeSurface(const int& surfaceIndex, const sf::Vector2f& position)
{
	std::array<rc::Colors, 9> nowSurface = rc::getRubicSurfaceNumber(surfaceIndex, rc::matrixes::matrix1, rc::matrixes::matrix2, rc::matrixes::matrix3);

	for (int i = 0; i < 9; i++)
	{
		blocks[i].setPosition(position);
		blocks[i].setOrigin(allOriginOfBlocks[i]);
		blocks[i].setSize(sf::Vector2f(40, 40));
		blocks[i].setFillColor(getSfColor(nowSurface[i]));
	}
}
	