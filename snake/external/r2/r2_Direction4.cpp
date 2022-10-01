#include "r2_Direction4.h"

namespace r2
{
	void ConvertDirection4State2Point( const eDirection4State state, int& out_x, int& out_y )
	{
		switch( state )
		{
		case eDirection4State::UP: out_x = 0; out_y = 1; break;
		case eDirection4State::RIGHT: out_x = 1; out_y = 0; break;
		case eDirection4State::DOWN: out_x = 0; out_y = -1; break;
		case eDirection4State::LEFT: out_x = -1; out_y = 0; break;
		}
	}

	Direction4::Direction4() :
		mState( eDirection4State::UP )
		, mX( 0 )
		, mY( 0 )
	{
		ConvertDirection4State2Point( mState, mX, mY );
	}
	Direction4::Direction4( const eDirection4State state ) :
		mState( state )
		, mX( 0 )
		, mY( 0 )
	{
		ConvertDirection4State2Point( mState, mX, mY );
	}
	Direction4::Direction4( const int x, const int y ) :
		mState( eDirection4State::NONE )
		, mX( 0 )
		, mY( 0 )
	{
		mState = ConvertPoint2Direction4State( x, y );
		ConvertDirection4State2Point( mState, mX, mY );
	}

	void Direction4::Rotate( const bool is_right )
	{
		switch( mState )
		{
		case eDirection4State::UP: mState = ( is_right ? eDirection4State::RIGHT : eDirection4State::LEFT ); break;
		case eDirection4State::RIGHT: mState = ( is_right ? eDirection4State::DOWN : eDirection4State::UP ); break;
		case eDirection4State::DOWN: mState = ( is_right ? eDirection4State::LEFT : eDirection4State::RIGHT ); break;
		case eDirection4State::LEFT: mState = ( is_right ? eDirection4State::UP : eDirection4State::DOWN ); break;
		}

		ConvertDirection4State2Point( mState, mX, mY );
	}
	void Direction4::Rotate( const bool direction_right, const int rotate_count )
	{
		for( int i = 0; rotate_count > i; ++i )
		{
			Rotate( direction_right );
		}
	}
}
