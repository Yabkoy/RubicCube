#include "../include/rubicElementClass.h"



sf::Color getSfColor(const Colors& thisCol)
{
	switch (thisCol)
	{
	case NONE:
		return sf::Color::Black;
		break;
	case GREEN:
		return sf::Color::Green;
		break;
	case YELLOW:
		return sf::Color::Yellow;
		break;
	case BLUE:
		return sf::Color::Blue;
		break;
	case ORANGE:
		return sf::Color(255, 165, 0);
		break;
	case WHITE:
		return sf::Color::White;
		break;
	case RED:
		return sf::Color::Red;
		break;
	default:
		return sf::Color::Black;
		break;
	}
}