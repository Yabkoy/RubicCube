#pragma once
#include "libs.h"

namespace sfmlGrap
{
	class surfaceShape : public sf::Drawable
	{
	private:
		sf::RectangleShape testRS;

		virtual void draw(sf::RenderTarget& mainTarget, sf::RenderStates states) const;
	public:
		surfaceShape();
	};


	class mainSFMLVis
	{
		private:
			sf::RenderWindow* RW;
			sf::Event mainEvent;
			surfaceShape testSH;

			void mainUpdateLoop();
		public:
			mainSFMLVis();
			~mainSFMLVis();
	};
}
