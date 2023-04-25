#include "Utility4Snake.h"

#include <iomanip>

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "psm/psm_Snake.h"

namespace psm_helper
{
	void Utility4Snake::Draw( const short x, const short y, const psm::Snake& snake )
	{
		const r2cm::WindowUtility::CursorPoint pivot_point{ x, y };

		for( uint32_t cy = 0; cy < snake.GetHeight(); ++cy )
		{
			for( uint32_t cx = 0; cx < snake.GetWidth(); ++cx )
			{
				if( snake.Get( cx, cy ) )
				{
					r2cm::WindowUtility::FillCharacter(
						{ static_cast<short>( pivot_point.x + ( cx * 2 ) ),	static_cast<short>( pivot_point.y + cy ) }
						, 'S'
					);

					r2cm::WindowUtility::FillColor(
						{ static_cast<short>( pivot_point.x + ( cx * 2 ) ),	static_cast<short>( pivot_point.y + cy ) }
						, r2cm::WindowUtility::eColor::FG_Red
					);
				}
			}
		}

		r2cm::WindowUtility::MoveCursorPoint( { static_cast<short>( pivot_point.x ), static_cast<short>( pivot_point.y + snake.GetHeight() ) } );
	}
}