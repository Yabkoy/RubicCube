#include "../include/matrixes.h"

namespace rc
{
	namespace matrixes
	{
		using namespace rc::blocks;
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
	}
}