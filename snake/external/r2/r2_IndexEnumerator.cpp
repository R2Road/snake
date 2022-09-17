#include "r2_IndexEnumerator.h"

#include <algorithm>
#include <random>
#include <utility>

#include "r2_Random.h"

namespace r2
{
	//
	// # Summury
	// �Ʒ��� ���� �ڵ�� ���� ���� ���ӵǴ� ���� �����ϱ� ���� ���̴�.
	// �� ���� ������ ������ ����� �������� �� �� �̻� ���� �ʴٸ� �����Ѵ�.
	// > 5 : 5 OK
	// > 6 : 5 OK
	// > 7 : 5 Failed
	//
	bool AlignIndexes( r2::IndexEnumerator::ContainerT& out_indexes )
	{
		bool swap_result = false;

		auto before = out_indexes.begin();
		auto cur = ( before + 1 );
		for( auto end = out_indexes.end(); end != cur; ++before, ++cur )
		{
			if( *before != *cur )
			{
				continue;
			}

			swap_result = false;
			for( auto next = ( cur + 1 ); end != next; ++next )
			{
				if( *before != *next )
				{
					std::swap( *next, *cur );
					swap_result = true;
					break;
				}
			}

			if( !swap_result )
			{
				return false;
			}
		}

		return true;
	}

	IndexEnumerator::IndexEnumerator() :
		mIndexes( { 0 } )
		, mCurrentIndex( 0u )
	{}

	IndexEnumerator::IndexEnumerator( std::initializer_list<int> source_indexes ) :
		mIndexes( 0 == source_indexes.size() ? std::initializer_list<int>{ 0 } : source_indexes )
		, mCurrentIndex( 0u )
	{}

	IndexEnumerator::IndexEnumerator( ContainerT&& source_indexes ) :
		mIndexes( source_indexes.empty() ? ( ContainerT{ 0 } ) : std::move( source_indexes ) )
		, mCurrentIndex( 0u )
	{}

	IndexEnumerator::IndexEnumerator( const ContainerT& source_indexes ) :
		mIndexes( source_indexes.empty() ? ( ContainerT{ 0 } ) : source_indexes )
		, mCurrentIndex( 0u )
	{}

	IndexEnumerator::IndexEnumerator( const ContainerT& source_indexes, const int scale_amount ) :
		mIndexes()
		, mCurrentIndex( 0u )
	{
		ContainerT indexes( 0 );

		if( source_indexes.empty() )
		{
			indexes.reserve( 1 );
			indexes.push_back( 0 );
		}
		else if( 1 == source_indexes.size() )
		{
			indexes.reserve( 1 );
			indexes.push_back( *source_indexes.begin() );
		}
		else if( 2 == source_indexes.size() )
		{
			indexes.reserve( 2 );
			if( r2::Random::GetBool() )
			{
				indexes.push_back( source_indexes[0] );
				indexes.push_back( source_indexes[1] );
			}
			else
			{
				indexes.push_back( source_indexes[1] );
				indexes.push_back( source_indexes[0] );
			}
		}
		else
		{
			const int fixed_scale_amout = std::max( 1, scale_amount );
			const auto required_size = source_indexes.size() * fixed_scale_amout;

			//
			// Reserve
			//
			indexes.reserve( required_size );

			//
			// Build Indexes : Step 1 : �⺻ �� ä��� : �ּ� 1���� ���� ���Եǵ��� �����Ѵ�.
			//
			for( const auto i : source_indexes )
			{
				indexes.push_back( i );
			}

			//
			// Build Indexes : Step 2 : �ұ��� ä���
			//
			for( const auto i : source_indexes )
			{
				for( int cur = 0, end = r2::Random::GetInt( 0, ( scale_amount / 2 ) ); end > cur; ++cur )
				{
					indexes.push_back( i );
				}
			}

			//
			// Build Indexes : Step 3 : ���ڶ� �� ä���
			//
			if( required_size > indexes.size() )
			{
				auto cur = source_indexes.begin();
				const auto end = source_indexes.end();
				while( required_size > indexes.size() )
				{
					if( end == cur )
					{
						cur = source_indexes.begin();
					}

					indexes.push_back( *cur );
					++cur;
				}
			}

			//
			// Shuffle & Align
			//
			{
				static std::random_device random_device;
				static std::mt19937 random_engine( random_device() );

				do
				{

					std::shuffle( indexes.begin(), indexes.end(), random_engine );

				} while( !AlignIndexes( indexes ) );
			}
		}

		mIndexes = std::move( indexes );
	}

	int IndexEnumerator::Get()
	{
		if( mIndexes.size() <= mCurrentIndex )
		{
			mCurrentIndex = 0;
		}

		return mIndexes[mCurrentIndex++];
	}
}
