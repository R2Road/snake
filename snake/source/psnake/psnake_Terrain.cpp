#include "psnake_Terrain.h"

#include "r2/r2_Assert.h"

namespace psnake
{
	Terrain::Terrain( const uint32_t width, const uint32_t height ) :
		mGridIndexConverter( width, height )
		, mContainer( width * height, { eCellType::Road } )
	{}

	bool Terrain::IsIn( const int32_t x, const int32_t y ) const
	{
		return ( 0 <= x && 0 <= y && static_cast<int>( GetWidth() ) > x && static_cast<int>( GetHeight() ) > y );
	}

	void Terrain::Fill( const std::initializer_list<eCellType> datas )
	{
		R2ASSERT( datas.size() == mContainer.size(), "" );

		std::size_t i = 0u;
		for( const auto c : datas )
		{
			mContainer[i].type = c;

			++i;
		}
	}
}