#pragma once

#include "r2/r2_Grid.h"

namespace psm
{

	//
	// # �� ��Ȳ �м�
	// > �ʿ��� ����� Queue�� ���� ������ ��� �ذ� �ȴ�.
	//
	// # ���ϴ� ��
	// > index �� ���� ���� ������ �޸� ���� �Ҵ����� ���� ������ ������ �ʹ�.
	//
	// # �ذ�å
	// > 1. ����� �Ǿ��� Array ��� Grid �� �����.
	// > 2. Grid�� Cell�� ListNode ������� ���� ���� ���� �� �ְ� �Ѵ�.
	// > 3. Add �Լ��� �Ҹ��� �ش� �׸����� ListNode �� �����ͼ� �ܹ��� List�� ���´�.
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