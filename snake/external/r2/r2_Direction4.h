#pragma once

#include "r2_Direction4State.h"

namespace r2
{
	class Direction4
	{
	public:
		Direction4();
		explicit Direction4( const eDirection4State state );
		explicit Direction4( const int x, const int y );

		//
		//
		//
		bool operator==( const Direction4& other ) const
		{
			return other.mState == mState;
		}
		bool operator!=( const Direction4& other ) const
		{
			return !( operator==( other ) );
		}

		//
		//
		//
		void SetState( const eDirection4State new_state );
		eDirection4State GetState() const
		{
			return mState;
		}
		int GetX() const
		{
			return mX;
		}
		int GetY() const
		{
			return mY;
		}

		//
		//
		//
		void Rotate( const bool is_right = true );
		void Rotate( const bool direction_right, const int rotate_count );

	private:
		eDirection4State mState;
		int mX;
		int mY;
	};
}
