#include "psm_scene_EntryScene.h"

#include "r2bix/r2base_Director.h"

#include "psm_GameCore.h"
#include "psm_table_TextureTable.h"
#include "psm_table_TextureFrameAnimationTable.h"

#include "psm_scene_CompanyScene.h"

namespace psm_scene
{
	class EntrySceneComponent : public r2base::Component<EntrySceneComponent>
	{
	public:
		EntrySceneComponent( r2base::Node& owner_node ) : r2base::Component<EntrySceneComponent>( owner_node ) {}

		//
		//
		//
		void Update( const float delta_time ) override
		{
			r2base::iComponent::Update( delta_time );

			//
			// Table Load
			//
			psm_table::TextureTable().Load();
			psm_table::TextureFrameAnimationTable().Load();

			//
			// Scene
			//
			auto next_scene = psm_scene::CompanyScene::Create( mOwnerNode.GetDirector(), psm::GameCore::Create() );

			//
			// Go Next 
			//
			mOwnerNode.GetDirector().Setup( std::move( next_scene ) );
		}
	};

	r2node::SceneNodeUp EntryScene::Create( r2base::Director& director )
	{
		auto ret( r2node::SceneNode::Create( director ) );
		if( ret )
		{
			ret->AddComponent<EntrySceneComponent>();
		}

		return ret;
	}
}