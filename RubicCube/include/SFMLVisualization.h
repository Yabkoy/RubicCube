#pragma once
#include "rubicElementClass.h"
#include "ShapeSurfaceClass.h"

namespace sfmlGrap
{
	class selectedSurface : public sf::Drawable
	{
		private:
			sf::RectangleShape selectedSurfaceShape;
			int positionIndex;

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


	class mainSFMLVis
	{
		private:
			sf::RenderWindow* RW;
			sf::Event mainEvent;

			sf::Vector2f entrySurfacePoint;
			sf::Vector2f myRubicSurfacePositions[6];

			surfaceShape mainRubicSurafes[6];
			selectedSurface mainSelector;

			void executeStateInitialization();

			void executePollEvent(sf::Event& myEvent);
			void mainUpdateLoop();
		public:
			mainSFMLVis();
			~mainSFMLVis();
	};
}
