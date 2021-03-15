#include "../include/SFMLVisualization.h"


//GREEN - 0
//YELLOW - 1
//BLUE - 2
//ORANGE - 3
//WHITE - 4
//RED - 5
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

void checkState(const ThreeElementBlock& m1)
{
	if (m1.b1 != -1 && m1.b2 == -1 && m1.b3 == -1)
		std::cout << "To jest One" << std::endl;
	else if (m1.b1 != -1 && m1.b2 != -1 && m1.b3 == -1)
		std::cout << "To jest dwa" << std::endl;
	else if (m1.b1 != -1 && m1.b2 != -1 && m1.b3 != -1)
		std::cout << "To jest trzy" << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Colors& col)
{
	stream << getStringNamFromRubicElemnt(col);
	return stream;
}

void LPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3)
{
	RubicMatrix nowStatematrix1[9];
	RubicMatrix nowStatematrix2[9];
	RubicMatrix nowStatematrix3[9];
	
	// Array Copy Statement ---------------
	for (int i = 0; i < 9; i++)
		nowStatematrix1[i] = matrix1[i];
	for (int i = 0; i < 9; i++)
		nowStatematrix2[i] = matrix2[i];
	for (int i = 0; i < 9; i++)
		nowStatematrix3[i] = matrix3[i];
	// ------------------------------------

	matrix1[0].b3 = nowStatematrix1[6].b2;
	matrix1[3].b2 = nowStatematrix2[6].b2;
	matrix1[6].b3 = nowStatematrix3[6].b2;
	
	matrix1[0].b2 = nowStatematrix1[6].b3;
	matrix2[0].b1 = nowStatematrix1[3].b2;
	matrix3[0].b2 = nowStatematrix1[0].b3;
	
	matrix3[0].b1 = nowStatematrix1[0].b2;
	matrix3[3].b1 = nowStatematrix2[0].b1;
	matrix3[6].b1 = nowStatematrix3[0].b2;

	matrix1[6].b2 = nowStatematrix3[0].b1;
	matrix2[6].b2 = nowStatematrix3[3].b1;
	matrix3[6].b2 = nowStatematrix3[6].b1;

	// ===================================

	matrix1[0].b1 = nowStatematrix1[6].b1;
	matrix2[0].b2 = nowStatematrix1[3].b1;
	matrix3[0].b3 = nowStatematrix1[0].b1;

	matrix1[3].b1 = nowStatematrix2[6].b1;
	matrix3[3].b2 = nowStatematrix2[0].b2;

	matrix1[6].b1 = nowStatematrix3[6].b3;
	matrix2[6].b1 = nowStatematrix3[3].b2;

	matrix3[6].b3 = nowStatematrix3[0].b3;
}




int main()
{	

	//LPrimDo(matrix1, matrix2, matrix3);
	//LPrimDo(matrix1, matrix2, matrix3);
	//LPrimDo(matrix1, matrix2, matrix3);
	// 
	//rm2[6].b1 GREEN

	sfmlGrap::mainSFMLVis();

	//std::cout << matrix1[2].b3 << std::endl;
	//std::cout << matrix2[2].b2 << std::endl;
	//std::cout << matrix3[2].b1 << std::endl;
	//std::cout << matrix1[5].b2 << std::endl;
	//std::cout << matrix2[5].b1 << std::endl;
	//std::cout << matrix3[5].b1 << std::endl;
	//std::cout << matrix1[8].b3 << std::endl;
	//std::cout << matrix2[8].b1 << std::endl;
	//std::cout << matrix3[8].b1 << std::endl;


	//std::cout << "\n\nMatrix 1: \n";
	//for (int i = 0; i < 9; i++)
	//	std::cout << matrix1[i].b1<<" - "<<matrix1[i].b2 << " - "<< matrix1[i].b3<< std::endl;
	//std::cout << "\nMatrix 2: \n";
	//for (int i = 0; i < 9; i++)
	//	std::cout << matrix2[i].b1 << " - " << matrix2[i].b2 << " - " << matrix2[i].b3 << std::endl;
	//std::cout << "\nMatrix 3: \n";
	//for (int i = 0; i < 9; i++)
	//	std::cout << matrix3[i].b1 << " - " << matrix3[i].b2 << " - " << matrix3[i].b3 << std::endl;



	std::cin.get();

	return 0;
}