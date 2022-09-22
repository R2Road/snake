#include "psnake_GameCore.h"

#include <new>

namespace psnake
{
	GameCoreUp GameCore::Create()
	{
		return GameCoreUp( new (std::nothrow) GameCore );
	}
}