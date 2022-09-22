#include "test_psnake_terrain.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "psnake/psnake_Terrain.h"

#include "test/Utility4Terrain.h"

namespace test_psnake_terrain
{
	r2cm::iItem::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Terrain : Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Declaration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( psnake::Terrain terrain( 3, 7 ) );

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 3, terrain.GetWidth() );
				EXPECT_EQ( 7, terrain.GetHeight() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, terrain.GetMaxX() );
				EXPECT_EQ( 6, terrain.GetMaxY() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );
				OUTPUT_VALUE( terrain.Size() );
			}

			std::cout << r2cm::split;

			{
				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Fill::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Terrain : Fill";
		};
	}
	r2cm::iItem::DoFunctionT Fill::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( psnake::Terrain terrain( 4, 4 ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( terrain.Fill( {
						psnake::eCellType::Obstacle		, psnake::eCellType::Obstacle	, psnake::eCellType::Obstacle		,psnake::eCellType::Obstacle
					,	psnake::eCellType::Obstacle		, psnake::eCellType::Road		, psnake::eCellType::Road			,psnake::eCellType::Obstacle
					,	psnake::eCellType::Obstacle		, psnake::eCellType::Road		, psnake::eCellType::Road			,psnake::eCellType::Obstacle
					,	psnake::eCellType::Obstacle		, psnake::eCellType::Obstacle	, psnake::eCellType::Obstacle		,psnake::eCellType::Obstacle
					} ) );
			}
			
			std::cout << r2cm::split;

			{
				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Get_IsIn::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Terrain : Get and IsIn";
		};
	}
	r2cm::iItem::DoFunctionT Get_IsIn::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( psnake::Terrain terrain( 2, 2 ) );
			PROCESS_MAIN( terrain.Fill( {
						psnake::eCellType::Road		, psnake::eCellType::Obstacle
					,	psnake::eCellType::Obstacle		, psnake::eCellType::Road
			} ) );

			std::cout << r2cm::split;

			{
				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( psnake::eCellType::Road, terrain.Get( 0, 0 ) );
				EXPECT_EQ( psnake::eCellType::Obstacle, terrain.Get( 1, 0 ) );
				EXPECT_EQ( psnake::eCellType::Obstacle, terrain.Get( 0, 1 ) );
				EXPECT_EQ( psnake::eCellType::Road, terrain.Get( 1, 1 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( psnake::eCellType::Road, terrain.Get( 2, 1 ) );
				EXPECT_EQ( psnake::eCellType::Road, terrain.Get( 1, 2 ) );
			}

			std::cout << r2cm::split;

			{
				EXPECT_TRUE( terrain.IsIn( 0, 0 ) );
				EXPECT_TRUE( terrain.IsIn( 1, 0 ) );
				EXPECT_TRUE( terrain.IsIn( 0, 1 ) );
				EXPECT_TRUE( terrain.IsIn( 1, 1 ) );

				std::cout << r2cm::linefeed;

				EXPECT_FALSE( terrain.IsIn( -1, 0 ) );
				EXPECT_FALSE( terrain.IsIn( 0, -1 ) );
				EXPECT_FALSE( terrain.IsIn( 2, 1 ) );
				EXPECT_FALSE( terrain.IsIn( 1, 2 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}