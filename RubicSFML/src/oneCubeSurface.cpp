#include "../include/oneCubeSurface.h"

void oneCubeSurface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < 9; i++)
		target.draw(blocks[i]);
}

oneCubeSurface::oneCubeSurface(const rc::Colors& mainCol, const sf::Vector2f& position)
{
	for (int i = 0; i < 9; i++)
	{
		blocks[i].setPosition(position);
		blocks[i].setOrigin(allOriginOfBlocks[i]);
		static int num = 0;
		std::cout << num <<". X: "<< blocks[i].getOrigin().x <<" Y: "<< blocks[i].getOrigin().y << std::endl;
		blocks[i].setFillColor(getSfColor(mainCol));
		num++;
	}
}
	