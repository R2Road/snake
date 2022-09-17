#pragma once

#include <memory>

#include "r2_ListNode.h"

namespace r2
{
	template<typename T>
	class ListIterator
	{
	public:
		using ValueT = T;
		using NodeT = ListNode<ValueT>;

		ListIterator( NodeT* target_node ) : mTargetNode( target_node )
		{}

		ListIterator& operator++()
		{
			mTargetNode = mTargetNode->pNext;
			return ( *this );
		}
		ListIterator& operator--()
		{
			mTargetNode = mTargetNode->pPrev;
			return ( *this );
		}

		bool operator==( const ListIterator& other ) const
		{
			return mTargetNode == other.mTargetNode;
		}
		bool operator!=( const ListIterator& other ) const
		{
			return !operator==( other );
		}

		ValueT& operator*() const
		{
			return mTargetNode->MyValue;
		}
		ValueT* operator->() const
		{
			return std::addressof( *( *this ) ); // call : operator*()
		}

		NodeT* mTargetNode;
	};



	template<typename T>
	class ListReverseIterator
	{
	public:
		using ValueT = T;
		using NodeT = ListNode<ValueT>;

		ListReverseIterator( NodeT* target_node ) : mTargetNode( target_node )
		{}

		ListReverseIterator& operator++()
		{
			mTargetNode = mTargetNode->pPrev;
			return ( *this );
		}
		ListReverseIterator& operator--()
		{
			mTargetNode = mTargetNode->pNext;
			return ( *this );
		}

		bool operator==( const ListReverseIterator& other ) const
		{
			return mTargetNode == other.mTargetNode;
		}
		bool operator!=( const ListReverseIterator& other ) const
		{
			return !operator==( other );
		}

		ValueT& operator*() const
		{
			return mTargetNode->MyValue;
		}
		ValueT* operator->() const
		{
			return std::addressof( *( *this ) ); // call : operator*()
		}

		NodeT* mTargetNode;
	};
}