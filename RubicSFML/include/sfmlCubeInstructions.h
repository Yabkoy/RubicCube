#pragma once
#include "libs.h"

sf::Color getSfColor(const rc::Colors& thisCol);

struct entryPointPositions
{
	sf::Vector2f entrySurfacePoint;
	sf::Vector2f myRubicSurfacePositions[6];

	entryPointPositions(const int& elementIndex);
};
namespace enumMoves
{
	enum CubeMoves
	{
		LMoveDo, LPrimDo, FPrimDo, FMoveDo, UMoveDo, UPrimDo, RMoveDo, RPrimDo, DMoveDo, DPrimDo, BPrimDo, BMoveDo
	};
}


extern void (*executeForSurface(const int& surfaceIndex, const enumMoves::CubeMoves& yourCubeMove, rc::RubicMatrix* matrix1, rc::RubicMatrix* matrix2, rc::RubicMatrix* matrix3, void (*destination)(rc::RubicMatrix*, rc::RubicMatrix*, rc::RubicMatrix*)))(rc::RubicMatrix* matrix1, rc::RubicMatrix* matrix2, rc::RubicMatrix* matrix3);

extern void reverseRubicMoveVectorAdd(std::vector<void(*)(rc::RubicMatrix*, rc::RubicMatrix*, rc::RubicMatrix*)>& vecotrDestination, void(*source)(rc::RubicMatrix*, rc::RubicMatrix*, rc::RubicMatrix*));