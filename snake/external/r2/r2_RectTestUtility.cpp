#include "r2_RectTestUtility.h"

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

namespace r2
{
	void RectTestUtility::DrawRect( const int offset_x, const int offset_y, const r2::RectInt& rect, const char c )
	{
		for( int y = rect.GetMinY(); rect.GetMaxY() >= y; ++y )
		{
			for( int x = rect.GetMinX(); rect.GetMaxX() >= x; ++x )
			{
				r2cm::WindowUtility::FillCharacter( { static_cast<short>( offset_x + x ), static_cast<short>( offset_y + y ) }, c );
			}
		}
	}

	void RectTestUtility::DrawRectInfo_Min_Max( const r2::RectInt& rect )
	{
		std::cout << r2cm::tab << "rect min, max :" << " " << rect.GetMinX() << " " << rect.GetMinY() << " " << rect.GetMaxX() << " " << rect.GetMaxY() << r2cm::linefeed;
	}
}