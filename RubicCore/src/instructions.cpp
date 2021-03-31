#include "../include/instructions.h"

namespace rc
{

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

	std::array<Colors, 9> getRubicSurfaceNumber(const int& surfaceIndex, const RubicMatrix* rm1, const RubicMatrix* rm2, const RubicMatrix* rm3)
	{

		std::array<Colors, 9> returnTypes;
		switch (surfaceIndex)
		{
			case 0: //DEF Green
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
			case 2: //DEF Blue
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
			case 3: //DEF Orange
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
			case 4: //DEF White
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
			case 5: //DEF red
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
		}

		return returnTypes; //If value don't exist crash is needed!
	}

	//std::array<Colors, 9> getRubicSurfaceNumber(const int& surfaceIndex, const RubicMatrix* rm1, const RubicMatrix* rm2, const RubicMatrix* rm3)
	//{

	//	std::array<Colors, 9> returnTypes;
	//	switch (surfaceIndex)
	//	{
	//	case 0: //DEF ORANGE
	//	{
	//		returnTypes[0] = rm1[0].b3;
	//		returnTypes[1] = rm1[1].b2;
	//		returnTypes[2] = rm1[2].b1;

	//		returnTypes[3] = rm1[3].b2;
	//		returnTypes[4] = rm1[4].b1;
	//		returnTypes[5] = rm1[5].b1;

	//		returnTypes[6] = rm1[6].b3;
	//		returnTypes[7] = rm1[7].b1;
	//		returnTypes[8] = rm1[8].b1;
	//		break;
	//	}
	//	case 1: //DEF YELLOW
	//	{
	//		returnTypes[0] = rm3[0].b2;
	//		returnTypes[1] = rm3[1].b1;
	//		returnTypes[2] = rm3[2].b2;

	//		returnTypes[3] = rm2[0].b1;
	//		returnTypes[4] = rm2[1].b1;
	//		returnTypes[5] = rm2[2].b1;

	//		returnTypes[6] = rm1[0].b2;
	//		returnTypes[7] = rm1[1].b1;
	//		returnTypes[8] = rm1[2].b2;

	//		break;
	//	}
	//	case 2: //DEF RED
	//	{
	//		returnTypes[8] = rm3[2].b3;
	//		returnTypes[7] = rm3[1].b2;
	//		returnTypes[6] = rm3[0].b1;

	//		returnTypes[5] = rm3[5].b2;
	//		returnTypes[4] = rm3[4].b1;
	//		returnTypes[3] = rm3[3].b1;

	//		returnTypes[2] = rm3[8].b3;
	//		returnTypes[1] = rm3[7].b1;
	//		returnTypes[0] = rm3[6].b1;
	//		break;
	//	}
	//	case 3: //DEF WHITE
	//	{
	//		returnTypes[0] = rm1[6].b2;
	//		returnTypes[1] = rm1[7].b2;
	//		returnTypes[2] = rm1[8].b2;

	//		returnTypes[3] = rm2[6].b2;
	//		returnTypes[4] = rm2[7].b1;
	//		returnTypes[5] = rm2[8].b2;
	//		returnTypes[6] = rm3[6].b2;
	//		returnTypes[7] = rm3[7].b2;
	//		returnTypes[8] = rm3[8].b2;
	//		break;
	//	}
	//	case 4: //DEF GREEN
	//	{
	//		returnTypes[0] = rm3[0].b3;
	//		returnTypes[1] = rm2[0].b2;
	//		returnTypes[2] = rm1[0].b1;

	//		returnTypes[3] = rm3[3].b2;
	//		returnTypes[4] = rm2[3].b1;
	//		returnTypes[5] = rm1[3].b1;

	//		returnTypes[6] = rm3[6].b3;
	//		returnTypes[7] = rm2[6].b1;
	//		returnTypes[8] = rm1[6].b1;

	//		break;
	//	}
	//	case 5: //DEF BLUE
	//	{
	//		returnTypes[0] = rm1[2].b3;
	//		returnTypes[1] = rm2[2].b2;
	//		returnTypes[2] = rm3[2].b1;

	//		returnTypes[3] = rm1[5].b2;
	//		returnTypes[4] = rm2[5].b1;
	//		returnTypes[5] = rm3[5].b1;

	//		returnTypes[6] = rm1[8].b3;
	//		returnTypes[7] = rm2[8].b1;
	//		returnTypes[8] = rm3[8].b1;
	//		break;
	//	}
	//	}

	//	return returnTypes; //If value don't exist crash is needed!
	//}

	void rubicArrayCopy(RubicMatrix* source, RubicMatrix* destination, size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			destination[i] = source[i];
		}
	}
}