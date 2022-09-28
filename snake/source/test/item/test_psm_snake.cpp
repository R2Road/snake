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

			DECLARATION_SUB( psm::Terrain terrain( 3, 7 ) );
			DECLARATION_MAIN( psm::Snake snake( 3, 7 ) );

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

				EXPECT_EQ( snake.GetHeadNode(), snake.GetEndNode() );
				EXPECT_EQ( *snake.GetHeadNode().prev, snake.GetHeadNode() );
				EXPECT_EQ( *snake.GetHeadNode().next, snake.GetHeadNode() );
				EXPECT_FALSE( snake.GetHeadNode().value );
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



	r2cm::iItem::TitleFunctionT PushFront::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Snake : PushFront";
		};
	}
	r2cm::iItem::DoFunctionT PushFront::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( psm::Terrain terrain( 4, 4 ) );
			DECLARATION_MAIN( psm::Snake snake( 4, 4 ) );

			std::cout << r2cm::split;

			{
				EXPECT_FALSE( snake.Get( 1, 1 ) );
				PROCESS_MAIN( snake.PushFront( 1, 1 ) );
				EXPECT_TRUE( snake.Get( 1, 1 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( snake.GetHeadNode(), snake.GetNode( 1, 1 ) );
				EXPECT_EQ( *snake.GetHeadNode().prev, snake.GetEndNode() );
				EXPECT_EQ( *snake.GetHeadNode().next, snake.GetEndNode() );
				EXPECT_EQ( *snake.GetEndNode().prev, snake.GetHeadNode() );
				EXPECT_EQ( *snake.GetEndNode().next, snake.GetHeadNode() );

				std::cout << r2cm::linefeed;

				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
				Utility4Snake::Draw( 4, current_cursor_point.y, snake );
			}

			std::cout << r2cm::split;

			{
				EXPECT_FALSE( snake.Get( 2, 2 ) );
				PROCESS_MAIN( snake.PushFront( 2, 2 ) );
				EXPECT_TRUE( snake.Get( 2, 2 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( snake.GetHeadNode(), snake.GetNode( 2, 2 ) );
				EXPECT_EQ( *snake.GetHeadNode().prev, snake.GetEndNode() );
				EXPECT_EQ( *snake.GetHeadNode().next, snake.GetNode( 1, 1 ) );
				EXPECT_EQ( *snake.GetHeadNode().next->next, snake.GetEndNode() );
				EXPECT_EQ( *snake.GetEndNode().prev, snake.GetNode( 1, 1 ) );
				EXPECT_EQ( *snake.GetEndNode().next, snake.GetHeadNode() );

				std::cout << r2cm::linefeed;

				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
				Utility4Snake::Draw( 4, current_cursor_point.y, snake );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT PopTail::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Snake : PopTail";
		};
	}
	r2cm::iItem::DoFunctionT PopTail::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( psm::Terrain terrain( 4, 4 ) );
			DECLARATION_MAIN( psm::Snake snake( 4, 4 ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( snake.PushFront( 1, 1 ) );
				PROCESS_MAIN( snake.PushFront( 2, 2 ) );
				EXPECT_EQ( snake.GetHeadNode(), snake.GetNode( 2, 2 ) );
			}

			std::cout << r2cm::split;

			{
				EXPECT_TRUE( snake.Get( 1, 1 ) );
				PROCESS_MAIN( snake.PopTail() );
				EXPECT_FALSE( snake.Get( 1, 1 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( snake.GetHeadNode(), snake.GetNode( 2, 2 ) );
				EXPECT_EQ( *snake.GetHeadNode().prev, snake.GetEndNode() );
				EXPECT_EQ( *snake.GetHeadNode().next, snake.GetEndNode() );
				EXPECT_EQ( *snake.GetEndNode().prev, snake.GetHeadNode() );
				EXPECT_EQ( *snake.GetEndNode().next, snake.GetHeadNode() );

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
				PROCESS_MAIN( snake.PopTail() );
				EXPECT_FALSE( snake.Get( 2, 2 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( snake.GetHeadNode(), snake.GetEndNode() );
				EXPECT_EQ( *snake.GetHeadNode().prev, snake.GetEndNode() );
				EXPECT_EQ( *snake.GetHeadNode().next, snake.GetEndNode() );
				EXPECT_EQ( *snake.GetEndNode().prev, snake.GetHeadNode() );
				EXPECT_EQ( *snake.GetEndNode().next, snake.GetHeadNode() );

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