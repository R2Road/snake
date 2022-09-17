#pragma once

namespace r2
{
	template<typename T>
	struct ListNode
	{
		using ValueT = T;
		using MyT = ListNode<ValueT>;

		ValueT MyValue;
		MyT* pPrev = nullptr;
		MyT* pNext = nullptr;
	};
}