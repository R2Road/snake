#pragma once

#include <memory>

#include "r2bix/r2node_SceneNode.h"
#include "psm/psm_GameCore.h"

namespace psnake_scene
{
	class CompanyScene : public r2node::SceneNode
	{
	private:
		CompanyScene( r2base::Director& director, psnake::GameCoreUp&& game_core );

	public:
		static r2node::SceneNodeUp Create( r2base::Director& director, psnake::GameCoreUp&& game_core );

	private:
		bool Init() override;
	public:
		void Update( const float delta_time ) override;

	private:
		psnake::GameCoreUp mGameCore;
	};
}