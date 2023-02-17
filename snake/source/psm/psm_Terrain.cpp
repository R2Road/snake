#include "psm_Terrain.h"

#include "r2/r2_Assert.h"

namespace psm
{
	Terrain::Terrain() :
		mGridIndexConverter( 1, 1 )
		, mContainer( 1, eCellType::Close )
	{}
	Terrain::Terrain( const uint32_t width, const uint32_t height ) :
		mGridIndexConverter( width, height )
		, mContainer( width * height, eCellType::Close )
	{}
	Terrain::Terrain( const psm_table::TerrainData& terrain_data ) :
		mGridIndexConverter( terrain_data.width, terrain_data.height )
		, mContainer( terrain_data.data )
	{}



	bool Terrain::IsIn( const int32_t x, const int32_t y ) const
	{
		return ( 0 <= x && 0 <= y && static_cast<int>( GetWidth() ) > x && static_cast<int>( GetHeight() ) > y );
	}



	void Terrain::Reset( const psm_table::TerrainData& terrain_data )
	{
		mGridIndexConverter = r2::GridIndexConverter( terrain_data.width, terrain_data.height );
		mContainer = terrain_data.data;
	}



	eCellType Terrain::Get( const uint32_t x, const uint32_t y ) const
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		return mContainer[target_linear_index];
	}
}