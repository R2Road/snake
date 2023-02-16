#pragma once

#include <vector>

#include "r2/r2_Assert.h"

#include "psm_constant.h"

namespace psm_table
{
	struct TerrainData
	{
	public:
		TerrainData() : width( 1 ), height( 1 ), data( { 0 } )
		{}

		TerrainData( const int new_width, const int new_height, const std::initializer_list<psm::eCellType> new_data ) :
			width( new_width )
			, height( new_height )
			, data( new_width * new_height, psm::eCellType::Open )
		{
			R2ASSERT( 0 < width , "" );
			R2ASSERT( 0 < height, "" );
			
			memcpy_s(
				&data[0]
				, data.size() * sizeof( psm::eCellType )
				, &( *new_data.begin() )
				, ( new_data.size() > data.size() ? data.size() * sizeof( psm::eCellType ) : new_data.size() * sizeof( psm::eCellType ) )
			);
		}

		int width;
		int height;
		std::vector<psm::eCellType> data;
	};
}