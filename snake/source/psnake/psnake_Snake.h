#pragma once

#include "r2/r2_Grid.h"

namespace psnake
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