#pragma once

namespace r2
{

	//
	// 2022.05.06 by R
	//
	// 무리하지 않고 즐겁게 작업을 이어나갈 수 있도록 모든 방안을 강구할 것.
	//

	static struct
	{

		const char VersionNumber_1 = '0';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '2';

		const char String4Version[12] = { 'R', '2', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };

		const char* const String4Road2Version_0_0_3 =
			"### Road 2 Version 0.0.3 ###"
			"\n"
			"\n"	"[ ] " "Queue Based On Array"
		;

		const char* const String4Road2Version_0_0_2 =
			"### Road 2 Version 0.0.2 ###"
			"\n"
			"\n"	"[o] " "Value with Tracking"
			"\n"	"[o] " "Value with Dirty"
			"\n"	"[o] " "Value with Dirty and Tracking"
		;

		const char* const String4Road2Version_0_0_1 =
			"### Road 2 Version 0.0.1 ###"
			"\n"
			"\n"	"[o] " "Index Enumerator"
		;

		const char* const String4Road2Version_0_0_0 =
			"### Road 2 Version 0.0.0 ###"
			"\n"
			"\n"	"[o] " "Make Project"
			"\n"	"[o] " "Cleanup"
		;

	} VersionInfo;
}