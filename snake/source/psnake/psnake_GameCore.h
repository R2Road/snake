#pragma once

#include <memory>

namespace psnake
{
	using GameCoreUp = std::unique_ptr<class GameCore>;
	class GameCore
	{
	private:
		GameCore() = default;

	public:
		static GameCoreUp Create();
	};
}