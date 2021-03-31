#pragma once
#include "libs.h"
#include "sfmlCubeInstructions.h"

class oneCubeSurface : public sf::Drawable
{
private:
	sf::RectangleShape blocks[9];
	std::array<rc::Colors, 9> nowSurface;

	static sf::Vector2f allOriginOfBlocks[9];

	sf::Vector2f surfacePosition;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void setMainSurfaceDisplaying(const int& surfaceIndex);

public:

	oneCubeSurface(const int& surfaceIndex, const sf::Vector2f& position);

	void setDisplayingSurface(const int& surfaceIndex);
};