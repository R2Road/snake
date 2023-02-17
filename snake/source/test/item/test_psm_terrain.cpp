#include "test_psm_terrain.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "psm/psm_Terrain.h"

#include "test/Utility4Terrain.h"

namespace test_psm_terrain
{
	std::ostream& operator<<( std::ostream& o, psm::eCellType value )
	{
		return o << static_cast<int>( value ) << r2cm::linefeed;
	}

	r2cm::TitleFunctionT Declaration_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Terrain : Declaration 1";
		};
	}
	r2cm::DoFunctionT Declaration_1::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( psm::Terrain terrain );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, terrain.GetWidth() );
				EXPECT_EQ( 1, terrain.GetHeight() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 0, terrain.GetMaxX() );
				EXPECT_EQ( 0, terrain.GetMaxY() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );
				OUTPUT_VALUE( terrain.Size() );

				std::cout << r2cm::linefeed;

				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( psm::Terrain terrain( 3, 7 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 3, terrain.GetWidth() );
				EXPECT_EQ( 7, terrain.GetHeight() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, terrain.GetMaxX() );
				EXPECT_EQ( 6, terrain.GetMaxY() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );
				OUTPUT_VALUE( terrain.Size() );

				std::cout << r2cm::linefeed;

				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Declaration_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Terrain : Declaration 2";
		};
	}
	r2cm::DoFunctionT Declaration_2::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( psm::Terrain terrain( psm_table::TerrainData{ 2, 2, std::initializer_list<psm_table::TerrainData::CellT>{} } ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, terrain.GetWidth() );
				EXPECT_EQ( 2, terrain.GetHeight() );
				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, terrain.GetMaxX() );
				EXPECT_EQ( 1, terrain.GetMaxY() );

				std::cout << r2cm::linefeed;

				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( psm::Terrain terrain( psm_table::TerrainData{ 2, 2, { psm::eCellType::Close, psm::eCellType::Close } } ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, terrain.GetWidth() );
				EXPECT_EQ( 2, terrain.GetHeight() );
				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, terrain.GetMaxX() );
				EXPECT_EQ( 1, terrain.GetMaxY() );

				std::cout << r2cm::linefeed;

				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( psm::Terrain terrain( psm_table::TerrainData{ 2, 2, { psm::eCellType::Close, psm::eCellType::Open, psm::eCellType::Open, psm::eCellType::Close, psm::eCellType::Close, psm::eCellType::Close } } ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, terrain.GetWidth() );
				EXPECT_EQ( 2, terrain.GetHeight() );
				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, terrain.GetMaxX() );
				EXPECT_EQ( 1, terrain.GetMaxY() );

				std::cout << r2cm::linefeed;

				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Declaration_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Terrain : Declaration 3";
		};
	}
	r2cm::DoFunctionT Declaration_3::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( psm::Terrain terrain( psm_table::TerrainData{ 2, 2, std::initializer_list<int>{} } ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, terrain.GetWidth() );
				EXPECT_EQ( 2, terrain.GetHeight() );
				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, terrain.GetMaxX() );
				EXPECT_EQ( 1, terrain.GetMaxY() );

				std::cout << r2cm::linefeed;

				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( psm::Terrain terrain( psm_table::TerrainData{ 2, 2, { 1, 1 } } ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, terrain.GetWidth() );
				EXPECT_EQ( 2, terrain.GetHeight() );
				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, terrain.GetMaxX() );
				EXPECT_EQ( 1, terrain.GetMaxY() );

				std::cout << r2cm::linefeed;

				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( psm::Terrain terrain( psm_table::TerrainData{ 2, 2, { 1, 0, 0, 1, 1, 1 } } ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, terrain.GetWidth() );
				EXPECT_EQ( 2, terrain.GetHeight() );
				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, terrain.GetMaxX() );
				EXPECT_EQ( 1, terrain.GetMaxY() );

				std::cout << r2cm::linefeed;

				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT IsIn::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Terrain : IsIn";
		};
	}
	r2cm::DoFunctionT IsIn::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( psm::Terrain terrain );
			PROCESS_MAIN( terrain.Reset( { 2, 2, {
						psm::eCellType::Open		, psm::eCellType::Close
					,	psm::eCellType::Close		, psm::eCellType::Open
			} } ) );

			std::cout << r2cm::split;

			{
				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
			}

			std::cout << r2cm::split;

			{
				EXPECT_TRUE( terrain.IsIn( 0, 0 ) );
				EXPECT_TRUE( terrain.IsIn( 1, 0 ) );
				EXPECT_TRUE( terrain.IsIn( 0, 1 ) );
				EXPECT_TRUE( terrain.IsIn( 1, 1 ) );
			}

			std::cout << r2cm::split;

			{
				EXPECT_FALSE( terrain.IsIn( -1, -1 ) );
				EXPECT_FALSE( terrain.IsIn( 0, -1 ) );
				EXPECT_FALSE( terrain.IsIn( 1, -1 ) );
				EXPECT_FALSE( terrain.IsIn( 2, -1 ) );

				std::cout << r2cm::linefeed;

				EXPECT_FALSE( terrain.IsIn( -1, 0 ) );
				EXPECT_FALSE( terrain.IsIn( 2, 0 ) );

				std::cout << r2cm::linefeed;

				EXPECT_FALSE( terrain.IsIn( -1, 1 ) );
				EXPECT_FALSE( terrain.IsIn( 2, 1 ) );

				std::cout << r2cm::linefeed;

				EXPECT_FALSE( terrain.IsIn( -1, 2 ) );
				EXPECT_FALSE( terrain.IsIn( 0, 2 ) );
				EXPECT_FALSE( terrain.IsIn( 1, 2 ) );
				EXPECT_FALSE( terrain.IsIn( 2, 2 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Get_IsIn::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Terrain : Get and IsIn";
		};
	}
	r2cm::DoFunctionT Get_IsIn::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( psm::Terrain terrain );
			PROCESS_MAIN( terrain.Reset( { 2, 2, {
						psm::eCellType::Open		, psm::eCellType::Close
					,	psm::eCellType::Close		, psm::eCellType::Open
			} } ) );

			std::cout << r2cm::split;

			{
				std::cout << "# View" << r2cm::linefeed2;
				const auto current_cursor_point = r2cm::WindowUtility::GetCursorPoint();
				Utility4Terrain::Draw( 4, current_cursor_point.y, terrain );
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( psm::eCellType::Open, terrain.Get( 0, 0 ) );
				EXPECT_EQ( psm::eCellType::Close, terrain.Get( 1, 0 ) );
				EXPECT_EQ( psm::eCellType::Close, terrain.Get( 0, 1 ) );
				EXPECT_EQ( psm::eCellType::Open, terrain.Get( 1, 1 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( psm::eCellType::Open, terrain.Get( 2, 1 ) );
				EXPECT_EQ( psm::eCellType::Open, terrain.Get( 1, 2 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Reset::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Terrain : Reset";
		};
	}
	r2cm::DoFunctionT Reset::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( psm::Terrain terrain );

			std::cout << r2cm::linefeed;

			EXPECT_EQ( 1, terrain.GetWidth() );
			EXPECT_EQ( 1, terrain.GetHeight() );

			std::cout << r2cm::linefeed;

			EXPECT_EQ( 0, terrain.GetMaxX() );
			EXPECT_EQ( 0, terrain.GetMaxY() );

			std::cout << r2cm::linefeed;

			EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );
			OUTPUT_VALUE( terrain.Size() );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( terrain.Reset( { 4, 4, {
						psm::eCellType::Close		, psm::eCellType::Close		, psm::eCellType::Close		,psm::eCellType::Close
					,	psm::eCellType::Close		, psm::eCellType::Open		, psm::eCellType::Open		,psm::eCellType::Close
					,	psm::eCellType::Close		, psm::eCellType::Open		, psm::eCellType::Open		,psm::eCellType::Close
					,	psm::eCellType::Close		, psm::eCellType::Close		, psm::eCellType::Close		,psm::eCellType::Close
				} } ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 4, terrain.GetWidth() );
				EXPECT_EQ( 4, terrain.GetHeight() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 3, terrain.GetMaxX() );
				EXPECT_EQ( 3, terrain.GetMaxY() );

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

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}