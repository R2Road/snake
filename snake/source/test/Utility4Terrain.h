#pragma once

namespace psnake
{
	class Terrain;
}

class Utility4Terrain
{
private:
	Utility4Terrain() = delete;

public:
	static void Draw( const short x, const short y, const psnake::Terrain& terrain );
};