#pragma once

#include <vector>

#include "r2/r2_GridIndexConverter.h"
#include "psm_constant.h"
#include "psm_table_TerrainData.h"

namespace psm
{
	class Terrain
	{
	public:
		using Cell = eCellType;
		using ContainerT = std::vector<Cell>;
		using ConstIteratorT = typename ContainerT::const_iterator;

		Terrain();
		Terrain( const uint32_t width, const uint32_t height );
		Terrain( const psm_table::TerrainData& terrain_data );

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
		void Reset( const psm_table::TerrainData& terrain_data );

		//
		//
		//
		eCellType Get( const uint32_t x, const uint32_t y ) const;

	private:
		r2::GridIndexConverter mGridIndexConverter;
		ContainerT mContainer;
	};
}