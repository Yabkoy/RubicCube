#pragma once
#include "libs.h"

struct ThreeElementBlock
{
	ThreeElementBlock(const Colors& b1 = Colors::NONE, const Colors& b2 = Colors::NONE, const Colors& b3 = Colors::NONE) : b1(b1), b2(b2), b3(b3) {}

	Colors b1;
	Colors b2;
	Colors b3;

	sf::Color getSfColor(const Colors& thisCol);

};
typedef ThreeElementBlock RubicMatrix;