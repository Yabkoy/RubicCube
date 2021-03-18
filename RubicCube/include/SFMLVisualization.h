#pragma once
#include "rubicElementClass.h"
#include "ShapeSurfaceClass.h"
#include "selectedSurfaceClass.h"

namespace sfmlGrap
{
	class mainSFMLVis
	{
		private:
			sf::RenderWindow* RW;
			sf::Event mainEvent;

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
