#pragma once

#include "r2/r2_Grid.h"

namespace psm
{

	//
	// # 현 상황 분석
	// > 필요한 기능은 Queue를 쓰는 것으로 모두 해결 된다.
	//
	// # 원하는 것
	// > index 를 통한 빠른 참조와 메모리 사전 할당으로 인한 이점을 누리고 싶다.
	//
	// # 해결책
	// > 1. 기반이 되어줄 Array 기반 Grid 를 만든다.
	// > 2. Grid의 Cell을 ListNode 기반으로 만들어서 따로 엮을 수 있게 한다.
	// > 3. Add 함수가 불리면 해당 그리드의 ListNode 를 가져와서 단방향 List로 엮는다.
	//

	class Snake
	{
	public:
		struct Node
		{
			bool value = false;

			Node* prev = nullptr;
			Node* next = nullptr;
		};

		using Cell = Node;
		using ContainerT = r2::Grid<Cell>;
		using ConstIteratorT = typename ContainerT::ConstIteratorT;

		Snake();
		Snake( const uint32_t width, const uint32_t height );

		//
		// Getter
		//
		std::size_t GetWidth() const
		{
			return mContainer.GetWidth();
		}
		std::size_t GetHeight() const
		{
			return mContainer.GetHeight();
		}
		std::size_t GetMaxX() const
		{
			return mContainer.GetWidth() - 1;
		}
		std::size_t GetMaxY() const
		{
			return mContainer.GetHeight() - 1;
		}
		std::size_t Size() const
		{
			return mContainer.GetSize();
		}
		bool IsIn( const int32_t x, const int32_t y ) const;

		//
		//
		//
		void Reset( const uint32_t width, const uint32_t height );
		void Push( const uint32_t x, const uint32_t y );
		void Pop();

		//
		//
		//
		const Node& GetHeadNode() const
		{
			return *mEndNode.next;
		}
		const Node& GetEndNode() const
		{
			return mEndNode;
		}
		const Node& GetNode( const uint32_t x, const uint32_t y ) const;
		bool Get( const uint32_t x, const uint32_t y ) const;

	private:
		ContainerT mContainer;
		Node mEndNode;
	};
}