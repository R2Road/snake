#include "test_psnake_demo.h"

#include "r2cm/r2cm_ostream.h"

namespace test_psnake_demo
{
	r2cm::iItem::TitleFunctionT Do::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Demo";
		};
	}
	r2cm::iItem::DoFunctionT Do::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}