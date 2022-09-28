#include "test_psnake_demo.h"

#include <conio.h>

#include "r2/r2_FPSTimer.h"
#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "psnake/psnake_GameCore.h"

#include "test/Utility4Terrain.h"
#include "test/Utility4Snake.h"

namespace test_psnake_demo
{
	r2cm::iItem::TitleFunctionT Do::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Demo";
		};
	}
	r2cm::iItem::DoFunctionT Do::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( auto game_core = psnake::GameCore::Create() );
			PROCESS_MAIN( game_core->Reset() );

			std::cout << r2cm::split;

			{
				r2::FPSTimer fps_timer( 30 );
				const auto pivot_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				int input = 0;
				do
				{
					if( fps_timer.Update() )
					{
						r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_cursor_point );
						Utility4Terrain::Draw( pivot_cursor_point.x, pivot_cursor_point.y, game_core->GetTerrain() );
						Utility4Snake::Draw( pivot_cursor_point.x, pivot_cursor_point.y, game_core->GetSnake() );

						if( _kbhit() )
						{
							input = _getch();
						}
					}

				} while( 27 != input );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}