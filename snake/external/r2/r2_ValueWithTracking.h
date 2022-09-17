#pragma once

namespace r2
{
	template<typename T, T DEFAULT_T>
	class ValueWithTracking
	{
	public:
		using ValueT = T;
		using MyT = ValueWithTracking<T, DEFAULT_T>;
		const ValueT ValueDefault = DEFAULT_T;

		ValueWithTracking() : mCurrent( ValueDefault ), mLast( ValueDefault )
		{}

		//
		// Operator
		//
		void operator=( const ValueT new_value ) override
		{
			mLast = mCurrent;
			mCurrent = new_value;
		}
		void operator=( const MyT new_value_with_tracking ) override
		{
			mLast = new_value_with_tracking.GetLast();
			mCurrent = new_value_with_tracking.GetCurrent();
		}

		//
		//
		//
		ValueT GetCurrent() const
		{
			return mCurrent;
		}
		ValueT GetLast() const
		{
			return mLast;
		}

	private:
		ValueT mCurrent;
		ValueT mLast;
	};
}
