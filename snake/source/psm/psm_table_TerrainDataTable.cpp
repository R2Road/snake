#include "psm_table_TerrainDataTable.h"

namespace psm_table
{
	void TerrainDataTable::Load()
	{
		if( !mContainer.empty() )
		{
			return;
		}

		const psm::eCellType cO = psm::eCellType::Open;
		const psm::eCellType cX = psm::eCellType::Close;

		//
		// 1 : Dummy 1
		//
		mContainer.emplace( 1, TerrainData{ 4, 4, {
				cX		, cX		, cX		,cX
			,	cX		, cO		, cO		,cX
			,	cX		, cO		, cO		,cX
			,	cX		, cX		, cX		,cX
		} } );
	}

	const psm_table::TerrainData& TerrainDataTable::Get( const int index ) const
	{
		auto itr = mContainer.find( index );
		if( mContainer.end() != itr )
		{
			return itr->second;
		}

		static psm_table::TerrainData dummy;
		return dummy;
	}
}