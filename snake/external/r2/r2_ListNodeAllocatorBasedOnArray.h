#pragma once

#include <array>

#include "r2_ListNode.h"
#include "r2_Assert.h"

namespace r2
{
	template<typename T, uint32_t N>
	class ListNodeAllocatorBasedOnArray
	{
	public:
		using ValueT = T;
		using SizeT = uint32_t;

		using NodeT = ListNode<ValueT>;
		using ContainerT = std::array<NodeT, N>;

		ListNodeAllocatorBasedOnArray() : mContainer(), mHead( nullptr ), mSize( 0u )
		{
			Clear();
		}

		//
		//
		//
		SizeT Size() const
		{
			return mSize;
		}
		SizeT GetAllocatedSize() const
		{
			return static_cast<SizeT>( mContainer.size() );
		}
		bool Empty() const
		{
			return ( 0u == mSize );
		}

		//
		//
		//
		void Clear()
		{
			//
			// Cleanup
			//
			for( auto& n : mContainer )
			{
				n.pPrev = nullptr;
				n.pNext = nullptr;
			}

			//
			// Build Chain
			//
			mHead = &( *mContainer.begin() );
			if( 1 < mContainer.size() )
			{
				auto current_node = mHead;

				auto cur = mContainer.begin();
				++cur;
				for( auto end = mContainer.end(); end != cur; ++cur )
				{
					cur->pPrev = current_node;
					current_node->pNext = &( *cur );

					current_node = current_node->pNext;
				}
			}
			mSize = static_cast<uint32_t>( mContainer.size() );
		}

		//
		//
		//
		NodeT* Pop()
		{
			R2ASSERT( nullptr != mHead, "Empty : ListNodeAllocatorBasedOnArray::Pop()" );

			NodeT* ret = mHead;

			if( nullptr != ret )
			{
				mHead = ret->pNext;
				--mSize;
			}

			return ret;
		}
		void Push( NodeT* rest_node )
		{
			rest_node->pPrev = nullptr;
			rest_node->pNext = nullptr;

			if( nullptr == mHead )
			{
				mHead = rest_node;
			}
			else
			{
				rest_node->pNext = mHead;
				mHead = rest_node;
			}

			++mSize;
		}

	private:
		ContainerT mContainer;
		NodeT* mHead;
		SizeT mSize;
	};
}