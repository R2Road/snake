#include "test_psnake_terrain.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

#include "psnake/psnake_Terrain.h"

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

				std::cout << r2cm::linefeed;

				std::cout << "# Iteration" << " > ";
				for( const auto c : terrain )
				{
					std::cout << c << ' ';
				}
				std::cout << r2cm::linefeed;
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

				std::cout << r2cm::linefeed;

				std::cout << "# Iteration" << " > ";
				for( const auto c : terrain )
				{
					std::cout << c << ' ';
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}