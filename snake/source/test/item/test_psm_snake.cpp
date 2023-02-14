#include "test_psm_snake.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "psm/psm_Snake.h"
#include "psm/psm_Terrain.h"

#include "test/Utility4Snake.h"
#include "test/Utility4Terrain.h"

bool operator==( const psm::Snake::Node& node_1, const psm::Snake::Node& node_2 )
{
	return ( &node_1 == &node_2 );
}

namespace test_psm_snake
{
	r2cm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Snake : Declaration";
		};
	}
	r2cm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( psm::Snake snake );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, snake.GetWidth() );
				EXPECT_EQ( 1, snake.GetHeight() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 0, snake.GetMaxX() );
				EXPECT_EQ( 0, snake.GetMaxY() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( snake.GetWidth() * snake.GetHeight(), snake.Size() );
				OUTPUT_VALUE( snake.Size() );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( snake.GetHeadNode() == snake.GetEndNode() );
				EXPECT_TRUE( *snake.GetHeadNode().prev == snake.GetHeadNode() );
				EXPECT_TRUE( *snake.GetHeadNode().next == snake.GetHeadNode() );
				EXPECT_FALSE( snake.GetHeadNode().value );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_SUB( psm::Terrain terrain( 3, 7 ) );
				DECLARATION_MAIN( psm::Snake snake( 3, 7 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 3, snake.GetWidth() );
				EXPECT_EQ( 7, snake.GetHeight() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, snake.GetMaxX() );
				EXPECT_EQ( 6, snake.GetMaxY() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( snake.GetWidth() * snake.GetHeight(), snake.Size() );
				OUTPUT_VALUE( snake.Size() );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( snake.GetHeadNode() == snake.GetEndNode() );
				EXPECT_TRUE( *snake.GetHeadNode().prev == snake.GetHeadNode() );
				EXPECT_TRUE( *snake.GetHeadNode().next == snake.GetHeadNode() );
				EXPECT_FALSE( snake.GetHeadNode().value );

				std::cout << r2cm::linefeed;

				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
				Utility4Snake::Draw( 4, current_cursor_point.y, snake );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Push::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Snake : Push";
		};
	}
	r2cm::DoFunctionT Push::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( psm::Terrain terrain( 4, 4 ) );
			DECLARATION_MAIN( psm::Snake snake( 4, 4 ) );

			std::cout << r2cm::split;

			{
				EXPECT_FALSE( snake.Get( 1, 1 ) );
				PROCESS_MAIN( snake.Push( 1, 1 ) );
				EXPECT_TRUE( snake.Get( 1, 1 ) );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( snake.GetHeadNode() == snake.GetNode( 1, 1 ) );
				EXPECT_TRUE( *snake.GetHeadNode().prev == snake.GetEndNode() );
				EXPECT_TRUE( *snake.GetHeadNode().next == snake.GetEndNode() );
				EXPECT_TRUE( *snake.GetEndNode().prev == snake.GetHeadNode() );
				EXPECT_TRUE( *snake.GetEndNode().next == snake.GetHeadNode() );

				std::cout << r2cm::linefeed;

				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
				Utility4Snake::Draw( 4, current_cursor_point.y, snake );
			}

			std::cout << r2cm::split;

			{
				EXPECT_FALSE( snake.Get( 2, 2 ) );
				PROCESS_MAIN( snake.Push( 2, 2 ) );
				EXPECT_TRUE( snake.Get( 2, 2 ) );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( snake.GetHeadNode() == snake.GetNode( 2, 2 ) );
				EXPECT_TRUE( *snake.GetHeadNode().prev == snake.GetEndNode() );
				EXPECT_TRUE( *snake.GetHeadNode().next == snake.GetNode( 1, 1 ) );
				EXPECT_TRUE( *snake.GetHeadNode().next->next == snake.GetEndNode() );
				EXPECT_TRUE( *snake.GetEndNode().prev == snake.GetNode( 1, 1 ) );
				EXPECT_TRUE( *snake.GetEndNode().next == snake.GetHeadNode() );

				std::cout << r2cm::linefeed;

				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
				Utility4Snake::Draw( 4, current_cursor_point.y, snake );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Pop::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Snake : Pop";
		};
	}
	r2cm::DoFunctionT Pop::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( psm::Terrain terrain( 4, 4 ) );
			DECLARATION_MAIN( psm::Snake snake( 4, 4 ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( snake.Push( 1, 1 ) );
				PROCESS_MAIN( snake.Push( 2, 2 ) );
				EXPECT_TRUE( snake.GetHeadNode() == snake.GetNode( 2, 2 ) );
			}

			std::cout << r2cm::split;

			{
				EXPECT_TRUE( snake.Get( 1, 1 ) );
				PROCESS_MAIN( snake.Pop() );
				EXPECT_FALSE( snake.Get( 1, 1 ) );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( snake.GetHeadNode() == snake.GetNode( 2, 2 ) );
				EXPECT_TRUE( *snake.GetHeadNode().prev == snake.GetEndNode() );
				EXPECT_TRUE( *snake.GetHeadNode().next == snake.GetEndNode() );
				EXPECT_TRUE( *snake.GetEndNode().prev == snake.GetHeadNode() );
				EXPECT_TRUE( *snake.GetEndNode().next == snake.GetHeadNode() );

				std::cout << r2cm::linefeed;

				{
					const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
					Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
					Utility4Snake::Draw( 4, current_cursor_point.y, snake );
				}
			}

			std::cout << r2cm::split;

			{
				EXPECT_TRUE( snake.Get( 2, 2 ) );
				PROCESS_MAIN( snake.Pop() );
				EXPECT_FALSE( snake.Get( 2, 2 ) );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( snake.GetHeadNode() == snake.GetEndNode() );
				EXPECT_TRUE( *snake.GetHeadNode().prev == snake.GetEndNode() );
				EXPECT_TRUE( *snake.GetHeadNode().next == snake.GetEndNode() );
				EXPECT_TRUE( *snake.GetEndNode().prev == snake.GetHeadNode() );
				EXPECT_TRUE( *snake.GetEndNode().next == snake.GetHeadNode() );

				std::cout << r2cm::linefeed;

				{
					const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
					Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
					Utility4Snake::Draw( 4, current_cursor_point.y, snake );
				}
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}