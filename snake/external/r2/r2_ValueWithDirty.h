#pragma once

namespace r2
{
	template<typename T, T default_value>
	class ValueWithDirty
	{
	public:
		using ValueT = T;
		using MyT = ValueWithDirty<T, default_value>;
		const ValueT ValueDefault = default_value;

		ValueWithDirty() : mValue( ValueDefault ), mbDirty( false )
		{}

		//
		// Operator
		//
		void operator=( const ValueT new_value ) override
		{
			if( new_value == mValue )
			{
				return;
			}

			mValue = new_value;
			mbDirty = true;
		}
		void operator=( const MyT new_value_with_dirty ) override
		{
			mValue = new_value_with_dirty.Get();
			mbDirty = new_value_with_dirty.IsDirty();
		}

		//
		//
		//
		ValueT Get() const
		{
			return mValue;
		}
		bool IsDirty() const
		{
			return mbDirty;
		}

		//
		//
		//
		void Cleanup()
		{
			mbDirty = false;
		}

	private:
		ValueT mValue;
		bool mbDirty;
	};
}
