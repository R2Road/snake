#include "TestMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/test_psnake_demo.h"
#include "item/test_psnake_terrain.h"

r2cm::MenuUp TestMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle()
	) );

	{
		ret->AddItem( '1', test_psnake_terrain::Declaration::GetInstance() );
		ret->AddItem( '2', test_psnake_terrain::Fill::GetInstance() );
		ret->AddItem( '3', test_psnake_terrain::Get_IsIn::GetInstance() );



		ret->AddSplit();



		ret->AddItem( 32, test_psnake_demo::Do::GetInstance() );



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