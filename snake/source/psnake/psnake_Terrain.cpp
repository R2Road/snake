#include "psnake_Terrain.h"

namespace psnake
{
	Terrain::Terrain( const uint32_t width, const uint32_t height ) :
		mGridIndexConverter( width, height )
		, mContainer( width * height, false )
	{}

	bool Terrain::IsIn( const int32_t x, const int32_t y ) const
	{
		return ( 0 <= x && 0 <= y && static_cast<int>( GetWidth() ) > x && static_cast<int>( GetHeight() ) > y );
	}
}