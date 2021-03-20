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



	entryPointPositions::entryPointPositions(const int& elementIndex)
	{
		entrySurfacePoint = sf::Vector2f((WINDOW_W / 2) - 25, (WINDOW_W / 2) - 100);

		unsigned int surfaceArrayIndex[36] = {
			0, 1, 2, 3, 4, 5,
			5, 1, 4, 3, 0, 2,
			0, 1, 2, 3, 5, 4, // <- 2
			4, 1, 5, 3, 2, 0,
			1, 2, 3, 0, 4, 5,
			3, 0, 1, 2, 4, 5,
		};

		//2

		myRubicSurfacePositions[surfaceArrayIndex[(elementIndex*6)]] = sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y + 200); //ORANGE 0
		myRubicSurfacePositions[surfaceArrayIndex[((elementIndex*6)+1)]] = sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y); //YELLOW 1
		myRubicSurfacePositions[surfaceArrayIndex[((elementIndex*6)+2)]] = sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y - 200); //RED 2
		myRubicSurfacePositions[surfaceArrayIndex[((elementIndex*6)+3)]] = sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y + 400); //WHITE 3
		myRubicSurfacePositions[surfaceArrayIndex[((elementIndex*6)+4)]] = sf::Vector2f(entrySurfacePoint.x - 200, entrySurfacePoint.y + 200); //GREEN 4
		myRubicSurfacePositions[surfaceArrayIndex[((elementIndex*6)+5)]] = sf::Vector2f(entrySurfacePoint.x + 200, entrySurfacePoint.y + 200); //BLUE 5

		//0, 1, 2, 3, 4, 5 ORANGE 
		//5, 1, 4, 3, 0, 2 BLUE
		//2, 1, 0, 3, 5, 4 RED
		//4, 1, 5, 3, 2, 0 GREEN
		//1, 2, 3, 0, 4, 5 YELLOW
		//3, 0, 1, 2, 4, 5 WHITE
	}

	float entryPointPositions::surfaceRotate(const int& elementIndex)
	{
		return 0;
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

	void arrayCopyFunction(RubicMatrix* source, RubicMatrix* destination, size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			destination[i] = source[i];
		}
	}

	void rotateCube(const int& onIndex)
	{
		
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

			arrayCopyFunction(matrix1, nowStatematrix1, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			arrayCopyFunction(matrix2, nowStatematrix2, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			arrayCopyFunction(matrix3, nowStatematrix3, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));

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

		void FPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
		{
			RubicMatrix nowStatematrix1[9];

			arrayCopyFunction(matrix1, nowStatematrix1, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));

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
		void FMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
		{
			for (int i = 0; i < 3; i++)
				FPrimDo(matrix1, matrix2, matrix3);
		}

		void UMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
		{
			RubicMatrix nowStatematrix1[9];
			RubicMatrix nowStatematrix2[9];
			RubicMatrix nowStatematrix3[9];

			arrayCopyFunction(matrix1, nowStatematrix1, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			arrayCopyFunction(matrix2, nowStatematrix2, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			arrayCopyFunction(matrix3, nowStatematrix3, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));

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

			arrayCopyFunction(matrix1, nowStatematrix1, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			arrayCopyFunction(matrix2, nowStatematrix2, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			arrayCopyFunction(matrix3, nowStatematrix3, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));

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

			//--------Main Surface----------------

			matrix1[2].b3 = nowStatematrix1[8].b3;
			matrix2[2].b2 = nowStatematrix1[5].b2;
			matrix3[2].b1 = nowStatematrix1[2].b3;

			matrix3[5].b1 = nowStatematrix2[2].b2;
			matrix3[8].b1 = nowStatematrix3[2].b1;
			matrix2[8].b1 = nowStatematrix3[5].b1;
			
			matrix1[8].b3 = nowStatematrix3[8].b1;
			matrix1[5].b2 = nowStatematrix2[8].b1;


		}
		void RPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
		{
			for (int i = 0; i < 3; i++)
				RMoveDo(matrix1, matrix2, matrix3);
		}

		void DMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
		{
			RubicMatrix nowStatematrix1[9];
			RubicMatrix nowStatematrix2[9];
			RubicMatrix nowStatematrix3[9];

			arrayCopyFunction(matrix1, nowStatematrix1, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			arrayCopyFunction(matrix2, nowStatematrix2, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			arrayCopyFunction(matrix3, nowStatematrix3, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));

			matrix1[8].b3 = nowStatematrix1[6].b3;
			matrix2[8].b1 = nowStatematrix1[7].b1;
			matrix3[8].b1 = nowStatematrix1[8].b1;

			matrix3[8].b3 = nowStatematrix1[8].b3;
			matrix3[7].b1 = nowStatematrix2[8].b1;
			matrix3[6].b1 = nowStatematrix3[8].b1;

			matrix3[6].b3 = nowStatematrix3[8].b3;
			matrix2[6].b1 = nowStatematrix3[7].b1;
			matrix1[6].b1 = nowStatematrix3[6].b1;

			matrix1[6].b3 = nowStatematrix3[6].b3;
			matrix1[7].b1 = nowStatematrix2[6].b1;
			matrix1[8].b1 = nowStatematrix1[6].b1;

			//--------Main Surface----------------

			matrix1[6].b2 = nowStatematrix3[6].b2;
			matrix1[7].b2 = nowStatematrix2[6].b2;
			matrix1[8].b2 = nowStatematrix1[6].b2;

			matrix2[8].b2 = nowStatematrix1[7].b2;
			matrix3[8].b2 = nowStatematrix1[8].b2;
			matrix3[7].b2 = nowStatematrix2[8].b2;

			matrix3[6].b2 = nowStatematrix3[8].b2;
			matrix2[6].b2 = nowStatematrix3[7].b2;

		}
		void DPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
		{
			for (int i = 0; i < 3; i++)
				DMoveDo(matrix1, matrix2, matrix3);
		}

		void BPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
		{
			RubicMatrix nowStatematrix3[9];

			arrayCopyFunction(matrix3, nowStatematrix3, (sizeof(nowStatematrix3) / sizeof(RubicMatrix)));

			matrix3[2].b1 = nowStatematrix3[0].b2;
			matrix3[5].b1 = nowStatematrix3[1].b1;
			matrix3[8].b1 = nowStatematrix3[2].b2;

			matrix3[8].b2 = nowStatematrix3[2].b1;
			matrix3[7].b2 = nowStatematrix3[5].b1;
			matrix3[6].b2 = nowStatematrix3[8].b1;

			matrix3[6].b3 = nowStatematrix3[8].b2;
			matrix3[3].b2 = nowStatematrix3[7].b2;
			matrix3[0].b3 = nowStatematrix3[6].b2;

			matrix3[0].b2 = nowStatematrix3[6].b3;
			matrix3[1].b1 = nowStatematrix3[3].b2;
			matrix3[2].b2 = nowStatematrix3[0].b3;

			//--------Main Surface----------------

			matrix3[2].b3 = nowStatematrix3[8].b3;
			matrix3[1].b2 = nowStatematrix3[5].b2;
			matrix3[0].b1 = nowStatematrix3[2].b3;

			matrix3[3].b1 = nowStatematrix3[1].b2;
			matrix3[6].b1 = nowStatematrix3[0].b1;
			matrix3[7].b1 = nowStatematrix3[3].b1;

			matrix3[8].b3 = nowStatematrix3[6].b1;
			matrix3[5].b2 = nowStatematrix3[7].b1;

		}

		void BMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
		{
			for (int i = 0; i < 3; i++)
				BPrimDo(matrix1, matrix2, matrix3);
		}

		void (*allMovesArrayPointers[12])(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3) = 
		{
			LMoveDo, LPrimDo, FPrimDo, FMoveDo, UMoveDo, UPrimDo, RMoveDo, RPrimDo, DMoveDo, DPrimDo, BPrimDo, BMoveDo,
		};

		void executeForSurface(const int& surfaceIndex, const rubicEnum::CubeMoves& yourCubeMove, RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3, void (*destination)(RubicMatrix*, RubicMatrix*, RubicMatrix*))
		{
			using rubicEnum::CubeMoves;
			switch (surfaceIndex)
			{
			case 0:
				switch (yourCubeMove)
				{
				case CubeMoves::LMoveDo:
					destination = LMoveDo;
					break;
				case CubeMoves::LPrimDo:
					destination = LPrimDo;
					break;
				case CubeMoves::FPrimDo:
					destination = FPrimDo;
					break;
				case CubeMoves::FMoveDo:
					destination = FMoveDo;
					break;
				case CubeMoves::UMoveDo:
					destination = UMoveDo;
					break;
				case CubeMoves::UPrimDo:
					destination = UPrimDo;
					break;
				case CubeMoves::RMoveDo:
					destination = RMoveDo;
					break;
				case CubeMoves::RPrimDo:
					destination = RPrimDo;
					break;
				case CubeMoves::DMoveDo:
					destination = DMoveDo;
					break;
				case CubeMoves::DPrimDo:
					destination = DPrimDo;
					break;
				case CubeMoves::BPrimDo:
					destination = BPrimDo;
					break;
				case CubeMoves::BMoveDo:
					destination = BMoveDo;
					break;
				}
				break;
			case 1:
				switch (yourCubeMove)
				{
				case CubeMoves::LMoveDo:
					destination = LMoveDo;
					break;
				case CubeMoves::LPrimDo:
					destination = LPrimDo;
					break;

				case CubeMoves::FPrimDo:
					destination = UPrimDo;
					break;
				case CubeMoves::FMoveDo:
					destination = UMoveDo;
					break;
				case CubeMoves::UMoveDo:
					destination = BMoveDo;
					break;
				case CubeMoves::UPrimDo:
					destination = BPrimDo;
					break;

				case CubeMoves::RMoveDo:
					destination = RMoveDo;
					break;
				case CubeMoves::RPrimDo:
					destination = RPrimDo;
					break;

				case CubeMoves::DMoveDo:
					destination = FMoveDo;
					break;
				case CubeMoves::DPrimDo:
					destination = FPrimDo;
					break;
				case CubeMoves::BPrimDo:
					destination = DPrimDo;
					break;
				case CubeMoves::BMoveDo:
					destination = DMoveDo;
					break;
				}
				break;
			case 2:
				switch (yourCubeMove)
				{
				case CubeMoves::LMoveDo:
					destination = LMoveDo;
					break;
				case CubeMoves::LPrimDo:
					destination = LPrimDo;
					break;


				case CubeMoves::FPrimDo:
					destination = BPrimDo;
					break;
				case CubeMoves::FMoveDo:
					destination = BMoveDo;
					break;
				case CubeMoves::UMoveDo:
					
					destination = DMoveDo;
					break;
				case CubeMoves::UPrimDo:
					
					destination = DPrimDo;
					break;


				case CubeMoves::RMoveDo:
					destination = RMoveDo;
					break;
				case CubeMoves::RPrimDo:
					destination = RPrimDo;
					break;


				case CubeMoves::DMoveDo:
					destination = UMoveDo;
					break;
				case CubeMoves::DPrimDo:
					destination = UPrimDo;
					break;

				case CubeMoves::BPrimDo:
					destination = FMoveDo;
					break;
				case CubeMoves::BMoveDo:
					destination = FPrimDo;
					break;
				}
				break;
			case 3:
				switch (yourCubeMove)
				{
				case CubeMoves::LMoveDo:
					destination = LMoveDo;
					break;
				case CubeMoves::LPrimDo:
					destination = LPrimDo;
					break;


				case CubeMoves::FPrimDo:
					destination = DPrimDo;
					break;
				case CubeMoves::FMoveDo:
					destination = DMoveDo;
					break;

				case CubeMoves::UMoveDo:
					destination = FMoveDo;
					break;
				case CubeMoves::UPrimDo:
					destination = FPrimDo;
					break;
				case CubeMoves::RMoveDo:
					destination = RMoveDo;
					break;
				case CubeMoves::RPrimDo:
					destination = RPrimDo;
					break;

				case CubeMoves::DMoveDo:
					destination = BPrimDo;
					break;
				case CubeMoves::DPrimDo:
					destination = BMoveDo;
					break;
				case CubeMoves::BPrimDo:
					destination = UPrimDo;
					break;
				case CubeMoves::BMoveDo:
					destination = UMoveDo;
					break;
				}
				break;
			case 4:
				switch (yourCubeMove)
				{
				case CubeMoves::LMoveDo:
					destination = BMoveDo;
					break;
				case CubeMoves::LPrimDo:
					destination = BPrimDo;
					break;
				case CubeMoves::FPrimDo:
					destination = FPrimDo;
					break;
				case CubeMoves::FMoveDo:
					destination = FMoveDo;
					break;
				case CubeMoves::UMoveDo:
					destination = UMoveDo;
					break;
				case CubeMoves::UPrimDo:
					destination = UPrimDo;
					break;
				case CubeMoves::RMoveDo:
					destination = FMoveDo;
					break;
				case CubeMoves::RPrimDo:
					destination = FPrimDo;
					break;
				case CubeMoves::DMoveDo:
					destination = DMoveDo;
					break;
				case CubeMoves::DPrimDo:
					destination = DPrimDo;
					break;
				case CubeMoves::BPrimDo:
					destination = RPrimDo;
					break;
				case CubeMoves::BMoveDo:
					destination = RMoveDo;
					break;
				}
				break;
			case 5:
				switch (yourCubeMove)
				{
				case CubeMoves::LMoveDo:
					destination = FPrimDo;
					break;
				case CubeMoves::LPrimDo:
					destination = FMoveDo;
					break;
				case CubeMoves::FPrimDo:
					destination = RMoveDo;
					break;
				case CubeMoves::FMoveDo:
					destination = FMoveDo;
					break;
				case CubeMoves::UMoveDo:
					destination = UMoveDo;
					break;
				case CubeMoves::UPrimDo:
					destination = UPrimDo;
					break;
				case CubeMoves::RMoveDo:
					destination = BMoveDo;
					break;
				case CubeMoves::RPrimDo:
					destination = BPrimDo;
					break;
				case CubeMoves::DMoveDo:
					destination = DMoveDo;
					break;
				case CubeMoves::DPrimDo:
					destination = DPrimDo;
					break;
				case CubeMoves::BPrimDo:
					destination = LPrimDo;
					break;
				case CubeMoves::BMoveDo:
					destination = LMoveDo;
					break;
				}
				break;
			default:
				break;
			}

			destination(matrix1, matrix2, matrix3);
		}
	}

	void reverseRubicMoveVectorAdd(std::vector<void(*)(rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*)>& vecotrDestination, void(*source)(rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*))
	{
		using namespace rubicMoves;
		
		// L NOTATION
		if (source == LMoveDo)
		{
			vecotrDestination.emplace_back(LPrimDo);
		}
		else if(source == LPrimDo)
		{
			vecotrDestination.emplace_back(LMoveDo);
		}
		//R NOTATION
		else if (source == RMoveDo)
		{
			vecotrDestination.emplace_back(RPrimDo);
		}
		else if (source == RPrimDo)
		{
			vecotrDestination.emplace_back(RMoveDo);
		}
		//F NOTATION
		else if (source == FMoveDo)
		{
			vecotrDestination.emplace_back(FPrimDo);
		}
		else if (source == FPrimDo)
		{
			vecotrDestination.emplace_back(FMoveDo);
		}
		//U NOTATION
		else if (source == UMoveDo)
		{
			vecotrDestination.emplace_back(UPrimDo);
		}
		else if (source == UPrimDo)
		{
			vecotrDestination.emplace_back(UMoveDo);
		}
		//R NOTATION
		else if (source == RMoveDo)
		{
			vecotrDestination.emplace_back(RPrimDo);
		}
		else if (source == RPrimDo)
		{
			vecotrDestination.emplace_back(RMoveDo);
		}
		//D NOTATION
		else if (source == DMoveDo)
		{
			vecotrDestination.emplace_back(DPrimDo);
		}
		else if (source == DPrimDo)
		{
			vecotrDestination.emplace_back(DMoveDo);
		}
		//B NOTATION
		else if (source == BMoveDo)
		{
			vecotrDestination.emplace_back(BPrimDo);
		}
		else if (source == BPrimDo)
		{
			vecotrDestination.emplace_back(BMoveDo);
		}
	}


};