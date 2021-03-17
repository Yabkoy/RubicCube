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

std::string getStringNamFromRubicElemnt(const Colors& element)
{
	switch (element)
	{
	case GREEN:
		return  "GREEN";
		break;
	case YELLOW:
		return  "YELLOW";
		break;
	case BLUE:
		return  "BLUE";
		break;
	case ORANGE:
		return  "ORANGE";
		break;
	case WHITE:
		return  "WHITE";
		break;
	case RED:
		return  "RED";
		break;
	default:
		return  "NONE";
		break;
	}
}

std::array<Colors, 9> getRubicSurfaceArray(const int& surfaceIndex, const RubicMatrix* rm1, const RubicMatrix* rm2, const RubicMatrix* rm3)
{

	std::array<Colors, 9> returnTypes;
	switch (surfaceIndex)
	{
	case 0: //DEF ORANGE
	{
		returnTypes[0] = rm1[0].b3;
		returnTypes[1] = rm1[1].b2;
		returnTypes[2] = rm1[2].b1;

		returnTypes[3] = rm1[3].b2;
		returnTypes[4] = rm1[4].b1;
		returnTypes[5] = rm1[5].b1;

		returnTypes[6] = rm1[6].b3;
		returnTypes[7] = rm1[7].b1;
		returnTypes[8] = rm1[8].b1;
		break;
	}
	case 1: //DEF YELLOW
	{
		returnTypes[0] = rm3[0].b2;
		returnTypes[1] = rm3[1].b1;
		returnTypes[2] = rm3[2].b2;

		returnTypes[3] = rm2[0].b1;
		returnTypes[4] = rm2[1].b1;
		returnTypes[5] = rm2[2].b1;

		returnTypes[6] = rm1[0].b2;
		returnTypes[7] = rm1[1].b1;
		returnTypes[8] = rm1[2].b2;

		break;
	}
	case 2: //DEF RED
	{
		returnTypes[8] = rm3[2].b3;
		returnTypes[7] = rm3[1].b2;
		returnTypes[6] = rm3[0].b1;

		returnTypes[5] = rm3[5].b2;
		returnTypes[4] = rm3[4].b1;
		returnTypes[3] = rm3[3].b1;

		returnTypes[2] = rm3[8].b3;
		returnTypes[1] = rm3[7].b1;
		returnTypes[0] = rm3[6].b1;
		break;
	}
	case 3: //DEF WHITE
	{
		returnTypes[0] = rm1[6].b2;
		returnTypes[1] = rm1[7].b2;
		returnTypes[2] = rm1[8].b2;

		returnTypes[3] = rm2[6].b2;
		returnTypes[4] = rm2[7].b1;
		returnTypes[5] = rm2[8].b2;
		returnTypes[6] = rm3[6].b2;
		returnTypes[7] = rm3[7].b2;
		returnTypes[8] = rm3[8].b2;
		break;
	}
	case 4: //DEF GREEN
	{
		returnTypes[0] = rm3[0].b3;
		returnTypes[1] = rm2[0].b2;
		returnTypes[2] = rm1[0].b1;

		returnTypes[3] = rm3[3].b2;
		returnTypes[4] = rm2[3].b1;
		returnTypes[5] = rm1[3].b1;

		returnTypes[6] = rm3[6].b3;
		returnTypes[7] = rm2[6].b1;
		returnTypes[8] = rm1[6].b1;

		break;
	}
	case 5: //DEF BLUE
	{
		returnTypes[0] = rm1[2].b3;
		returnTypes[1] = rm2[2].b2;
		returnTypes[2] = rm3[2].b1;

		returnTypes[3] = rm1[5].b2;
		returnTypes[4] = rm2[5].b1;
		returnTypes[5] = rm3[5].b1;

		returnTypes[6] = rm1[8].b3;
		returnTypes[7] = rm2[8].b1;
		returnTypes[8] = rm3[8].b1;
		break;
	}
	default:
		break;
	}

	return returnTypes;
}

