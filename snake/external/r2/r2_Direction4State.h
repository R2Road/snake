#pragma once

namespace r2
{
	enum class eDirection4State
	{
		NONE = -1,

		UP,
		RIGHT,
		DOWN,
		LEFT,

		FIRST = UP,
		END = LEFT,
	};

	eDirection4State GetRandomDirection4State();
	eDirection4State GetReverseDirection4State( const eDirection4State state );

	eDirection4State ConvertInteger2Direction4State( const int value );
	eDirection4State ConvertPoint2Direction4State( const int x, const int y );

}
