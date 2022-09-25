#include "psnake_Snake.h"

#include "r2/r2_Assert.h"

namespace psnake
{
	Snake::Snake( const uint32_t width, const uint32_t height ) :
		mGridIndexConverter( width, height )
		, mContainer( width * height, false )
	{}

	bool Snake::IsIn( const int32_t x, const int32_t y ) const
	{
		return ( 0 <= x && 0 <= y && static_cast<int>( GetWidth() ) > x && static_cast<int>( GetHeight() ) > y );
	}

	void Snake::Add( const uint32_t x, const uint32_t y )
	{
		R2ASSERT( false == Get( x, y ), "" );

		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		mContainer[target_linear_index] = true;
	}
	void Snake::Remove( const uint32_t x, const uint32_t y )
	{
		R2ASSERT( true == Get( x, y ), "" );

		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		mContainer[target_linear_index] = false;
	}

	bool Snake::Get( const uint32_t x, const uint32_t y ) const
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		return mContainer[target_linear_index];
	}
}