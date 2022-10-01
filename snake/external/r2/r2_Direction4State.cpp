#include "r2_Direction4State.h"

#include "r2_Random.h"

namespace r2
{
	eDirection4State GetRandomDirection4State()
	{
		return static_cast<eDirection4State>( r2::Random::GetInt(
			static_cast<int>( eDirection4State::FIRST )
			, static_cast<int>( eDirection4State::END )
		) );
	}
	eDirection4State GetReverseDirection4State( const eDirection4State _state )
	{
		int ret = static_cast<int>( _state ) + 2;

		if( static_cast<int>( eDirection4State::END ) < ret )
		{
			ret -= ( static_cast<int>( eDirection4State::END ) + 1 );
		}

		return static_cast<eDirection4State>( ret );
	}

	eDirection4State ConvertInteger2Direction4State( const int value )
	{
		if( static_cast<int>( eDirection4State::FIRST ) <= value && static_cast<int>( eDirection4State::END ) >= value )
		{
			return static_cast<eDirection4State>( value );
		}

		return eDirection4State::FIRST;
	}
	eDirection4State ConvertPoint2Direction4State( const int x, const int y )
	{
		if( 1 <= x )
		{
			return eDirection4State::RIGHT;
		}
		else if( -1 >= x )
		{
			return eDirection4State::LEFT;
		}
		else if( 1 <= y )
		{
			return eDirection4State::UP;
		}
		else if( -1 >= y )
		{
			return eDirection4State::DOWN;
		}

		return eDirection4State::NONE;
	}
}
