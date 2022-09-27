#include "psnake_Snake.h"

#include "r2/r2_Assert.h"

namespace psnake
{
	Snake::Snake( const uint32_t width, const uint32_t height ) :
		mContainer( width, height, Node{} )
	{}

	bool Snake::IsIn( const int32_t x, const int32_t y ) const
	{
		return ( 0 <= x && 0 <= y && static_cast<int>( GetWidth() ) > x && static_cast<int>( GetHeight() ) > y );
	}

	void Snake::Add( const uint32_t x, const uint32_t y )
	{
		R2ASSERT( false == Get( x, y ), "" );

		mContainer.Set( x, y, Node{ true } );
	}
	void Snake::Remove( const uint32_t x, const uint32_t y )
	{
		R2ASSERT( true == Get( x, y ), "" );

		mContainer.Set( x, y, Node{ false } );
	}

	bool Snake::Get( const uint32_t x, const uint32_t y ) const
	{
		return mContainer.Get( x, y ).value;
	}
}