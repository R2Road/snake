#pragma once

namespace psm
{
	class Snake;
}

namespace psm_helper
{
	class Utility4Snake
	{
	private:
		Utility4Snake() = delete;

	public:
		static void Draw( const short x, const short y, const psm::Snake& snake );
	};
}