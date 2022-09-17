#pragma once

namespace r2
{
	template<typename T, T default_value>
	class ValueWithDirtyAndTracking
	{
	public:
		using ValueT = T;
		using MyT = ValueWithDirtyAndTracking<T, default_value>;
		const ValueT ValueDefault = default_value;

		ValueWithDirtyAndTracking() : mCurrent( ValueDefault ), mLast( ValueDefault ), mbDirty( false )
		{}

		//
		// Operator
		//
		void operator=( const ValueT new_value ) override
		{
			if( new_value == mCurrent )
			{
				return;
			}

			mLast = mCurrent;
			mCurrent = new_value;
			mbDirty = true;
		}
		void operator=( const MyT new_value_with_dirty ) override
		{
			mLast = new_value_with_dirty.GetLast();
			mCurrent = new_value_with_dirty.GetCurrent();
			mbDirty = new_value_with_dirty.IsDirty();
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
		ValueT mCurrent;
		ValueT mLast;
		bool mbDirty;
	};
}
