#pragma once

#include <array>

#include "r2_ListIterator.h"
#include "r2_ListNodeAllocatorBasedOnArray.h"

#include "r2_Assert.h"

namespace r2
{
	template<typename T, uint32_t N>
	class ListBasedOnArray
	{
	public:
		using ValueT = T;
		using SizeT = uint32_t;

		using NodeT = ListNode<ValueT>;
		using ContainerT = ListNodeAllocatorBasedOnArray<ValueT, N + 1u>; // N + Head

		using IteratorT = ListIterator<ValueT>;
		//using iterator = ListIterator<ValueT>; // ...dev rule?
		using ReverseIteratorT = ListReverseIterator<ValueT>;

		ListBasedOnArray() : mContainer(), mEnd( nullptr ), mSize( 0u )
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
			// 4 Live
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
		SizeT GetRestNodeCount() const
		{
			return mContainer.Size();
		}

		void PushFront( const ValueT new_value )
		{
			if( mContainer.Empty() )
			{
				return;
			}

			auto new_front_node = mContainer.Pop();
			new_front_node->MyValue = new_value;

			// Prev
			mEnd->pNext->pPrev = new_front_node;

			// New
			new_front_node->pPrev = mEnd;
			new_front_node->pNext = mEnd->pNext;

			// NExt
			mEnd->pNext = new_front_node;

			++mSize;
		}
		void PushBack( const ValueT new_value )
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
		IteratorT Erase( IteratorT target )
		{
			if( end() == target )
			{
				return end();
			}

			auto pPrev = target.mTargetNode->pPrev;
			auto pNext = target.mTargetNode->pNext;

			pPrev->pNext = pNext;
			pNext->pPrev = pPrev;

			--mSize;

			mContainer.Push( target.mTargetNode );

			return IteratorT( pNext );
		}

	private:
		ContainerT mContainer;

		NodeT* mEnd;
		SizeT mSize;
	};
}