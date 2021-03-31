#include "../include/matrixes.h"

namespace rc
{
	namespace matrixes
	{	

		RubicMatrix matrix1[9] =
		{
			blocks::AR3[2], blocks::AR2[3], blocks::AR3[3],
			blocks::AR2[6], blocks::AR1[4], blocks::AR2[7],
			blocks::AR3[6], blocks::AR2[11], blocks::AR3[7],
		};

		RubicMatrix matrix2[9] =
		{
			blocks::AR2[2], blocks::AR1[0], blocks::AR2[0],
			blocks::AR1[3], Colors::NONE, blocks::AR1[1],
			blocks::AR2[10], blocks::AR1[5], blocks::AR2[8],
		};
		RubicMatrix matrix3[9] =
		{
			blocks::AR3[1], blocks::AR2[1], blocks::AR3[0],
			blocks::AR2[5], blocks::AR1[2], blocks::AR2[4],
			blocks::AR3[5], blocks::AR2[9], blocks::AR3[4]
		};
	}
}