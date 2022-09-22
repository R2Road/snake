#pragma once

#include <memory>

#include "psnake_Terrain.h"

namespace psnake
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

	private:
		Terrain mTerrain;
	};
}