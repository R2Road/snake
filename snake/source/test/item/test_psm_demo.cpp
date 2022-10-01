#include "test_psm_demo.h"

#include <conio.h>

#include "r2/r2_FPSTimer.h"
#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "psm/psm_GameCore.h"
#include "psm/psm_table_TerrainDataTable.h"

#include "test/Utility4Terrain.h"
#include "test/Utility4Snake.h"

namespace test_psm_demo
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

			psm_table::TerrainDataTable::GetInstance().Load();

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto game_core = psm::GameCore::Create() );
			PROCESS_MAIN( game_core->Reset( psm_table::TerrainDataTable::GetInstance().Get( 1 ) ) );

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

							switch( input )
							{
							case 'w':
								break;
							case 'a':
								break;
							case 's':
								break;
							case 'd':
								break;
							}
						}
					}

				} while( 27 != input );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}