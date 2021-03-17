#pragma once
#include "libs.h"

namespace rubicInstructions
{
	sf::Color getSfColor(const Colors& thisCol);

	std::string getStringNamFromRubicElemnt(const Colors& element);

	struct ThreeElementBlock
	{
		ThreeElementBlock(const Colors& b1 = Colors::NONE, const Colors& b2 = Colors::NONE, const Colors& b3 = Colors::NONE) : b1(b1), b2(b2), b3(b3) {}

		Colors b1;
		Colors b2;
		Colors b3;
	};
	typedef ThreeElementBlock RubicMatrix;

	std::array<Colors, 9> getRubicSurfaceArray(const int& surfaceIndex, const RubicMatrix* rm1, const RubicMatrix* rm2, const RubicMatrix* rm3);

	namespace rubicBlocksArray
	{
		extern ThreeElementBlock AR1[6];

		extern ThreeElementBlock AR2[12];

		extern ThreeElementBlock AR3[8];

	};

	namespace rubicMatrixesArray
	{
		extern RubicMatrix matrix1[9];
		extern RubicMatrix matrix2[9];
		extern RubicMatrix matrix3[9];
	};

	namespace rubicMoves
	{
		void LPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
		void LMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);

		void FMoveDo(RubicMatrix* matrix1);
		void FPrimDo(RubicMatrix* matrix1);

		void UMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
		void UPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
	};
};
