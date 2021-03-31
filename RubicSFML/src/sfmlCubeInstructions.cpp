#include "../include/sfmlCubeInstructions.h"

sf::Vector2f allPositionOfBlocks[6] =
{
	sf::Vector2f(WINDOW_W/2, WINDOW_H / 2),
	sf::Vector2f(WINDOW_W / 2, (WINDOW_H / 2)-180),
	sf::Vector2f(WINDOW_W / 2, (WINDOW_H / 2) - 360),

	sf::Vector2f(WINDOW_W / 2, (WINDOW_H / 2) + 180),
	sf::Vector2f(WINDOW_W / 2 - 180, (WINDOW_H / 2)),
	sf::Vector2f(WINDOW_W / 2 + 180, (WINDOW_H / 2)),
};

sf::Vector2f allOriginOfBlocks[9] =
{
	sf::Vector2f(45, 45),
	sf::Vector2f(0, 45),
	sf::Vector2f(-45, 45),

	sf::Vector2f(45, 0),
	sf::Vector2f(0, 0),
	sf::Vector2f(-45, 0),

	sf::Vector2f(45, -45),
	sf::Vector2f(0, -45),
	sf::Vector2f(-45, -45),
};

sf::Color getSfColor(const rc::Colors& thisCol)
{
	switch (thisCol)
	{
	case rc::NONE:
		return sf::Color::Black;
		break;
	case rc::GREEN:
		return sf::Color::Green;
		break;
	case rc::YELLOW:
		return sf::Color::Yellow;
		break;
	case rc::BLUE:
		return sf::Color::Blue;
		break;
	case rc::ORANGE:
		return sf::Color(255, 165, 0);
		break;
	case rc::WHITE:
		return sf::Color::White;
		break;
	case rc::RED:
		return sf::Color::Red;
		break;
	default:
		return sf::Color::Black;
		break;
	}
}


