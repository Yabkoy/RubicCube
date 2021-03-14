#pragma once
#include "libs.h"

namespace sfmlGrap
{
	class mainSFMLVis
	{
		private:
			sf::RenderWindow* RW;
			sf::Event mainEvent;
			sf::RectangleShape RS;

			void mainUpdateLoop();
		public:
			mainSFMLVis();
			~mainSFMLVis();
	};
}
