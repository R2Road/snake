namespace r2
{
	class Log
	{
	private:
		Log();

	public:
		static void Print( const char* format_string, ... );

	private:
		static Log instance;
		bool mActivate;
	};
}



#define R2LOG_ENABLE_LOG 1



#if defined( R2LOG_ENABLE_LOG ) && R2LOG_ENABLE_LOG == 1
	#define R2LOG( format, ... )      r2::Log::Print( format, ##__VA_ARGS__ )
#else
	#define R2Log( ... )       do {} while ( 0 )
#endif

#define R2LOG_FORCE( format, ... )      r2::Log::Print( format, ##__VA_ARGS__ )
