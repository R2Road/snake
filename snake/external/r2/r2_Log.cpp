#include "r2_Log.h"

#include <stdio.h>
#include <stdarg.h>

namespace r2
{
	Log Log::instance;

	Log::Log() : mActivate( true )
	{}

	void Log::Print( const char* format_string, ... )
	{
		if( !instance.mActivate )
		{
			return;
		}

		static char buf[256] = { 0 };
		va_list argList;

		va_start( argList, format_string );

		vsnprintf( buf, 256, format_string, argList );
		printf( "%s", buf );

		va_end( argList );
	}
}