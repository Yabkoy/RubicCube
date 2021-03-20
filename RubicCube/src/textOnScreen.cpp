#include "../include/textOnScreen.h"

void textOnScreen::draw(sf::RenderTarget& mainTarget, sf::RenderStates states) const
{
	mainTarget.draw(mainText);
}


void textOnScreen::loadFont(const std::string& font)
{
	if (!mainFont.loadFromFile(font))
		std::cout << "Can't load font!" << std::endl;
	mainText.setFont(mainFont);
}


textOnScreen::textOnScreen() {}

void textOnScreen::setText(const std::string& text)
{
	mainText.setString(text);
}
void textOnScreen::setFont(const std::string& font)
{
	loadFont(font);
}