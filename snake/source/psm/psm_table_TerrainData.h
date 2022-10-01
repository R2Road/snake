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
			, data( new_data )
		{
			R2ASSERT( new_width * new_height == new_data.size(), "" );
		}

		int width;
		int height;
		std::vector<psm::eCellType> data;
	};
}