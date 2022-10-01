#include "psm_Snake.h"

#include "r2/r2_Assert.h"

namespace psm
{
	Snake::Snake() :
		mContainer( 1, 1, Node{} )
		, mEndNode()
	{
		mEndNode.prev = &mEndNode;
		mEndNode.next = &mEndNode;
	}
	Snake::Snake( const uint32_t width, const uint32_t height ) :
		mContainer( width, height, Node{} )
		, mEndNode()
	{
		mEndNode.prev = &mEndNode;
		mEndNode.next = &mEndNode;
	}

	bool Snake::IsIn( const int32_t x, const int32_t y ) const
	{
		return ( 0 <= x && 0 <= y && static_cast<int>( GetWidth() ) > x && static_cast<int>( GetHeight() ) > y );
	}

	void Snake::Reset( const uint32_t width, const uint32_t height )
	{
		mContainer.Reset( width, height, Node{} );

		mEndNode.prev = &mEndNode;
		mEndNode.next = &mEndNode;
	}
	void Snake::PushFront( const uint32_t x, const uint32_t y )
	{
		R2ASSERT( false == Get( x, y ), "" );

		auto& node = mContainer.Get( x, y );
		node.value = true;

		//
		// �� ����� ��, �� ����
		//
		node.prev = &mEndNode;
		node.next = mEndNode.next;

		//
		// ���� �Ӹ� ���� �� �Ӹ� ��� ����
		//
		node.next->prev = &node;

		//
		// End Node �� �� ��� ����
		//
		mEndNode.next = &node;
		
	}
	void Snake::PopTail()
	{
		if( &mEndNode == mEndNode.prev )
		{
			return;
		}

		auto target_node = mEndNode.prev;
		target_node->value = false;

		//
		// �� ���� ���� End Node ����
		//
		( target_node->prev )->next = &mEndNode;

		//
		// End Node �� �� ���� ��� ����
		//
		mEndNode.prev = ( target_node->prev );

		//
		// Clear
		//
		target_node->prev = nullptr;
		target_node->next = nullptr;
	}

	const Snake::Node& Snake::GetNode( const uint32_t x, const uint32_t y ) const
	{
		return mContainer.Get( x, y );
	}
	bool Snake::Get( const uint32_t x, const uint32_t y ) const
	{
		return mContainer.Get( x, y ).value;
	}
}