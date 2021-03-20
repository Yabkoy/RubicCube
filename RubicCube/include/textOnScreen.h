#pragma once
#include "libs.h"

class textOnScreen : public sf::Drawable
{
private:
	virtual void draw(sf::RenderTarget& mainTarget, sf::RenderStates states) const;
	sf::Text mainText;
	sf::Font mainFont;

	void loadFont(const std::string& font);

public:
	textOnScreen();

	void setText(const std::string& text);
	void setFont(const std::string& font);
};