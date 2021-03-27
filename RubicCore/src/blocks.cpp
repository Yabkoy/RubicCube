#include "../include/blocks.h"

namespace rc
{
	namespace blocks
	{
		RubicElementBlock AR1[6] =
		{
			YELLOW, BLUE, RED, GREEN, ORANGE, WHITE,
		};

		RubicElementBlock AR2[12] =
		{
			{YELLOW, BLUE}, {YELLOW, RED}, {YELLOW, GREEN}, {YELLOW, ORANGE},
			{BLUE, RED}, {RED, GREEN}, {GREEN, ORANGE}, {ORANGE, BLUE},
			{BLUE, WHITE}, {RED, WHITE}, {GREEN, WHITE}, {ORANGE, WHITE},
		};

		RubicElementBlock AR3[8] =
		{
			{BLUE, YELLOW, RED}, {RED, YELLOW, GREEN}, {GREEN, YELLOW, ORANGE}, {ORANGE, YELLOW, BLUE},
			{BLUE, WHITE, RED}, {RED, WHITE , GREEN}, {GREEN, WHITE, ORANGE}, {ORANGE, WHITE, BLUE},
		};
	}
}