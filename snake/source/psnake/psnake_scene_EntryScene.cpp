#include "psnake_scene_EntryScene.h"

#include "r2bix/r2base_Director.h"

#include "psnake_table_TextureTable.h"
#include "psnake_table_TextureFrameAnimationTable.h"

#include "psnake_scene_CompanyScene.h"

namespace psnake_scene
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
			psnake_table::TextureTable::GetInstance().Load();
			psnake_table::TextureFrameAnimationTable::GetInstance().Load();

			//
			// Scene
			//
			auto next_scene = psnake_scene::CompanyScene::Create( mOwnerNode.GetDirector() );

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