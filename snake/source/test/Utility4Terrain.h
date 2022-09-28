#pragma once

namespace psm
{
	class Terrain;
}

class Utility4Terrain
{
private:
	Utility4Terrain() = delete;

public:
	static void Draw( const short x, const short y, const psm::Terrain& terrain );
};