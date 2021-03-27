#pragma once
#include "ShapeSurfaceClass.h"
#include "textOnScreen.h"
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
		textOnScreen surfaceText;

	private:
		
		std::vector<void(*)(rc::RubicMatrix*, rc::RubicMatrix*, rc::RubicMatrix*) > movesCollection;
		void (*toReverseFunc)(rc::RubicMatrix*, rc::RubicMatrix*, rc::RubicMatrix*);
	private:
		void executeStateInitialization();
		void executePollEvent(sf::Event& myEvent);
		void mainUpdateLoop();
	public:
		mainSFMLVis();
		~mainSFMLVis();
	};
}
