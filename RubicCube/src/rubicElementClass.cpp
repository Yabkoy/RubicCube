#include "../include/rubicElementClass.h"


namespace rubicInstructions
{
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
			//ERROR HERE
			break;
		}

		return returnTypes;
	}

	namespace rubicBlocksArray
	{
		ThreeElementBlock AR1[6] =
		{
			YELLOW, BLUE, RED, GREEN, ORANGE, WHITE,
		};

		ThreeElementBlock AR2[12] =
		{
			{YELLOW, BLUE}, {YELLOW, RED}, {YELLOW, GREEN}, {YELLOW, ORANGE},
			{BLUE, RED}, {RED, GREEN}, {GREEN, ORANGE}, {ORANGE, BLUE},
			{BLUE, WHITE}, {RED, WHITE}, {GREEN, WHITE}, {ORANGE, WHITE},
		};

		ThreeElementBlock AR3[8] =
		{
			{BLUE, YELLOW, RED}, {RED, YELLOW, GREEN}, {GREEN, YELLOW, ORANGE}, {ORANGE, YELLOW, BLUE},
			{BLUE, WHITE, RED}, {RED, WHITE , GREEN}, {GREEN, WHITE, ORANGE}, {ORANGE, WHITE, BLUE},
		};

	};

	namespace rubicMatrixesArray
	{
		using namespace rubicInstructions::rubicBlocksArray;

		RubicMatrix matrix1[9] =
		{
			AR3[2], AR2[3], AR3[3],
			AR2[6], AR1[4], AR2[7],
			AR3[6], AR2[11], AR3[7],
		};

		RubicMatrix matrix2[9] =
		{
			AR2[2], AR1[0], AR2[0],
			AR1[3], Colors::NONE, AR1[1],
			AR2[10], AR1[5], AR2[8],
		};
		RubicMatrix matrix3[9] =
		{
			AR3[1], AR2[1], AR3[0],
			AR2[5], AR1[2], AR2[4],
			AR3[5], AR2[9], AR3[4]
		};
	};

	namespace rubicMoves
	{
		void LMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
		{
			for (int i = 0; i < 3; i++)
				LPrimDo(matrix1, matrix2, matrix3);
		}
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

			//--------Main Surface----------------

			matrix1[0].b1 = nowStatematrix1[6].b1;
			matrix2[0].b2 = nowStatematrix1[3].b1;
			matrix3[0].b3 = nowStatematrix1[0].b1;

			matrix1[3].b1 = nowStatematrix2[6].b1;
			matrix3[3].b2 = nowStatematrix2[0].b2;

			matrix1[6].b1 = nowStatematrix3[6].b3;
			matrix2[6].b1 = nowStatematrix3[3].b2;
			matrix3[6].b3 = nowStatematrix3[0].b3;
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

			//--------Main Surface----------------

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

		void UMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
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

			matrix1[0].b1 = nowStatematrix1[2].b1;
			matrix2[0].b2 = nowStatematrix1[1].b2;
			matrix3[0].b3 = nowStatematrix1[0].b3;

			matrix3[0].b1 = nowStatematrix1[0].b1;
			matrix3[1].b2 = nowStatematrix2[0].b2;
			matrix3[2].b3 = nowStatematrix3[0].b3;

			matrix3[2].b1 = nowStatematrix3[0].b1;
			matrix2[2].b2 = nowStatematrix3[1].b2;
			matrix1[2].b3 = nowStatematrix3[2].b3;

			matrix1[0].b3 = nowStatematrix1[2].b3;
			matrix1[1].b2 = nowStatematrix2[2].b2;
			matrix1[2].b1 = nowStatematrix3[2].b1;

			//--------Main Surface----------------

			matrix3[0].b2 = nowStatematrix1[0].b2;
			matrix3[1].b1 = nowStatematrix2[0].b1;
			matrix3[2].b2 = nowStatematrix3[0].b2;

			matrix2[2].b1 = nowStatematrix3[1].b1;
			matrix1[2].b2 = nowStatematrix3[2].b2;
			matrix1[1].b1 = nowStatematrix2[2].b1;

			matrix1[0].b2 = nowStatematrix1[2].b2;
			matrix2[0].b1 = nowStatematrix1[1].b1;

		}
		void UPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
		{
			for (int i = 0; i < 3; i++)
				UMoveDo(matrix1, matrix2, matrix3);
		}

		void RMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
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

			matrix1[2].b2 = nowStatematrix1[8].b1;
			matrix2[2].b1 = nowStatematrix1[5].b1;
			matrix3[2].b2 = nowStatematrix1[2].b1;

			matrix3[2].b3 = nowStatematrix1[2].b2;
			matrix3[5].b2 = nowStatematrix2[2].b1;
			matrix3[8].b3 = nowStatematrix3[2].b2;

			matrix3[8].b2 = nowStatematrix3[2].b3;
			matrix2[8].b2 = nowStatematrix3[5].b2;
			matrix1[8].b2 = nowStatematrix3[8].b3;

			matrix1[8].b1 = nowStatematrix3[8].b2;
			matrix1[5].b1 = nowStatematrix2[8].b2;
			matrix1[2].b1 = nowStatematrix1[8].b2;
		}
	}
};

namespace debugFunc
{
	
};
