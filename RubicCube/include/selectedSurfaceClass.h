#pragma once
#include "libs.h"
#include "rubicElementClass.h"

namespace sfmlGrap
{
	class selectedSurface : public sf::Drawable
	{
	private:
		sf::RectangleShape selectedSurfaceShape;
		int positionIndex = 0;

		void initPosition();

		virtual void draw(sf::RenderTarget& mainTarget, sf::RenderStates states) const;

	public:
		enum KEYS
		{
			NONE = -1, LEFT, UP, DOWN, RIGHT
		};

		selectedSurface();

		void setPosition(const sf::Vector2f mainVec);

		void moveSelectedBox(const KEYS& mainKey);

		
	};
}
