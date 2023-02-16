#pragma once

#include <vector>

#include "r2/r2_Assert.h"

#include "psm_constant.h"

namespace psm_table
{
	struct TerrainData
	{
	public:
		using CellT = psm::eCellType;

		TerrainData() : width( 1 ), height( 1 ), data( { 0 } )
		{}

		TerrainData( const int new_width, const int new_height, const std::initializer_list<CellT> new_data ) :
			width( new_width )
			, height( new_height )
			, data( new_width * new_height, CellT::Open )
		{
			R2ASSERT( 0 < width , "" );
			R2ASSERT( 0 < height, "" );
			
			memcpy_s(
				&data[0]
				, data.size() * sizeof( CellT )
				, &( *new_data.begin() )
				, ( new_data.size() > data.size() ? data.size() * sizeof( CellT ) : new_data.size() * sizeof( CellT ) )
			);
		}

		int width;
		int height;
		std::vector<CellT> data;
	};
}