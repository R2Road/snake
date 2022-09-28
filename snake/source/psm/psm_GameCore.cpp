#include "psm_GameCore.h"

#include <new>

namespace psm
{
	GameCore::GameCore() : mTerrain( 4, 4 ), mSnake( 4, 4 )
	{}

	GameCoreUp GameCore::Create()
	{
		return GameCoreUp( new (std::nothrow) GameCore );
	}

	void GameCore::Reset()
	{
		mTerrain.Fill( {
				psm::eCellType::Close		, psm::eCellType::Close		, psm::eCellType::Close		,psm::eCellType::Close
			,	psm::eCellType::Close		, psm::eCellType::Open		, psm::eCellType::Open		,psm::eCellType::Close
			,	psm::eCellType::Close		, psm::eCellType::Open		, psm::eCellType::Open		,psm::eCellType::Close
			,	psm::eCellType::Close		, psm::eCellType::Close		, psm::eCellType::Close		,psm::eCellType::Close
		} );

		mSnake.Reset( mTerrain.GetWidth(), mTerrain.GetHeight() );
	}
}