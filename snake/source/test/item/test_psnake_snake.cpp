#include "test_psnake_snake.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "psnake/psnake_Snake.h"
#include "psnake/psnake_Terrain.h"

#include "test/Utility4Snake.h"
#include "test/Utility4Terrain.h"

namespace test_psnake_snake
{
	r2cm::iItem::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Snake : Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Declaration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( psnake::Terrain terrain( 3, 7 ) );
			DECLARATION_MAIN( psnake::Snake snake( 3, 7 ) );

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 3, snake.GetWidth() );
				EXPECT_EQ( 7, snake.GetHeight() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, snake.GetMaxX() );
				EXPECT_EQ( 6, snake.GetMaxY() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( snake.GetWidth() * snake.GetHeight(), snake.Size() );
				OUTPUT_VALUE( snake.Size() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( snake.begin(), snake.end() );
				EXPECT_EQ( snake.begin()->prev, snake.begin() );
				EXPECT_EQ( snake.begin()->next, snake.begin() );
				EXPECT_FALSE( snake.begin()->value );
			}

			std::cout << r2cm::split;

			{
				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
				Utility4Snake::Draw( 4, current_cursor_point.y, snake );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Add_Remove::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Snake : Add, Remove";
		};
	}
	r2cm::iItem::DoFunctionT Add_Remove::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( psnake::Terrain terrain( 4, 4 ) );
			DECLARATION_MAIN( psnake::Snake snake( 4, 4 ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Add" << r2cm::linefeed2;

				EXPECT_FALSE( snake.Get( 1, 1 ) );
				PROCESS_MAIN( snake.PushFront( 1, 1 ) );
				EXPECT_TRUE( snake.Get( 1, 1 ) );

				std::cout << r2cm::linefeed;

				EXPECT_FALSE( snake.Get( 2, 2 ) );
				PROCESS_MAIN( snake.PushFront( 2, 2 ) );
				EXPECT_TRUE( snake.Get( 2, 2 ) );

				std::cout << r2cm::linefeed;

				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
				Utility4Snake::Draw( 4, current_cursor_point.y, snake );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Remove" << r2cm::linefeed2;

				EXPECT_TRUE( snake.Get( 1, 1 ) );
				PROCESS_MAIN( snake.Remove( 1, 1 ) );
				EXPECT_FALSE( snake.Get( 1, 1 ) );

				std::cout << r2cm::linefeed;

				{
					const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
					Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
					Utility4Snake::Draw( 4, current_cursor_point.y, snake );
				}

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( snake.Get( 2, 2 ) );
				PROCESS_MAIN( snake.Remove( 2, 2 ) );
				EXPECT_FALSE( snake.Get( 2, 2 ) );

				std::cout << r2cm::linefeed;

				{
					const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
					Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
					Utility4Snake::Draw( 4, current_cursor_point.y, snake );
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}