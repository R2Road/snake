#pragma once

#include "r2_ListIterator.h"
#include "r2_ListNodeAllocatorBasedOnArray.h"

#include "r2_Assert.h"

namespace r2
{
	template<typename T, uint32_t N>
	class QueueBasedOnArray
	{
	public:
		using ValueT = T;
		using SizeT = uint32_t;

		using NodeT = ListNode<ValueT>;
		using ContainerT = ListNodeAllocatorBasedOnArray<ValueT, N + 1u>; // N + Head

		using IteratorT = ListIterator<ValueT>;
		using ReverseIteratorT = ListReverseIterator<ValueT>;

		QueueBasedOnArray() : mContainer(), mEnd( nullptr ), mSize( 0u )
		{
			Clear();
		}

		//
		// Iteration
		//
		IteratorT begin() { return IteratorT( mEnd->pNext ); }
		IteratorT end() { return IteratorT( mEnd ); }
		ReverseIteratorT rbegin() const { return ReverseIteratorT( mEnd->pPrev ); }
		ReverseIteratorT rend() const { return ReverseIteratorT( mEnd ); }

		void Clear()
		{
			//
			// Clear
			//
			mContainer.Clear();

			//
			// End
			//
			mEnd = mContainer.Pop();
			mEnd->pPrev = mEnd;
			mEnd->pNext = mEnd;

			mSize = 0u;
		}

	public:
		SizeT Size() const
		{
			return mSize;
		}
		bool Empty() const
		{
			return ( 0u == mSize );
		}
		SizeT GetAllocatedSize() const
		{
			return mContainer.GetAllocatedSize();
		}
		SizeT GetRemainSpaceSize() const
		{
			return mContainer.Size();
		}

		//
		// Push Back
		//
		void Put( const ValueT& new_value )
		{
			if( mContainer.Empty() )
			{
				return;
			}

			auto new_back_node = mContainer.Pop();
			new_back_node->MyValue = new_value;

			// Prev
			mEnd->pPrev->pNext = new_back_node;

			// New
			new_back_node->pPrev = mEnd->pPrev;
			new_back_node->pNext = mEnd;

			// Next
			mEnd->pPrev = new_back_node;

			++mSize;
		}

		//
		// Pop Front
		//
		ValueT Get()
		{
			ValueT ret = mEnd->pNext->MyValue;
			erase( mEnd->pNext );

			return ret;
		}

	private:
		void erase( NodeT* target_node )
		{
			if( mEnd == target_node )
			{
				return;
			}

			auto pPrev = target_node->pPrev;
			auto pNext = target_node->pNext;

			pPrev->pNext = pNext;
			pNext->pPrev = pPrev;

			--mSize;

			mContainer.Push( target_node );
		}

	private:
		ContainerT mContainer;

		NodeT* mEnd;
		SizeT mSize;
	};
}