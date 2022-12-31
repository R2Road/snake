#include "test_psm_demo.h"

#include <conio.h>

#include "r2/r2_FPSTimer.h"
#include "r2/r2_PointInt.h"
#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "psm/psm_GameCore.h"
#include "psm/psm_table_TerrainDataTable.h"

#include "test/Utility4Terrain.h"
#include "test/Utility4Snake.h"

namespace test_psm_demo
{
	r2cm::TitleFunctionT Do::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Demo";
		};
	}
	r2cm::DoFunctionT Do::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			PROCESS_MAIN( psm_table::TerrainDataTable().Load() );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto game_core = psm::GameCore::Create() );
			PROCESS_MAIN( game_core->Reset( psm_table::TerrainDataTable().Get( 1 ) ) );

			std::cout << r2cm::split;

			{
				r2::FPSTimer fps_timer( 30 );
				const auto pivot_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				int input = 0;

				r2::PointInt move_amount;

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
								move_amount.Set( 0, -1 );
								break;
							case 'a':
								move_amount.Set( -1, 0 );
								break;
							case 's':
								move_amount.Set( 0, 1 );
								break;
							case 'd':
								move_amount.Set( 1, 0 );
								break;
							default:
								move_amount.SetZero();
								break;
							}

							if( 0 != move_amount.GetX() && 0 != move_amount.GetY() )
							{
								// Do Something
							}
						}
					}

				} while( 27 != input );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}