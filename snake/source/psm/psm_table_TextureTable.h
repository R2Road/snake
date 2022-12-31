#pragma once

#include "r2/r2_SingletonWithStaticFunction.h"
#include "r2bix/r2base_TextureTableBase.h"

namespace psm_table
{
	class TextureTable : public r2base::TextureTableBase, public r2::SingletonWithStaticFunction<TextureTable>
	{
	public:
		void Load() override;
	};
}