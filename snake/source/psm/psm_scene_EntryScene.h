#pragma once

#include "r2bix/r2node_SceneNode.h"

namespace psm_scene
{
	class EntryScene : public r2node::SceneNode
	{
	private:
		EntryScene() = delete;

	public:
		static r2node::SceneNodeUp Create( r2base::Director& director );
	};
}