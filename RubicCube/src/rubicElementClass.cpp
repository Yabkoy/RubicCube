#include "../include/rubicElementClass.h"

namespace rubicInstructions
{



	entryPointPositions::entryPointPositions(const int& elementIndex)
	{
		std::cout << "INDEX: " << elementIndex << std::endl;
		entrySurfacePoint = sf::Vector2f((WINDOW_W / 2) - 25, (WINDOW_W / 2) - 100);

		myRubicSurfacePositions[0] = sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y + 200); //ORANGE 0
		myRubicSurfacePositions[1] = sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y); //YELLOW 1
		myRubicSurfacePositions[2] = sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y - 200); //RED 2
		myRubicSurfacePositions[3] = sf::Vector2f(entrySurfacePoint.x, entrySurfacePoint.y + 400); //WHITE 3
		myRubicSurfacePositions[4] = sf::Vector2f(entrySurfacePoint.x - 200, entrySurfacePoint.y + 200); //GREEN 4
		myRubicSurfacePositions[5] = sf::Vector2f(entrySurfacePoint.x + 200, entrySurfacePoint.y + 200); //BLUE 5

		//std::cout << (elementIndex * 6) << std::endl;
		//std::cout << ((elementIndex * 6) + 1) << std::endl;
		//std::cout << ((elementIndex * 6) + 2) << std::endl;
		//std::cout << ((elementIndex * 6) + 3) << std::endl;
		//std::cout << ((elementIndex * 6) + 4) << std::endl;
		//std::cout << ((elementIndex * 6) + 5) << std::endl;

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


	namespace rubicMoves
	{
		void (*executeForSurface(const int& surfaceIndex, const rubicEnum::CubeMoves& yourCubeMove, RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3, void (*destination)(RubicMatrix*, RubicMatrix*, RubicMatrix*)))(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
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
			return destination;
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