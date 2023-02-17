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
				DECLARATION_SUB( psm::Terrain t );
				DECLARATION_MAIN( psm::Snake s );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, s.GetWidth() );
				EXPECT_EQ( 1, s.GetHeight() );
				EXPECT_EQ( s.GetWidth() * s.GetHeight(), s.Size() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 0, s.GetMaxX() );
				EXPECT_EQ( 0, s.GetMaxY() );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( s.GetHeadNode() == s.GetEndNode() );
				EXPECT_TRUE( *s.GetHeadNode().prev == s.GetHeadNode() );
				EXPECT_TRUE( *s.GetHeadNode().next == s.GetHeadNode() );
				EXPECT_FALSE( s.GetHeadNode().value );

				std::cout << r2cm::linefeed;

				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, t );
				Utility4Snake::Draw( 4, current_cursor_point.y, s );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_SUB( psm::Terrain t( 3, 4 ) );
				DECLARATION_MAIN( psm::Snake s( 3, 4 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 3, s.GetWidth() );
				EXPECT_EQ( 4, s.GetHeight() );
				EXPECT_EQ( s.GetWidth() * s.GetHeight(), s.Size() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, s.GetMaxX() );
				EXPECT_EQ( 3, s.GetMaxY() );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( s.GetHeadNode() == s.GetEndNode() );
				EXPECT_TRUE( *s.GetHeadNode().prev == s.GetHeadNode() );
				EXPECT_TRUE( *s.GetHeadNode().next == s.GetHeadNode() );
				EXPECT_FALSE( s.GetHeadNode().value );

				std::cout << r2cm::linefeed;

				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, t );
				Utility4Snake::Draw( 4, current_cursor_point.y, s );
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

			DECLARATION_SUB( psm::Terrain t( 4, 4 ) );
			DECLARATION_MAIN( psm::Snake s( 4, 4 ) );

			std::cout << r2cm::split;

			{
				EXPECT_FALSE( s.Get( 1, 1 ) );
				PROCESS_MAIN( s.Push( 1, 1 ) );
				EXPECT_TRUE( s.Get( 1, 1 ) );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( s.GetHeadNode() == s.GetNode( 1, 1 ) );
				EXPECT_TRUE( *s.GetHeadNode().prev == s.GetEndNode() );
				EXPECT_TRUE( *s.GetHeadNode().next == s.GetEndNode() );
				EXPECT_TRUE( *s.GetEndNode().prev == s.GetHeadNode() );
				EXPECT_TRUE( *s.GetEndNode().next == s.GetHeadNode() );

				std::cout << r2cm::linefeed;

				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, t );
				Utility4Snake::Draw( 4, current_cursor_point.y, s );
			}

			std::cout << r2cm::split;

			{
				EXPECT_FALSE( s.Get( 2, 2 ) );
				PROCESS_MAIN( s.Push( 2, 2 ) );
				EXPECT_TRUE( s.Get( 2, 2 ) );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( s.GetHeadNode() == s.GetNode( 2, 2 ) );
				EXPECT_TRUE( *s.GetHeadNode().prev == s.GetEndNode() );
				EXPECT_TRUE( *s.GetHeadNode().next == s.GetNode( 1, 1 ) );
				EXPECT_TRUE( *s.GetHeadNode().next->next == s.GetEndNode() );
				EXPECT_TRUE( *s.GetEndNode().prev == s.GetNode( 1, 1 ) );
				EXPECT_TRUE( *s.GetEndNode().next == s.GetHeadNode() );

				std::cout << r2cm::linefeed;

				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, t );
				Utility4Snake::Draw( 4, current_cursor_point.y, s );
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

			DECLARATION_SUB( psm::Terrain t( 4, 4 ) );
			DECLARATION_MAIN( psm::Snake s( 4, 4 ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( s.Push( 1, 1 ) );
				PROCESS_MAIN( s.Push( 2, 2 ) );
				EXPECT_TRUE( s.GetHeadNode() == s.GetNode( 2, 2 ) );
			}

			std::cout << r2cm::split;

			{
				EXPECT_TRUE( s.Get( 1, 1 ) );
				PROCESS_MAIN( s.Pop() );
				EXPECT_FALSE( s.Get( 1, 1 ) );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( s.GetHeadNode() == s.GetNode( 2, 2 ) );
				EXPECT_TRUE( *s.GetHeadNode().prev == s.GetEndNode() );
				EXPECT_TRUE( *s.GetHeadNode().next == s.GetEndNode() );
				EXPECT_TRUE( *s.GetEndNode().prev == s.GetHeadNode() );
				EXPECT_TRUE( *s.GetEndNode().next == s.GetHeadNode() );

				std::cout << r2cm::linefeed;

				{
					const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
					Utility4Terrain::Draw( 4, current_cursor_point.y, t );
					Utility4Snake::Draw( 4, current_cursor_point.y, s );
				}
			}

			std::cout << r2cm::split;

			{
				EXPECT_TRUE( s.Get( 2, 2 ) );
				PROCESS_MAIN( s.Pop() );
				EXPECT_FALSE( s.Get( 2, 2 ) );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( s.GetHeadNode() == s.GetEndNode() );
				EXPECT_TRUE( *s.GetHeadNode().prev == s.GetEndNode() );
				EXPECT_TRUE( *s.GetHeadNode().next == s.GetEndNode() );
				EXPECT_TRUE( *s.GetEndNode().prev == s.GetHeadNode() );
				EXPECT_TRUE( *s.GetEndNode().next == s.GetHeadNode() );

				std::cout << r2cm::linefeed;

				{
					const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
					Utility4Terrain::Draw( 4, current_cursor_point.y, t );
					Utility4Snake::Draw( 4, current_cursor_point.y, s );
				}
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}