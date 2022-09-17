#pragma once

#include <vector>

#include "r2_Assert.h"

namespace r2
{
	template<typename T, T Default_Value = 0u >
	class Queue
	{
	public:
		using ValueT = T;
	private:
		using ContainerT = std::vector<int>;

	public:
		Queue() : mContainer(), mHead( 0u ), mTail( 0u )
		{}

		//
		// Iteration
		//
		ContainerT::const_iterator begin() const { return mContainer.begin(); }
		ContainerT::const_iterator end() const { return mContainer.end(); }
		ContainerT::iterator begin() { return mContainer.begin(); }
		ContainerT::iterator end() { return mContainer.end(); }

		//
		// for Test
		//
		int GetHead() const { return mHead; }
		int GetTail() const { return mTail; }

		//
		//
		//
		bool Empty() const { return mHead == mTail; }
		const ContainerT& GetContainer() const { return mContainer; }

		void Reset()
		{
			for( auto cur = mContainer.begin(), end = mContainer.end(); end != cur; ++cur )
			{
				*cur = Default_Value;
			}
			mHead = 0u;
			mTail = 0u;
		}
		void Resize( const std::size_t size )
		{
			mContainer.resize( size, Default_Value );
		}

		void Push( const ValueT new_value )
		{
			if( mTail >= mContainer.size() )
			{
				R2ASSERT( false, "" );
				return;
			}

			mContainer[mTail++] = new_value;
		}
		const ValueT Pop()
		{
			if( Empty() )
			{
				R2ASSERT( false, "" );
				return Default_Value;
			}

			return mContainer[mHead++];
		}

	private:
		ContainerT mContainer;
		std::size_t mHead;
		std::size_t mTail;
	};
}