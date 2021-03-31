#pragma once
#include "textOnScreen.h"
#include "oneCubeSurface.h"

namespace sfmlGrap
{
	class mainSFMLVis
	{
	private:
		sf::RenderWindow* RW;
		sf::Event mainEvent;

		static unsigned int selectedSurfaceIndexes[36];

		oneCubeSurface mainSurfaces[6];

	private:
		void executePollEvent(sf::Event& myEvent);
		void mainUpdateLoop();
	public:
		mainSFMLVis();
		~mainSFMLVis();
	};
}
