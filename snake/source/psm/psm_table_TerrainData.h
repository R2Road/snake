#pragma once

#include <vector>

#include "psm_constant.h"

namespace psm_table
{
	struct TerrainData
	{
		int width;
		int height;
		std::vector<psm::eCellType> data;
	};
}