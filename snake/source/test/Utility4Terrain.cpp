#include "Utility4Terrain.h"

#include <iomanip>

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "psnake/psnake_Terrain.h"

void Utility4Terrain::Draw( const short x, const short y, const psnake::Terrain& terrain )
{
	const r2cm::WindowUtility::CursorPoint pivot_point{ x, y };

	for( uint32_t cy = 0; cy < terrain.GetHeight(); ++cy )
	{
		for( uint32_t cx = 0; cx < terrain.GetWidth(); ++cx )
		{
			r2cm::WindowUtility::FillCharacter(
				{ static_cast<short>( pivot_point.x + ( cx * 2 ) ),	static_cast<short>( pivot_point.y + cy ) }
				, ( psnake::eCellType::Open == terrain.Get( cx, cy ) ? 'o' : 'x' )
			);
		}
	}

	r2cm::WindowUtility::MoveCursorPoint( { static_cast<short>( pivot_point.x ), static_cast<short>( pivot_point.y + terrain.GetHeight() ) } );
}