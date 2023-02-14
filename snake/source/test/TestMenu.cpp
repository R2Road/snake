#include "TestMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/test_psm_demo.h"
#include "item/test_psm_snake.h"
#include "item/test_psm_terrain.h"

r2cm::TitleFunctionT TestMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Test Menu";
	};
}
r2cm::DescriptionFunctionT TestMenu::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2cm::WriteFunctionT TestMenu::GetWriteFunction() const
{
	return []( r2cm::MenuProcessor* ret )
	{
		ret->AddItem( '1', test_psm_terrain::Declaration_1() );
		ret->AddItem( '2', test_psm_terrain::Declaration_2() );
		ret->AddItem( '3', test_psm_terrain::Reset() );
		ret->AddItem( '4', test_psm_terrain::Get_IsIn() );



		ret->AddLineFeed();



		ret->AddItem( 'q', test_psm_snake::Declaration() );
		ret->AddItem( 'w', test_psm_snake::Push() );
		ret->AddItem( 'e', test_psm_snake::PopTail() );



		ret->AddSplit();



		ret->AddItem( 32, test_psm_demo::Do() );



		ret->AddSplit();



		ret->AddItem(
			27
			, r2cm::eColor::BG_Purple
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eDoLeaveAction
			{
				return r2cm::eDoLeaveAction::Exit;
			}
		);
	};
}