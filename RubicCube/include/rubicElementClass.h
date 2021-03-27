#pragma once
#include "libs.h"

namespace rubicInstructions
{
	sf::Color getSfColor(const Colors& thisCol);

	std::string getStringNamFromRubicElemnt(const Colors& element);



	struct entryPointPositions
	{
		sf::Vector2f entrySurfacePoint;
		sf::Vector2f myRubicSurfacePositions[6];
		float surfaceRotate(const int& elementIndex);

		entryPointPositions(const int& elementIndex);
	};

	

	std::array<Colors, 9> getRubicSurfaceArray(const int& surfaceIndex, const RubicMatrix* rm1, const RubicMatrix* rm2, const RubicMatrix* rm3);

	void initInstructions();

	void arrayCopyFunction(RubicMatrix* source, RubicMatrix* destination);

	void rotateCube(const int& onIndex);

	namespace rubicBlocksArray
	{
		extern ThreeElementBlock AR1[6];

		extern ThreeElementBlock AR2[12];

		extern ThreeElementBlock AR3[8];

	};

	namespace rubicMatrixesArray
	{
		extern RubicMatrix matrix1[9];
		extern RubicMatrix matrix2[9];
		extern RubicMatrix matrix3[9];
	};

	namespace rubicMoves
	{
		namespace rubicEnum
		{
			enum CubeMoves
			{
				LMoveDo, LPrimDo, FPrimDo, FMoveDo, UMoveDo, UPrimDo, RMoveDo, RPrimDo, DMoveDo, DPrimDo, BPrimDo, BMoveDo
			};
		};


		void LPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
		void LMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);

		void FPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
		void FMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);

		void UMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
		void UPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);

		void RMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
		void RPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);

		void DMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
		void DPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);

		void BPrimDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
		void BMoveDo(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);

		extern void (*allMovesArrayPointers[12])(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);

		extern void (*executeForSurface(const int& surfaceIndex, const rubicEnum::CubeMoves& yourCubeMove, RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3, void (*destination)(RubicMatrix*, RubicMatrix*, RubicMatrix*)))(RubicMatrix* matrix1, RubicMatrix* matrix2, RubicMatrix* matrix3);
	};

	void reverseRubicMoveVectorAdd(std::vector<void(*)(rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*)>& vecotrDestination, void(*source)(rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*, rubicInstructions::RubicMatrix*));
};
