#include "../include/rubicElementClass.h"

namespace debugFunc
{
	std::ostream& operator<<(std::ostream& stream, const Colors& col)
	{
		stream << rubicInstructions::getStringNamFromRubicElemnt(col);
		return stream;
	}
	void checkState(const rubicInstructions::ThreeElementBlock& m1)
	{
		if (m1.b1 != -1 && m1.b2 == -1 && m1.b3 == -1)
			std::cout << "To jest One" << std::endl;
		else if (m1.b1 != -1 && m1.b2 != -1 && m1.b3 == -1)
			std::cout << "To jest dwa" << std::endl;
		else if (m1.b1 != -1 && m1.b2 != -1 && m1.b3 != -1)
			std::cout << "To jest trzy" << std::endl;
	}
};