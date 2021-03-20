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

			int positionIndex = 0;

			surfaceShape mainRubicSurafes[6];
			selectedSurface mainSelector;
	private:
			std::vector<void(*)(rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*) > movesCollection;
			void (*toReverseFunc)(rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*);
			int testIndex = 0;
	private:
			void executeStateInitialization();

			void executePollEvent(sf::Event& myEvent);
			void mainUpdateLoop();
		public:
			mainSFMLVis();
			~mainSFMLVis();
	};
}
