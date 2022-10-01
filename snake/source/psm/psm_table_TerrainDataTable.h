#pragma once

#include <unordered_map>

#include "r2cm/r2cm_Singleton.h"

#include "psm_constant.h"
#include "psm_table_TerrainData.h"

namespace psm_table
{
	class TerrainDataTable : public r2cm::SingleTon< TerrainDataTable>
	{
	public:
		void Load();

		const TerrainData& Get( const int index ) const;

	private:
		std::unordered_map<int, TerrainData> mContainer;
	};
}