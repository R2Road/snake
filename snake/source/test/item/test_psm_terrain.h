#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace test_psm_terrain
{
	class Declaration_1 : public r2cm::iItem, public r2cm::SingleTon<Declaration_1>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Declaration_2 : public r2cm::iItem, public r2cm::SingleTon<Declaration_2>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Reset : public r2cm::iItem, public r2cm::SingleTon<Reset>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Get_IsIn : public r2cm::iItem, public r2cm::SingleTon<Get_IsIn>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}