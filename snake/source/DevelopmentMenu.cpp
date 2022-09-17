#include "DevelopmentMenu.h"

#include <string>

#include "r2bix/r2base_Director.h"
#include "r2bix/r2base_VersionInfo.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_VersionInfo.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "psnake/psnake_DirectorConfig.h"
#include "psnake/psnake_VersionInfo.h"
#include "psnake/psnake_scene_EntryScene.h"

#include "test/TestMenu.h"

const char* DevelopmentMenu::GetTitle()
{
	static const std::string ret =
		std::string( "Development Menu" )
		+ " : <" + r2cm::VersionInfo.String4Version + ">"
		+ " : <" + r2base::VersionInfo.String4Version + ">"
		+ " : <" + psnake::VersionInfo.String4Version + ">";
	return ret.c_str();
}

r2cm::MenuUp DevelopmentMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle()
		, psnake::VersionInfo.String4Road2Version_0_0_0
	) );

	{
		ret->AddItem(
			'1'
			, r2cm::eColor::FG_White
			, []()->const char* { return "Test"; }
			, []()->r2cm::eItemLeaveAction
			{
				// 2022.04.11 by R2Road
				// 인자로 넘어온 director 를 사용해도 되지만 아래 코드와의 일관성을 위해 새 r2cm::Director를 만들어 돌린다.

				//
				// Setup
				//
				r2cm::Director director;
				director.Setup( TestMenu::Create( director ) );

				//
				// Process
				//
				director.Run();

				return r2cm::eItemLeaveAction::None;
			}
		);



		ret->AddLineFeed();



		ret->AddItem(
			32
			, r2cm::eColor::BG_Blue
			, []()->const char* { return "Snake"; }
			, []()->r2cm::eItemLeaveAction
			{
				r2cm::WindowUtility::Resize( 548, 548 );
				r2cm::WindowUtility::Move( 0, 0 );

				{
					//
					// Setup
					//
					r2base::Director director( psnake::DirectorConfig );
					director.Setup( psnake_scene::EntryScene::Create( director ) );

					//
					// Environment : ScrollBar | Maximize Button | Frame Lock
					//
					r2cm::WindowUtility::ScrollBarVisible( false );
					r2cm::WindowUtility::MaximizeButtonEnable( false );
					r2cm::WindowUtility::ResizingByDraggingEnable( false );

					//
					// Process
					//
					director.Run();
				}

				r2cm::WindowUtility::Resize( 960, 960 );
				r2cm::WindowUtility::Move( 0, 0 );
				r2cm::WindowUtility::ScrollBarVisible( true );
				r2cm::WindowUtility::MaximizeButtonEnable( true );
				r2cm::WindowUtility::ResizingByDraggingEnable( true );

				return r2cm::eItemLeaveAction::None;
			}
		);



		ret->AddSplit();



		ret->AddItem(
			27
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eItemLeaveAction
			{
				return r2cm::eItemLeaveAction::Exit;
			}
		);
	}

	return ret;
}