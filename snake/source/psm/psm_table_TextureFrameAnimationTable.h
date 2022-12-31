#pragma once

#include "r2/r2_SingletonWithStaticFunction.h"
#include "r2bix/r2base_TextureFrameAnimationTableBase.h"

namespace psm_table
{
	class TextureFrameAnimationTable : public r2base::TextureFrameAnimationTableBase, public r2::SingletonWithStaticFunction<TextureFrameAnimationTable>
	{
	public:
		void Load() override;
	};
}