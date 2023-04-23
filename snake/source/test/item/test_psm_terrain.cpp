#include "test_psm_terrain.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "psm/psm_Terrain.h"

#include "test/psmhelper_Printer4Terrain_CharOX.h"

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
			LS();

			{
				OUTPUT_SUBJECT( "기본 생성자" );

				LF();

				DECLARATION_MAIN( psm::Terrain terrain );

				LF();

				EXPECT_EQ( 1, terrain.GetWidth() );
				EXPECT_EQ( 1, terrain.GetHeight() );

				LF();

				EXPECT_EQ( 0, terrain.GetMaxX() );
				EXPECT_EQ( 0, terrain.GetMaxY() );

				LF();

				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );
				OUTPUT_VALUE( terrain.Size() );

				LF();

				psmhelper::Printer4Terrain_CharOX::Print( 4, 0, terrain );
			}

			LS();

			{
				OUTPUT_SUBJECT( "가로, 세로를 인자로 받는 생성자" );

				LF();

				DECLARATION_MAIN( psm::Terrain terrain( 3, 5 ) );

				LF();

				EXPECT_EQ( 3, terrain.GetWidth() );
				EXPECT_EQ( 5, terrain.GetHeight() );

				LF();

				EXPECT_EQ( 2, terrain.GetMaxX() );
				EXPECT_EQ( 4, terrain.GetMaxY() );

				LF();

				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );
				OUTPUT_VALUE( terrain.Size() );

				LF();

				psmhelper::Printer4Terrain_CharOX::Print( 4, 0, terrain );
			}

			LS();

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
			LS();

			OUTPUT_SUBJECT( "TerrainData 를 인자로 받는 생성자" );

			LS();

			{
				DECLARATION_MAIN( psm::Terrain terrain( psm_table::TerrainData{ 2, 2, std::initializer_list<psm_table::TerrainData::CellT>{} } ) );

				LF();

				EXPECT_EQ( 2, terrain.GetWidth() );
				EXPECT_EQ( 2, terrain.GetHeight() );
				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );

				LF();

				EXPECT_EQ( 1, terrain.GetMaxX() );
				EXPECT_EQ( 1, terrain.GetMaxY() );

				LF();

				psmhelper::Printer4Terrain_CharOX::Print( 4, 0, terrain );
			}

			LS();

			{
				DECLARATION_MAIN( psm::Terrain terrain( psm_table::TerrainData{ 2, 2, { psm::eCellType::Open, psm::eCellType::Open } } ) );

				LF();

				EXPECT_EQ( 2, terrain.GetWidth() );
				EXPECT_EQ( 2, terrain.GetHeight() );
				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );

				LF();

				EXPECT_EQ( 1, terrain.GetMaxX() );
				EXPECT_EQ( 1, terrain.GetMaxY() );

				LF();

				psmhelper::Printer4Terrain_CharOX::Print( 4, 0, terrain );
			}

			LS();

			{
				DECLARATION_MAIN( psm::Terrain terrain( psm_table::TerrainData{ 2, 2, { psm::eCellType::Open, psm::eCellType::Close, psm::eCellType::Close, psm::eCellType::Open, psm::eCellType::Open, psm::eCellType::Open } } ) );

				LF();

				EXPECT_EQ( 2, terrain.GetWidth() );
				EXPECT_EQ( 2, terrain.GetHeight() );
				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );

				LF();

				EXPECT_EQ( 1, terrain.GetMaxX() );
				EXPECT_EQ( 1, terrain.GetMaxY() );

				LF();

				psmhelper::Printer4Terrain_CharOX::Print( 4, 0, terrain );
			}

			LS();

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
			LS();

			{
				DECLARATION_MAIN( psm::Terrain terrain( psm_table::TerrainData{ 2, 2, std::initializer_list<int>{} } ) );

				LF();

				EXPECT_EQ( 2, terrain.GetWidth() );
				EXPECT_EQ( 2, terrain.GetHeight() );
				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );

				LF();

				EXPECT_EQ( 1, terrain.GetMaxX() );
				EXPECT_EQ( 1, terrain.GetMaxY() );

				LF();

				psmhelper::Printer4Terrain_CharOX::Print( 4, 0, terrain );
			}

			LS();

			{
				DECLARATION_MAIN( psm::Terrain terrain( psm_table::TerrainData{ 2, 2, { 1, 1 } } ) );

				LF();

				EXPECT_EQ( 2, terrain.GetWidth() );
				EXPECT_EQ( 2, terrain.GetHeight() );
				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );

				LF();

				EXPECT_EQ( 1, terrain.GetMaxX() );
				EXPECT_EQ( 1, terrain.GetMaxY() );

				LF();

				psmhelper::Printer4Terrain_CharOX::Print( 4, 0, terrain );
			}

			LS();

			{
				DECLARATION_MAIN( psm::Terrain terrain( psm_table::TerrainData{ 2, 2, { 1, 0, 0, 1, 1, 1 } } ) );

				LF();

				EXPECT_EQ( 2, terrain.GetWidth() );
				EXPECT_EQ( 2, terrain.GetHeight() );
				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );

				LF();

				EXPECT_EQ( 1, terrain.GetMaxX() );
				EXPECT_EQ( 1, terrain.GetMaxY() );

				LF();

				psmhelper::Printer4Terrain_CharOX::Print( 4, 0, terrain );
			}

			LS();

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
			LS();

			DECLARATION_MAIN( psm::Terrain terrain );
			PROCESS_MAIN( terrain.Reset( psm_table::TerrainData{ 2, 2, std::initializer_list<int>{} } ) );

			LS();

			{
				psmhelper::Printer4Terrain_CharOX::Print( 4, 0, terrain );
			}

			LS();

			{
				EXPECT_TRUE( terrain.IsIn( 0, 0 ) );
				EXPECT_TRUE( terrain.IsIn( 1, 0 ) );
				EXPECT_TRUE( terrain.IsIn( 0, 1 ) );
				EXPECT_TRUE( terrain.IsIn( 1, 1 ) );
			}

			LS();

			{
				EXPECT_FALSE( terrain.IsIn( 2, 0 ) );

				LF();

				EXPECT_FALSE( terrain.IsIn( 2, 1 ) );

				LF();

				EXPECT_FALSE( terrain.IsIn( 0, 2 ) );
				EXPECT_FALSE( terrain.IsIn( 1, 2 ) );
				EXPECT_FALSE( terrain.IsIn( 2, 2 ) );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Get::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Terrain : Get";
		};
	}
	r2cm::DoFunctionT Get::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( psm::Terrain terrain );
			PROCESS_MAIN( terrain.Reset( psm_table::TerrainData{ 2, 2, {
						psm::eCellType::Open		, psm::eCellType::Close
					,	psm::eCellType::Close		, psm::eCellType::Open
			} } ) );

			LS();

			{
				psmhelper::Printer4Terrain_CharOX::Print( 4, 0, terrain );
			}

			LS();

			{
				EXPECT_EQ( psm::eCellType::Open, terrain.Get( 0, 0 ) );
				EXPECT_EQ( psm::eCellType::Close, terrain.Get( 1, 0 ) );
				EXPECT_EQ( psm::eCellType::Close, terrain.Get( 0, 1 ) );
				EXPECT_EQ( psm::eCellType::Open, terrain.Get( 1, 1 ) );
			}
			
			LS();

			{
				EXPECT_EQ( terrain.Get( 1, 0 ), terrain.Get( 2, 0 ) );

				LF();

				EXPECT_EQ( terrain.Get( 1, 1 ), terrain.Get( 2, 1 ) );

				LF();

				EXPECT_EQ( terrain.Get( 0, 1 ), terrain.Get( 0, 2 ) );
				EXPECT_EQ( terrain.Get( 1, 1 ), terrain.Get( 1, 2 ) );
				EXPECT_EQ( terrain.Get( 1, 1 ), terrain.Get( 2, 2 ) );
			}

			LS();

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
			LS();

			DECLARATION_MAIN( psm::Terrain terrain );

			LS();

			{
				EXPECT_EQ( 1, terrain.GetWidth() );
				EXPECT_EQ( 1, terrain.GetHeight() );
				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );

				LF();

				EXPECT_EQ( 0, terrain.GetMaxX() );
				EXPECT_EQ( 0, terrain.GetMaxY() );

				LF();

				psmhelper::Printer4Terrain_CharOX::Print( 4, 0, terrain );
			}

			LS();

			{
				PROCESS_MAIN( terrain.Reset( psm_table::TerrainData{ 4, 4, {
						psm::eCellType::Close		, psm::eCellType::Close		, psm::eCellType::Close		,psm::eCellType::Close
					,	psm::eCellType::Close		, psm::eCellType::Open		, psm::eCellType::Open		,psm::eCellType::Close
					,	psm::eCellType::Close		, psm::eCellType::Open		, psm::eCellType::Open		,psm::eCellType::Close
					,	psm::eCellType::Close		, psm::eCellType::Close		, psm::eCellType::Close		,psm::eCellType::Close
				} } ) );

				LF();

				EXPECT_EQ( 4, terrain.GetWidth() );
				EXPECT_EQ( 4, terrain.GetHeight() );
				EXPECT_EQ( terrain.GetWidth() * terrain.GetHeight(), terrain.Size() );

				LF();

				EXPECT_EQ( 3, terrain.GetMaxX() );
				EXPECT_EQ( 3, terrain.GetMaxY() );

				LF();

				psmhelper::Printer4Terrain_CharOX::Print( 4, 0, terrain );
			}
			
			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}