#pragma once

namespace psnake
{
	class Snake;
}

class Utility4Snake
{
private:
	Utility4Snake() = delete;

public:
	static void Draw( const short x, const short y, const psnake::Snake& snake );
};