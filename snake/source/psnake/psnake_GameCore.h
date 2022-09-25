#pragma once

#include <memory>

#include "psnake_Terrain.h"
#include "psnake_Snake.h"

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
		const Snake& GetSnake() const
		{
			return mSnake;
		}

		//
		//
		//
		void Reset();

	private:
		Terrain mTerrain;
		Snake mSnake;
	};
}