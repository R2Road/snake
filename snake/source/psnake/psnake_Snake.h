#pragma once

#include "r2/r2_Grid.h"

namespace psnake
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
		using Cell = bool;
		using ContainerT = r2::Grid<Cell>;
		using ConstIteratorT = typename ContainerT::ConstIteratorT;

		Snake( const uint32_t width, const uint32_t height );

		//
		// Iteration
		//
		ConstIteratorT begin() const
		{
			return mContainer.begin();
		}
		ConstIteratorT end() const
		{
			return mContainer.end();
		}

		//
		// Getter
		//
		uint32_t GetWidth() const
		{
			return mContainer.GetWidth();
		}
		uint32_t GetHeight() const
		{
			return mContainer.GetHeight();
		}
		uint32_t GetMaxX() const
		{
			return mContainer.GetWidth() - 1;
		}
		uint32_t GetMaxY() const
		{
			return mContainer.GetHeight() - 1;
		}
		uint32_t Size() const
		{
			return static_cast<uint32_t>( mContainer.GetSize() );
		}
		bool IsIn( const int32_t x, const int32_t y ) const;

		//
		//
		//
		void Add( const uint32_t x, const uint32_t y );
		void Remove( const uint32_t x, const uint32_t y );

		//
		//
		//
		bool Get( const uint32_t x, const uint32_t y ) const;

	private:
		ContainerT mContainer;
	};
}