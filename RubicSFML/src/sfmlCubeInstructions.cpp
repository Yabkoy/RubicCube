#include "../include/sfmlCubeInstructions.h"


sf::Color getSfColor(const rc::Colors& thisCol)
{
	switch (thisCol)
	{
	case rc::NONE:
		return sf::Color::Black;
		break;
	case rc::GREEN:
		return sf::Color::Green;
		break;
	case rc::YELLOW:
		return sf::Color::Yellow;
		break;
	case rc::BLUE:
		return sf::Color::Blue;
		break;
	case rc::ORANGE:
		return sf::Color(255, 165, 0);
		break;
	case rc::WHITE:
		return sf::Color::White;
		break;
	case rc::RED:
		return sf::Color::Red;
		break;
	default:
		return sf::Color::Black;
		break;
	}
}
