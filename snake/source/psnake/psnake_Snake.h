#pragma once

#include <vector>

#include "r2/r2_GridIndexConverter.h"

namespace psnake
{
	class Snake
	{
	public:
		using Cell = bool;
		using ContainerT = std::vector<Cell>;
		using ConstIteratorT = typename ContainerT::const_iterator;

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
			return mGridIndexConverter.GetWidth();
		}
		uint32_t GetHeight() const
		{
			return mGridIndexConverter.GetHeight();
		}
		uint32_t GetMaxX() const
		{
			return mGridIndexConverter.GetWidth() - 1;
		}
		uint32_t GetMaxY() const
		{
			return mGridIndexConverter.GetHeight() - 1;
		}
		uint32_t Size() const
		{
			return static_cast<uint32_t>( mContainer.size() );
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
		r2::GridIndexConverter mGridIndexConverter;
		ContainerT mContainer;
	};
}