#pragma once

#include <vector>

namespace r2
{
	class IndexEnumerator
	{
	public:
		using ContainerT = std::vector<int>;

		IndexEnumerator();
		IndexEnumerator( std::initializer_list<int> source_indexes );
		IndexEnumerator( ContainerT&& source_indexes );
		IndexEnumerator( const ContainerT& source_indexes );
		IndexEnumerator( const ContainerT& source_indexes, const int scale_amount );

		const ContainerT& GetContainer() const { return mIndexes; }
		std::size_t Size() const { return mIndexes.size(); }
		int Get();

	private:
		ContainerT mIndexes;
		std::size_t mCurrentIndex;
	};
}