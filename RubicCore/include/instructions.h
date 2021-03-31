#pragma once
#include "../include/libs.h"

namespace rc
{
	enum Colors : int
	{
		NONE = -1, GREEN, YELLOW, BLUE, ORANGE, WHITE, RED
	};

	struct RubicElementBlock
	{
		RubicElementBlock(const Colors& b1 = Colors::NONE, const Colors& b2 = Colors::NONE, const Colors& b3 = Colors::NONE) : b1(b1), b2(b2), b3(b3) {}

		Colors b1;
		Colors b2;
		Colors b3;
	};

	typedef RubicElementBlock RubicMatrix;

	std::string getStringNamFromRubicElemnt(const Colors& element);
	std::array<Colors, 9> getRubicSurfaceNumber(const int& surfaceIndex, const RubicMatrix* rm1, const RubicMatrix* rm2, const RubicMatrix* rm3);

	void rubicArrayCopy(RubicMatrix* source, RubicMatrix* destination, size_t size);
}
