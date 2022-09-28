#include "psm_table_TextureTable.h"

#include "r2bix/r2render_Texture.h"
#include "r2bix/r2render_TextureFrame.h"

namespace psnake_table
{
	void TextureTable::Load()
	{
		if( !mTextureContainer.empty() )
		{
			return;
		}

		{
			auto result = mTextureContainer.emplace( "project_mini_rogue_image", TextureValueT( new ( std::nothrow ) r2render::Texture(
				60,
				//		"          1         2         3         4         5         6         7"
				//		"01234567890123456789012345678901234567890123456789012345678901234567890"
				/* 0 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx               "
				/* 1 */ "x 00000 xx  11   xx 22222 xx 33333 xx 4  4  x               "
				/* 2 */ "x0     0xx 111   xx2     2xx3     3xx4   4  x               "
				/* 3 */ "x0     0xx   1   xx  2222 xx   333 xx4   4  x               "
				/* 4 */ "x0     0xx   1   xx22     xx3     3xx4444444x               "
				/* 5 */ "x 00000 xx1111111xx2222222xx 33333 xx    4  x               "
				/* 6 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx               "
				/* 7 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx               "
				/* 8 */ "x555555 xx 666   xx7777777xx 88888 xx 99999 x               "
				/* 9 */ "x5      xx6      xx      7xx8     8xx9     9x               "
				/* 0 */ "x555555 xx666666 xx      7xx 88888 xx 999999x               "
				/* 1 */ "x      5xx6     6xx      7xx8     8xx      9x               "
				/* 2 */ "x555555 xx 66666 xx      7xx 88888 xx 99999 x               "
				/* 3 */ "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx               "
			) ) );

			{
				auto frame_result = mTextureFrameContainer.emplace(
					"number_0"
					, TextureFrameValueT( new ( std::nothrow ) r2render::TextureFrame( result.first->second.get() ) )
				);
				frame_result.first->second->SetVisibleRect( r2::RectInt( 1, 1, 6, 4 ) );
			}
		}
	}
}