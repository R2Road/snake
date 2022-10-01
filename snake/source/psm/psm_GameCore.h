#pragma once

#include <memory>

#include "psm_Terrain.h"
#include "psm_Snake.h"

namespace psm
{
	using GameCoreUp = std::unique_ptr<class GameCore>;
	class GameCore
	{
	private:
		GameCore();

	public:
		static GameCoreUp Create();

		//
		//
		//
		const Terrain& GetTerrain() const
		{
			return mTerrain;
		}
		const Snake& GetSnake() const
		{
			return mSnake;
		}

		//
		//
		//
		void Reset( const psm_table::TerrainData& terrain_data );

	private:
		Terrain mTerrain;
		Snake mSnake;
	};
}