#include "psnake_GameCore.h"

#include <new>

namespace psnake
{
	GameCore::GameCore() : mTerrain( 4, 4 ), mSnake( 4, 4 )
	{}

	GameCoreUp GameCore::Create()
	{
		return GameCoreUp( new (std::nothrow) GameCore );
	}
}