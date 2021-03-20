#pragma once
#include "libs.h"
#include "rubicElementClass.h"
namespace sfmlGrap
{
	class surfaceShape : public sf::Drawable
	{
	private:
		std::array<sf::RectangleShape, 9> block;

		sf::Vector2f entryPointPosition;


		virtual void draw(sf::RenderTarget& mainTarget, sf::RenderStates states) const;

	public:
		surfaceShape(const sf::Vector2f& entryPointPosition = sf::Vector2f(0, 0));

		void initSurface();
		void setEntryPointPosition(const sf::Vector2f& epp);

		void rotateSurface(const float& angle);
	};
}