#pragma once
#include "libs.h"
#include "sfmlCubeInstructions.h"

class selectingSurfaceEngine : public sf::Drawable
{
private:
	sf::RectangleShape selectedIndexShape;

	void renderBox();

	unsigned int positionIndex = 0;

	virtual void draw(sf::RenderTarget& mainTarget, sf::RenderStates states) const;

public:
	void changeSelectBox(const sf::Keyboard::Key keyPressed);
	selectingSurfaceEngine();
};