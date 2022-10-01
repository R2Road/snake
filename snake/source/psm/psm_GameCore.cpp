#include "psm_GameCore.h"

#include <new>

namespace psm
{
	GameCore::GameCore() : mTerrain(), mSnake()
	{}

	GameCoreUp GameCore::Create()
	{
		return GameCoreUp( new (std::nothrow) GameCore );
	}

	void GameCore::Reset( const psm_table::TerrainData& terrain_data )
	{
		mTerrain.Reset( terrain_data );
		mSnake.Reset( terrain_data.width, terrain_data.height );
	}
}