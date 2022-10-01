#include "psm_table_TerrainDataTable.h"

namespace psm_table
{
	void TerrainDataTable::Load()
	{
		if( !mContainer.empty() )
		{
			return;
		}

		//
		// 1 : Dummy 1
		//
		mContainer.emplace( 1, TerrainData{ 4, 4, {
				psm::eCellType::Close		, psm::eCellType::Close		, psm::eCellType::Close		,psm::eCellType::Close
			,	psm::eCellType::Close		, psm::eCellType::Open		, psm::eCellType::Open		,psm::eCellType::Close
			,	psm::eCellType::Close		, psm::eCellType::Open		, psm::eCellType::Open		,psm::eCellType::Close
			,	psm::eCellType::Close		, psm::eCellType::Close		, psm::eCellType::Close		,psm::eCellType::Close
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