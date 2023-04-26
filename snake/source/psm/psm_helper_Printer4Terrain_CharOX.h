#pragma once

#include "r2/r2_NoneCopyable.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "psm/psm_Terrain.h"

namespace psm_helper
{
	class Printer4Terrain_CharOX : private r2::NoneCopyable
	{
	private:
		Printer4Terrain_CharOX() = delete;

	public:
		inline static void Print( r2cm::WindowUtility::CursorPoint pivot, const short offset_x, const short offset_y, uint16_t space_h, uint16_t space_v, const psm::Terrain& container )
		{
			//
			//
			//
			pivot.x += offset_x;
			pivot.y += offset_y;

			//
			//
			//
			space_h = ( space_h > 0 ? space_h : 1 );
			space_v = ( space_v > 0 ? space_v : 1 );

			//
			// Draw
			//
			for( uint32_t cy = 0; cy < container.GetHeight(); ++cy )
			{
				for( uint32_t cx = 0; cx < container.GetWidth(); ++cx )
				{
					if( psm::eCellType::Open == container.Get( cx, cy ) )
					{
						r2cm::WindowUtility::FillColor(
							{
									static_cast<short>( pivot.x + ( cx * space_h ) )
								,	static_cast<short>( pivot.y + ( cy * space_v ) )
							}
							, r2cm::WindowUtility::eColor::BG_Blue | r2cm::WindowUtility::eColor::FG_White
						);
						r2cm::WindowUtility::FillCharacter(
							{
									static_cast<short>( pivot.x + ( cx * space_h ) )
								,	static_cast<short>( pivot.y + ( cy * space_v ) )
							}
							, 'o'
						);
					}
					else
					{
						r2cm::WindowUtility::FillCharacter(
							{
									static_cast<short>( pivot.x + ( cx * space_h ) )
								,	static_cast<short>( pivot.y + ( cy * space_v ) )
							}
							, 'x'
						);
					}
				}
			}

			//
			// Move Cursor
			//
			r2cm::WindowUtility::MoveCursorPoint( {
					0
				,	static_cast<short>( pivot.y + ( container.GetMaxY() * space_v ) + 1 )
				} );
		}

		inline static void Print( const short offset_x, const short offset_y, uint16_t space_h, uint16_t space_v, const psm::Terrain& container )
		{
			const auto pivot = r2cm::WindowUtility::GetCursorPoint();
			Print( pivot, offset_x, offset_y, space_h, space_v, container );
		}

		inline static void Print( const short offset_x, const short offset_y, const psm::Terrain& container )
		{
			Print( offset_x, offset_y, 2, 1, container );
		}

		inline static void Print( const psm::Terrain& container )
		{
			Print( 0, 0, 2, 1, container );
		}


		inline static void Print( const r2cm::WindowUtility::CursorPoint pivot, const short offset_x, const short offset_y, const psm::Terrain& container )
		{
			Print( pivot, offset_x, offset_y, 2, 1, container );
		}
	};
}