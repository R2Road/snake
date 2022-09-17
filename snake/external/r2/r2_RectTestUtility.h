#pragma once

#include "r2/r2_RectInt.h"

namespace r2
{
	class RectTestUtility
	{
	private:
		RectTestUtility() = delete;

	public:
		static void DrawRect( const int offset_x, const int offset_y, const r2::RectInt& rect, const char c );
		static void DrawRectInfo_Min_Max( const r2::RectInt& rect );
	};
}