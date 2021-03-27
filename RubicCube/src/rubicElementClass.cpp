#include "../include/rubicElementClass.h"

namespace rubicInstructions
{






	namespace rubicMoves
	{

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