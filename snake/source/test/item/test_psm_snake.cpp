#include "test_psm_snake.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "psm/psm_helper_Printer4Terrain_CharOX.h"
#include "psm/psm_Snake.h"

#include "test/Utility4Snake.h"

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
			LS();

			{
				DECLARATION_SUB( psm::Terrain t );
				DECLARATION_MAIN( psm::Snake s );

				LF();

				EXPECT_EQ( 1, s.GetWidth() );
				EXPECT_EQ( 1, s.GetHeight() );
				EXPECT_EQ( s.GetWidth() * s.GetHeight(), s.Size() );

				LF();

				EXPECT_EQ( 0, s.GetMaxX() );
				EXPECT_EQ( 0, s.GetMaxY() );

				LF();

				EXPECT_TRUE( s.GetHeadNode() == s.GetEndNode() );
				EXPECT_TRUE( *s.GetHeadNode().prev == s.GetHeadNode() );
				EXPECT_TRUE( *s.GetHeadNode().next == s.GetHeadNode() );
				EXPECT_FALSE( s.GetHeadNode().value );

				LF();

				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				psm_helper::Printer4Terrain_CharOX::Print( current_cursor_point, 4, 0, t );
				psm_helper::Utility4Snake::Draw( 4, current_cursor_point.y, s );
			}

			LS();

			{
				DECLARATION_SUB( psm::Terrain t( 3, 4 ) );
				DECLARATION_MAIN( psm::Snake s( 3, 4 ) );

				LF();

				EXPECT_EQ( 3, s.GetWidth() );
				EXPECT_EQ( 4, s.GetHeight() );
				EXPECT_EQ( s.GetWidth() * s.GetHeight(), s.Size() );

				LF();

				EXPECT_EQ( 2, s.GetMaxX() );
				EXPECT_EQ( 3, s.GetMaxY() );

				LF();

				EXPECT_TRUE( s.GetHeadNode() == s.GetEndNode() );
				EXPECT_TRUE( *s.GetHeadNode().prev == s.GetHeadNode() );
				EXPECT_TRUE( *s.GetHeadNode().next == s.GetHeadNode() );
				EXPECT_FALSE( s.GetHeadNode().value );

				LF();

				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				psm_helper::Printer4Terrain_CharOX::Print( current_cursor_point, 4, 0, t );
				psm_helper::Utility4Snake::Draw( 4, current_cursor_point.y, s );
			}

			LS();

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
			LS();

			DECLARATION_SUB( psm::Terrain t( 4, 4 ) );
			DECLARATION_MAIN( psm::Snake s( 4, 4 ) );

			LS();

			{
				EXPECT_FALSE( s.Get( 1, 1 ) );
				PROCESS_MAIN( s.Push( 1, 1 ) );
				EXPECT_TRUE( s.Get( 1, 1 ) );

				LF();

				EXPECT_TRUE( s.GetHeadNode() == s.GetNode( 1, 1 ) );
				EXPECT_TRUE( *s.GetHeadNode().prev == s.GetEndNode() );
				EXPECT_TRUE( *s.GetHeadNode().next == s.GetEndNode() );
				EXPECT_TRUE( *s.GetEndNode().prev == s.GetHeadNode() );
				EXPECT_TRUE( *s.GetEndNode().next == s.GetHeadNode() );

				LF();

				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				psm_helper::Printer4Terrain_CharOX::Print( current_cursor_point, 4, 0, t );
				psm_helper::Utility4Snake::Draw( 4, current_cursor_point.y, s );
			}

			LS();

			{
				EXPECT_FALSE( s.Get( 2, 2 ) );
				PROCESS_MAIN( s.Push( 2, 2 ) );
				EXPECT_TRUE( s.Get( 2, 2 ) );

				LF();

				EXPECT_TRUE( s.GetHeadNode() == s.GetNode( 2, 2 ) );
				EXPECT_TRUE( *s.GetHeadNode().prev == s.GetEndNode() );
				EXPECT_TRUE( *s.GetHeadNode().next == s.GetNode( 1, 1 ) );
				EXPECT_TRUE( *s.GetHeadNode().next->next == s.GetEndNode() );
				EXPECT_TRUE( *s.GetEndNode().prev == s.GetNode( 1, 1 ) );
				EXPECT_TRUE( *s.GetEndNode().next == s.GetHeadNode() );

				LF();

				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				psm_helper::Printer4Terrain_CharOX::Print( current_cursor_point, 4, 0, t );
				psm_helper::Utility4Snake::Draw( 4, current_cursor_point.y, s );
			}

			LS();

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
			LS();

			DECLARATION_SUB( psm::Terrain t( 4, 4 ) );
			DECLARATION_MAIN( psm::Snake s( 4, 4 ) );

			LS();

			{
				PROCESS_MAIN( s.Push( 1, 1 ) );
				PROCESS_MAIN( s.Push( 2, 2 ) );
				EXPECT_TRUE( s.GetHeadNode() == s.GetNode( 2, 2 ) );
			}

			LS();

			{
				EXPECT_TRUE( s.Get( 1, 1 ) );
				PROCESS_MAIN( s.Pop() );
				EXPECT_FALSE( s.Get( 1, 1 ) );

				LF();

				EXPECT_TRUE( s.GetHeadNode() == s.GetNode( 2, 2 ) );
				EXPECT_TRUE( *s.GetHeadNode().prev == s.GetEndNode() );
				EXPECT_TRUE( *s.GetHeadNode().next == s.GetEndNode() );
				EXPECT_TRUE( *s.GetEndNode().prev == s.GetHeadNode() );
				EXPECT_TRUE( *s.GetEndNode().next == s.GetHeadNode() );

				LF();

				{
					const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
					psm_helper::Printer4Terrain_CharOX::Print( current_cursor_point, 4, 0, t );
					psm_helper::Utility4Snake::Draw( 4, current_cursor_point.y, s );
				}
			}

			LS();

			{
				EXPECT_TRUE( s.Get( 2, 2 ) );
				PROCESS_MAIN( s.Pop() );
				EXPECT_FALSE( s.Get( 2, 2 ) );

				LF();

				EXPECT_TRUE( s.GetHeadNode() == s.GetEndNode() );
				EXPECT_TRUE( *s.GetHeadNode().prev == s.GetEndNode() );
				EXPECT_TRUE( *s.GetHeadNode().next == s.GetEndNode() );
				EXPECT_TRUE( *s.GetEndNode().prev == s.GetHeadNode() );
				EXPECT_TRUE( *s.GetEndNode().next == s.GetHeadNode() );

				LF();

				{
					const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
					psm_helper::Printer4Terrain_CharOX::Print( current_cursor_point, 4, 0, t );
					psm_helper::Utility4Snake::Draw( 4, current_cursor_point.y, s );
				}
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}