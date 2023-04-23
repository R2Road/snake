#include "test_psm_demo.h"

#include <conio.h>

#include "r2/r2_FPSTimer.h"
#include "r2/r2_Direction4.h"

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
			LS();

			PROCESS_MAIN( psm_table::TerrainDataTable::GetInstance().Load() );

			LS();

			DECLARATION_MAIN( auto game_core = psm::GameCore::Create() );
			PROCESS_MAIN( game_core->Reset( psm_table::TerrainDataTable::GetInstance().Get( 1 ) ) );

			LS();

			{
				std::cout << "[ W, A, S, D ] : Move" << r2cm::linefeed;
			}

			LS();

			{
				r2::FPSTimer fps_timer( 30 );
				const auto pivot_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				int input = 0;
				r2::Direction4 move_direction;

				r2::PointInt move_amount;

				do
				{
					if( fps_timer.Update() )
					{
						r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_cursor_point );

						psmhelper::Printer4Terrain_CharOX::Print( pivot_cursor_point.x, pivot_cursor_point.y, game_core->GetTerrain() );
						Utility4Snake::Draw( pivot_cursor_point.x, pivot_cursor_point.y, game_core->GetSnake() );

						LS();

						std::cout << "Input Direction" << "    " << "X : " << move_direction.GetX() << "   " << "Y : " << move_direction.GetY() << r2cm::linefeed;

						LS();


						if( _kbhit() )
						{
							input = _getch();

							switch( input )
							{
							case 'w':
								move_direction.SetState( r2::eDirection4State::DOWN );
								break;
							case 'a':
								move_direction.SetState( r2::eDirection4State::LEFT );
								break;
							case 's':
								move_direction.SetState( r2::eDirection4State::UP );
								break;
							case 'd':
								move_direction.SetState( r2::eDirection4State::RIGHT );
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

			LS();

			return r2cm::eDoLeaveAction::None;
		};
	}
}