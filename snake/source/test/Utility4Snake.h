#pragma once

namespace psm
{
	class Snake;
}

namespace psm_helper
{
	class Printer4Snake_CharS
	{
	private:
		Printer4Snake_CharS() = delete;

	public:
		static void Draw( const short x, const short y, const psm::Snake& snake );
	};
}