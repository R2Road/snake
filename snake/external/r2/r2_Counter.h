#pragma once

#include <algorithm>
#include <numeric>
#include <type_traits>

#include "r2_Assert.h"

namespace r2
{
	template<typename T>
	class Counter
	{
	public:
		using ValueT = T;
		const ValueT ValueMAX = std::numeric_limits<ValueT>::max();

		Counter( const ValueT limit ) : mAlive( true ), mLimit( limit ), mCount( static_cast<ValueT>( 0 ) )
		{
			static_assert(
				std::is_same<char, ValueT>::value
				|| std::is_same<unsigned char, ValueT>::value
				|| std::is_same<short, ValueT>::value
				|| std::is_same<unsigned short, ValueT>::value
				|| std::is_same<int, ValueT>::value
				|| std::is_same<unsigned int, ValueT>::value
				|| std::is_same<long long int, ValueT>::value
				|| std::is_same<unsigned long long int, ValueT>::value
				, "r2r::Counter - Not Allowed Type"
			);
		}

		//
		//
		//
		bool IsAlive() const
		{
			return mAlive;
		}
		bool IsDie() const
		{
			return !mAlive;
		}
		ValueT GetCount() const
		{
			return mCount;
		}
		ValueT GetLimit() const
		{
			return mLimit;
		}

		//
		//
		//
		inline void ReStart()
		{
			mAlive = true;
			mCount = static_cast<ValueT>( 0 );
		}
		inline void Reset( const ValueT limit )
		{
			mLimit = limit;
			ReStart();
		}

		//
		//
		//
		inline bool Increase()
		{
			return Increase( 1 );
		}
		inline bool Increase( const ValueT increase_amount )
		{
			if( !mAlive )
			{
				return false;
			}

			increaseCount( increase_amount );

			return mAlive;
		}

	private:
		inline void increaseCount( ValueT increase_amount )
		{
			R2ASSERT( increase_amount <= ( ValueMAX - mCount ), "" );

			mCount = std::min( ValueMAX, mCount + increase_amount );
			mAlive = ( mLimit > mCount );
		}

	private:
		bool mAlive;
		ValueT mLimit;
		ValueT mCount;
	};
}