//void (*executeForSurface(const int& surfaceIndex, const enumMoves::CubeMoves& yourCubeMove, rc::RubicMatrix* matrix1, rc::RubicMatrix* matrix2, rc::RubicMatrix* matrix3, void (*destination)(rc::RubicMatrix*, rc::RubicMatrix*, rc::RubicMatrix*)))(rc::RubicMatrix* matrix1, rc::RubicMatrix* matrix2, rc::RubicMatrix* matrix3)
//{
//	using enumMoves::CubeMoves;
//	switch (surfaceIndex)
//	{
//	case 0:
//		switch (yourCubeMove)
//		{
//		case CubeMoves::LMoveDo:
//			
//			destination = rc::moves::LMoveDo;
//			break;
//		case CubeMoves::LPrimDo:
//			destination = rc::moves::LPrimDo;
//			break;
//		case CubeMoves::FPrimDo:
//			destination = rc::moves::FPrimDo;
//			break;
//		case CubeMoves::FMoveDo:
//			destination = rc::moves::FMoveDo;
//			break;
//		case CubeMoves::UMoveDo:
//			destination = rc::moves::UMoveDo;
//			break;
//		case CubeMoves::UPrimDo:
//			destination = rc::moves::UPrimDo;
//			break;
//		case CubeMoves::RMoveDo:
//			destination = rc::moves::RMoveDo;
//			break;
//		case CubeMoves::RPrimDo:
//			destination = rc::moves::RPrimDo;
//			break;
//		case CubeMoves::DMoveDo:
//			destination = rc::moves::DMoveDo;
//			break;
//		case CubeMoves::DPrimDo:
//			destination = rc::moves::DPrimDo;
//			break;
//		case CubeMoves::BPrimDo:
//			destination = rc::moves::BPrimDo;
//			break;
//		case CubeMoves::BMoveDo:
//			destination = rc::moves::BMoveDo;
//			break;
//		}
//		break;
//	case 1:
//		switch (yourCubeMove)
//		{
//		case CubeMoves::LMoveDo:
//			destination = rc::moves::LMoveDo;
//			break;
//		case CubeMoves::LPrimDo:
//			destination = rc::moves::LPrimDo;
//			break;
//
//		case CubeMoves::FPrimDo:
//			destination = rc::moves::UPrimDo;
//			break;
//		case CubeMoves::FMoveDo:
//			destination = rc::moves::UMoveDo;
//			break;
//		case CubeMoves::UMoveDo:
//			destination = rc::moves::BMoveDo;
//			break;
//		case CubeMoves::UPrimDo:
//			destination = rc::moves::BPrimDo;
//			break;
//
//		case CubeMoves::RMoveDo:
//			destination = rc::moves::RMoveDo;
//			break;
//		case CubeMoves::RPrimDo:
//			destination = rc::moves::RPrimDo;
//			break;
//
//		case CubeMoves::DMoveDo:
//			destination = rc::moves::FMoveDo;
//			break;
//		case CubeMoves::DPrimDo:
//			destination = rc::moves::FPrimDo;
//			break;
//		case CubeMoves::BPrimDo:
//			destination = rc::moves::DPrimDo;
//			break;
//		case CubeMoves::BMoveDo:
//			destination = rc::moves::DMoveDo;
//			break;
//		}
//		break;
//	case 2:
//		switch (yourCubeMove)
//		{
//		case CubeMoves::LMoveDo:
//			destination = rc::moves::LMoveDo;
//			break;
//		case CubeMoves::LPrimDo:
//			destination = rc::moves::LPrimDo;
//			break;
//
//
//		case CubeMoves::FPrimDo:
//			destination = rc::moves::BPrimDo;
//			break;
//		case CubeMoves::FMoveDo:
//			destination = rc::moves::BMoveDo;
//			break;
//		case CubeMoves::UMoveDo:
//
//			destination = rc::moves::DMoveDo;
//			break;
//		case CubeMoves::UPrimDo:
//
//			destination = rc::moves::DPrimDo;
//			break;
//
//
//		case CubeMoves::RMoveDo:
//			destination = rc::moves::RMoveDo;
//			break;
//		case CubeMoves::RPrimDo:
//			destination = rc::moves::RPrimDo;
//			break;
//
//
//		case CubeMoves::DMoveDo:
//			destination = rc::moves::UMoveDo;
//			break;
//		case CubeMoves::DPrimDo:
//			destination = rc::moves::UPrimDo;
//			break;
//
//		case CubeMoves::BPrimDo:
//			destination = rc::moves::FMoveDo;
//			break;
//		case CubeMoves::BMoveDo:
//			destination = rc::moves::FPrimDo;
//			break;
//		}
//		break;
//	case 3:
//		switch (yourCubeMove)
//		{
//		case CubeMoves::LMoveDo:
//			destination = rc::moves::LMoveDo;
//			break;
//		case CubeMoves::LPrimDo:
//			destination = rc::moves::LPrimDo;
//			break;
//
//
//		case CubeMoves::FPrimDo:
//			destination = rc::moves::DPrimDo;
//			break;
//		case CubeMoves::FMoveDo:
//			destination = rc::moves::DMoveDo;
//			break;
//
//		case CubeMoves::UMoveDo:
//			destination = rc::moves::FMoveDo;
//			break;
//		case CubeMoves::UPrimDo:
//			destination = rc::moves::FPrimDo;
//			break;
//		case CubeMoves::RMoveDo:
//			destination = rc::moves::RMoveDo;
//			break;
//		case CubeMoves::RPrimDo:
//			destination = rc::moves::RPrimDo;
//			break;
//
//		case CubeMoves::DMoveDo:
//			destination = rc::moves::BPrimDo;
//			break;
//		case CubeMoves::DPrimDo:
//			destination = rc::moves::BMoveDo;
//			break;
//		case CubeMoves::BPrimDo:
//			destination = rc::moves::UPrimDo;
//			break;
//		case CubeMoves::BMoveDo:
//			destination = rc::moves::UMoveDo;
//			break;
//		}
//		break;
//	case 4:
//		switch (yourCubeMove)
//		{
//		case CubeMoves::LMoveDo:
//			destination = rc::moves::BMoveDo;
//			break;
//		case CubeMoves::LPrimDo:
//			destination = rc::moves::BPrimDo;
//			break;
//		case CubeMoves::FPrimDo:
//			destination = rc::moves::FPrimDo;
//			break;
//		case CubeMoves::FMoveDo:
//			destination = rc::moves::FMoveDo;
//			break;
//		case CubeMoves::UMoveDo:
//			destination = rc::moves::UMoveDo;
//			break;
//		case CubeMoves::UPrimDo:
//			destination = rc::moves::UPrimDo;
//			break;
//		case CubeMoves::RMoveDo:
//			destination = rc::moves::FMoveDo;
//			break;
//		case CubeMoves::RPrimDo:
//			destination = rc::moves::FPrimDo;
//			break;
//		case CubeMoves::DMoveDo:
//			destination = rc::moves::DMoveDo;
//			break;
//		case CubeMoves::DPrimDo:
//			destination = rc::moves::DPrimDo;
//			break;
//		case CubeMoves::BPrimDo:
//			destination = rc::moves::RPrimDo;
//			break;
//		case CubeMoves::BMoveDo:
//			destination = rc::moves::RMoveDo;
//			break;
//		}
//		break;
//	case 5:
//		switch (yourCubeMove)
//		{
//		case CubeMoves::LMoveDo:
//			destination = rc::moves::FPrimDo;
//			break;
//		case CubeMoves::LPrimDo:
//			destination = rc::moves::FMoveDo;
//			break;
//		case CubeMoves::FPrimDo:
//			destination = rc::moves::RMoveDo;
//			break;
//		case CubeMoves::FMoveDo:
//			destination = rc::moves::FMoveDo;
//			break;
//		case CubeMoves::UMoveDo:
//			destination = rc::moves::UMoveDo;
//			break;
//		case CubeMoves::UPrimDo:
//			destination = rc::moves::UPrimDo;
//			break;
//		case CubeMoves::RMoveDo:
//			destination = rc::moves::BMoveDo;
//			break;
//		case CubeMoves::RPrimDo:
//			destination = rc::moves::BPrimDo;
//			break;
//		case CubeMoves::DMoveDo:
//			destination = rc::moves::DMoveDo;
//			break;
//		case CubeMoves::DPrimDo:
//			destination = rc::moves::DPrimDo;
//			break;
//		case CubeMoves::BPrimDo:
//			destination = rc::moves::LPrimDo;
//			break;
//		case CubeMoves::BMoveDo:
//			destination = rc::moves::LMoveDo;
//			break;
//		}
//		break;
//	default:
//		break;
//	}
//
//	destination(matrix1, matrix2, matrix3);
//	return destination;
//}
//
//void reverseRubicMoveVectorAdd(std::vector<void(*)(rc::RubicMatrix*, rc::RubicMatrix*, rc::RubicMatrix*)>& vecotrDestination, void(*source)(rc::RubicMatrix*, rc::RubicMatrix*, rc::RubicMatrix*))
//{
//	using namespace rc::moves;
//
//
//	// L NOTATION
//	if (source == LMoveDo)
//	{
//		vecotrDestination.emplace_back(LPrimDo);
//	}
//	else if (source == LPrimDo)
//	{
//		vecotrDestination.emplace_back(LMoveDo);
//	}
//	//R NOTATION
//	else if (source == RMoveDo)
//	{
//		vecotrDestination.emplace_back(RPrimDo);
//	}
//	else if (source == RPrimDo)
//	{
//		vecotrDestination.emplace_back(RMoveDo);
//	}
//	//F NOTATION
//	else if (source == FMoveDo)
//	{
//		vecotrDestination.emplace_back(FPrimDo);
//	}
//	else if (source == FPrimDo)
//	{
//		vecotrDestination.emplace_back(FMoveDo);
//	}
//	//U NOTATION
//	else if (source == UMoveDo)
//	{
//		vecotrDestination.emplace_back(UPrimDo);
//	}
//	else if (source == UPrimDo)
//	{
//		vecotrDestination.emplace_back(UMoveDo);
//	}
//	//R NOTATION
//	else if (source == RMoveDo)
//	{
//		vecotrDestination.emplace_back(RPrimDo);
//	}
//	else if (source == RPrimDo)
//	{
//		vecotrDestination.emplace_back(RMoveDo);
//	}
//	//D NOTATION
//	else if (source == DMoveDo)
//	{
//		vecotrDestination.emplace_back(DPrimDo);
//	}
//	else if (source == DPrimDo)
//	{
//		vecotrDestination.emplace_back(DMoveDo);
//	}
//	//B NOTATION
//	else if (source == BMoveDo)
//	{
//		vecotrDestination.emplace_back(BPrimDo);
//	}
//	else if (source == BPrimDo)
//	{
//		vecotrDestination.emplace_back(BMoveDo);
//	}
//}
