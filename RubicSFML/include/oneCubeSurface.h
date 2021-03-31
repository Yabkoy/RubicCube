#pragma once
#include "libs.h"
#include "sfmlCubeInstructions.h"

class oneCubeSurface : public sf::Drawable
{
private:
	sf::RectangleShape blocks[9];

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	oneCubeSurface(const int& surfaceIndex, const sf::Vector2f& position);
};