#include "../include/libs.h"

enum Colors : int
{
	NONE = -1, GREEN, YELLOW, BLUE, ORANGE, WHITE, RED 
};


struct ThreeElementBlock
{
	ThreeElementBlock(const Colors& b1 = Colors::NONE, const Colors& b2 = Colors::NONE, const Colors& b3 = Colors::NONE) : b1(b1), b2(b2), b3(b3) {}

	Colors b1;
	Colors b2;
	Colors b3;
};

ThreeElementBlock AR1[6] =
{
	YELLOW, BLUE, RED, GREEN, ORANGE, WHITE,
};

ThreeElementBlock AR2[12] =
{
	{YELLOW, BLUE}, {YELLOW, RED}, {YELLOW, GREEN}, {YELLOW, ORANGE},
	{BLUE, RED}, {RED, GREEN}, {GREEN, ORANGE}, {ORANGE, BLUE},
	{BLUE, WHITE}, {RED, WHITE}, {GREEN, WHITE}, {ORANGE, WHITE},
};

ThreeElementBlock AR3[8] =
{
	{BLUE, YELLOW, RED}, {RED, YELLOW, GREEN}, {GREEN, YELLOW, ORANGE}, {ORANGE, YELLOW, BLUE},
	{BLUE, WHITE, RED}, {RED, WHITE , GREEN}, {GREEN, WHITE, ORANGE}, {ORANGE, WHITE, BLUE},
};
typedef ThreeElementBlock RubicMatrix;

RubicMatrix matrix1[9] = //0, 3, 6
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


class Camera
{
	private:
		int surfaceIndex = 0;
		
		const RubicMatrix* rm1;
		const RubicMatrix* rm2;
		const RubicMatrix* rm3;

	public:

		Camera(const RubicMatrix* m1, const RubicMatrix* m2, const RubicMatrix* m3) : rm1(m1), rm2(m2), rm3(m3)
		{
			std::cout << "Camera Crated!\n";



			std::cout << "\n\nMATRIX2: \n";
			std::cout << rm1[0].b2 << std::endl;
			std::cout << rm1[1].b1 << std::endl;
			std::cout << rm1[2].b2 << std::endl;

			std::cout << rm2[0].b1 << std::endl;
			std::cout << rm2[1].b1 << std::endl;
			std::cout << rm2[2].b1 << std::endl;

			std::cout << rm3[0].b2 << std::endl;
			std::cout << rm3[1].b1 << std::endl;
			std::cout << rm3[2].b2 << std::endl;


		}

		std::array<RubicMatrix, 9> getBlockArray()
		{
			std::array<RubicMatrix, 9> returnTypes;
			switch (surfaceIndex)
			{
			case 0: //DEF ORANGE
			{
				returnTypes[0] = rm1[0].b3;
				returnTypes[1] = rm1[1].b2;
				returnTypes[2] = rm1[2].b1;

				returnTypes[3] = rm1[3].b2;
				returnTypes[4] = rm1[4].b1;
				returnTypes[5] = rm1[5].b1;

				returnTypes[6] = rm1[6].b3;
				returnTypes[7] = rm1[7].b1;
				returnTypes[8] = rm1[8].b1;
			}
			case 1: //DEF YELLOW
			{
				returnTypes[0] = rm1[0].b2;
				returnTypes[1] = rm1[1].b1;
				returnTypes[2] = rm1[2].b2;
											  
				returnTypes[3] = rm2[0].b1;
				returnTypes[4] = rm2[1].b1;
				returnTypes[5] = rm2[2].b1;
											  
				returnTypes[6] = rm3[0].b2;
				returnTypes[7] = rm3[1].b1;
				returnTypes[8] = rm3[2].b2;
			}
			case 2: //DEF RED
			{
				returnTypes[0] = rm3[0].b1;
				returnTypes[1] = rm3[1].b2;
				returnTypes[2] = rm3[2].b3;
										  
				returnTypes[3] = rm3[3].b1;
				returnTypes[4] = rm3[4].b1;
				returnTypes[5] = rm3[5].b2;
										  
				returnTypes[6] = rm3[6].b1;
				returnTypes[7] = rm3[7].b1;
				returnTypes[8] = rm3[8].b3;
			}
			case 3: //DEF WHITE
			{
				returnTypes[0] = rm1[6].b2; 
				returnTypes[1] = rm1[7].b2; 
				returnTypes[2] = rm1[8].b2; 
				returnTypes[3] = rm2[6].b2;
				returnTypes[4] = rm2[7].b1;
				returnTypes[5] = rm2[8].b2;
				returnTypes[6] = rm3[6].b2;
				returnTypes[7] = rm3[7].b2;
				returnTypes[8] = rm3[8].b2;
								  
			}	
			case 4:
			{
				returnTypes[0] = rm1[0].b1;
				returnTypes[1] = rm2[3].b1;
				returnTypes[2] = rm3[0].b3;
				returnTypes[3] = rm1[3].b1;
				returnTypes[4] = rm2[3].b1;
				returnTypes[5] = rm3[3].b2;
				returnTypes[6] = rm1[6].b1;
				returnTypes[7] = rm2[6].b1;
				returnTypes[8] = rm3[6].b3;
			}
			case 5:
			{
				returnTypes[0] = rm1[2].b3;
				returnTypes[1] = rm2[2].b2;
				returnTypes[2] = rm3[2].b1;
				returnTypes[3] = rm1[5].b2;
				returnTypes[4] = rm2[5].b1;
				returnTypes[5] = rm3[5].b1;
				returnTypes[6] = rm1[8].b3;
				returnTypes[7] = rm2[8].b1;
				returnTypes[8] = rm3[8].b1;
			}
			default:			  
				break;
			}
		}

};

int main()
{	
	sf::RenderWindow RW(sf::VideoMode(800, 600, 32), "TEST WINDOW");

	sf::RectangleShape RS(sf::Vector2f(25, 25));
	RS.setFillColor(sf::Color::Red);

	while (RW.isOpen())
	{
		sf::Event mainEvent;
		if (RW.pollEvent(mainEvent))
		{
			if (mainEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				RW.close();
		}

		RW.clear(sf::Color::Black);

		RW.draw(RS);

		RW.display();
	}



	//LPrimDo(matrix1, matrix2, matrix3);
	//LPrimDo(matrix1, matrix2, matrix3);
	//LPrimDo(matrix1, matrix2, matrix3);



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