namespace rubicMoves
{
	void LPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
	{
		RubicMatrix nowStatematrix1[9];
		RubicMatrix nowStatematrix2[9];
		RubicMatrix nowStatematrix3[9];

		// Array Copy Statement ---------------
		for (int i = 0; i < 9; i++)
			nowStatematrix1[i] = matrix1[i];
		for (int i = 0; i < 9; i++)
			nowStatematrix2[i] = matrix2[i];
		for (int i = 0; i < 9; i++)
			nowStatematrix3[i] = matrix3[i];
		// ------------------------------------

		matrix1[0].b3 = nowStatematrix1[6].b2;
		matrix1[3].b2 = nowStatematrix2[6].b2;
		matrix1[6].b3 = nowStatematrix3[6].b2;

		matrix1[0].b2 = nowStatematrix1[6].b3;
		matrix2[0].b1 = nowStatematrix1[3].b2;
		matrix3[0].b2 = nowStatematrix1[0].b3;

		matrix3[0].b1 = nowStatematrix1[0].b2;
		matrix3[3].b1 = nowStatematrix2[0].b1;
		matrix3[6].b1 = nowStatematrix3[0].b2;

		matrix1[6].b2 = nowStatematrix3[6].b1;
		matrix2[6].b2 = nowStatematrix3[3].b1;
		matrix3[6].b2 = nowStatematrix3[0].b1;

		// ===================================

		matrix1[0].b1 = nowStatematrix1[6].b1;
		matrix2[0].b2 = nowStatematrix1[3].b1;
		matrix3[0].b3 = nowStatematrix1[0].b1;

		matrix1[3].b1 = nowStatematrix2[6].b1;
		matrix3[3].b2 = nowStatematrix2[0].b2;

		matrix1[6].b1 = nowStatematrix3[6].b3;
		matrix2[6].b1 = nowStatematrix3[3].b2;
		matrix3[6].b3 = nowStatematrix3[0].b3;
	}
	void LMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
	{
		for (int i = 0; i < 3; i++)
			LPrimDo(matrix1, matrix2, matrix3);
	}

	void FMoveDo(RubicMatrix* matrix1)
	{
		RubicMatrix nowStatematrix1[9];

		// Array Copy Statement ---------------
		for (int i = 0; i < 9; i++)
			nowStatematrix1[i] = matrix1[i];

		// ------------------------------------

		matrix1[6].b1 = nowStatematrix1[0].b2;
		matrix1[3].b1 = nowStatematrix1[1].b1;
		matrix1[0].b1 = nowStatematrix1[2].b2;

		matrix1[0].b2 = nowStatematrix1[2].b3;
		matrix1[1].b1 = nowStatematrix1[5].b2;
		matrix1[2].b2 = nowStatematrix1[8].b3;

		matrix1[2].b3 = nowStatematrix1[8].b2;
		matrix1[5].b2 = nowStatematrix1[7].b2;
		matrix1[8].b3 = nowStatematrix1[6].b2;

		matrix1[8].b2 = nowStatematrix1[6].b1;
		matrix1[7].b2 = nowStatematrix1[3].b1;
		matrix1[6].b2 = nowStatematrix1[0].b1;



		matrix1[0].b3 = nowStatematrix1[2].b1;
		matrix1[1].b2 = nowStatematrix1[5].b1;
		matrix1[2].b1 = nowStatematrix1[8].b1;

		matrix1[5].b1 = nowStatematrix1[7].b1;
		matrix1[8].b1 = nowStatematrix1[6].b3;
		matrix1[7].b1 = nowStatematrix1[3].b2;

		matrix1[6].b3 = nowStatematrix1[0].b3;
		matrix1[3].b2 = nowStatematrix1[1].b2;
	}
	void FPrimDo(RubicMatrix* matrix1)
	{
		for (int i = 0; i < 3; i++)
			FMoveDo(matrix1);
	}
}