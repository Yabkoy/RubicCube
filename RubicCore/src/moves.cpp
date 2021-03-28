#include "../include/moves.h"

namespace rc
{
	namespace moves
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

			rubicArrayCopy(matrix1, nowStatematrix1, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			rubicArrayCopy(matrix2, nowStatematrix2, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			rubicArrayCopy(matrix3, nowStatematrix3, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));

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

			rubicArrayCopy(matrix1, nowStatematrix1, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));

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


			rubicArrayCopy(matrix1, nowStatematrix1, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			rubicArrayCopy(matrix2, nowStatematrix2, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			rubicArrayCopy(matrix3, nowStatematrix3, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));

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

			rubicArrayCopy(matrix1, nowStatematrix1, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			rubicArrayCopy(matrix2, nowStatematrix2, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			rubicArrayCopy(matrix3, nowStatematrix3, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));

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

			rubicArrayCopy(matrix1, nowStatematrix1, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			rubicArrayCopy(matrix2, nowStatematrix2, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));
			rubicArrayCopy(matrix3, nowStatematrix3, (sizeof(nowStatematrix1) / sizeof(RubicMatrix)));

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

			rubicArrayCopy(matrix3, nowStatematrix3, (sizeof(nowStatematrix3) / sizeof(RubicMatrix)));

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
	}
}