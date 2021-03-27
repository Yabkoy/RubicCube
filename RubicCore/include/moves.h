#pragma once

#include "instructions.h"

namespace rc
{
	namespace moves
	{
		void LMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
		void LPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
																					  
		void FPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
		void FMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
																					  ;
		void UMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
		void UPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
																					  
		void RMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
		void RPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
																					  
		void DMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
		void DPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
																					  
		void BPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
		void BMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
	}
}