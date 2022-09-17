#pragma once

namespace r2
{
	template<typename T, typename Index_T = unsigned long long, Index_T Start_Value = 1, Index_T Invalid_Value = 0>
	class UniqueIndexGenerator
	{
	public:
		using OwnerT = T;
		using IndexT = Index_T;

		UniqueIndexGenerator() = delete;
		
		//
		//
		//
		static const IndexT GetNewIndex()
		{
			static IndexT start_index = Start_Value;
			return start_index++;
		}
		static const IndexT GetInvalidIndex()
		{
			static const IndexT invalid_index = Invalid_Value; // 0 is invalid
			return invalid_index;
		}
	};
}
