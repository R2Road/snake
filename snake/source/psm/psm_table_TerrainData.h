#pragma once

#include <initializer_list>

#include "psm_constant.h"

namespace psm_table
{
	struct TerrainData
	{
		int width;
		int height;
		std::initializer_list<psm::eCellType> data;
	};
}