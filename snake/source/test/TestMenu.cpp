#include "TestMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/test_psm_demo.h"
#include "item/test_psm_snake.h"
#include "item/test_psm_terrain.h"

r2cm::MenuUp TestMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle()
	) );

	{
		ret->AddItem( '1', test_psm_terrain::Declaration::GetInstance() );
		ret->AddItem( '2', test_psm_terrain::Reset::GetInstance() );
		ret->AddItem( '3', test_psm_terrain::Get_IsIn::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'q', test_psm_snake::Declaration::GetInstance() );
		ret->AddItem( 'w', test_psm_snake::PushFront::GetInstance() );
		ret->AddItem( 'e', test_psm_snake::PopTail::GetInstance() );



		ret->AddSplit();



		ret->AddItem( 32, test_psm_demo::Do::GetInstance() );



		ret->AddSplit();



		ret->AddItem(
			27
			, r2cm::eColor::FG_White
			, []()->const char* { return "Exit"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				return r2cm::eItemLeaveAction::Exit;
			}
		);
	}

	return ret;
}