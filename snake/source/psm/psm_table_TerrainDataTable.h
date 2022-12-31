#pragma once

#include <unordered_map>

#include "r2/r2_SingletonWithStaticFunction.h"

#include "psm_constant.h"
#include "psm_table_TerrainData.h"

namespace psm_table
{
	class TerrainDataTable : public r2::SingletonWithStaticFunction<TerrainDataTable>
	{
	public:
		void Load();

		const TerrainData& Get( const int index ) const;

	private:
		std::unordered_map<int, TerrainData> mContainer;
	};
}