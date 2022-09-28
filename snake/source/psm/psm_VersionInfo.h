#pragma once

namespace psm
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
		const char VersionNumber_3 = '0';

		const char String4Version[20] = { 'S', 'n', 'a', 'k', 'e', ' ', 'M', 'i', 'n', 'i', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };


		const char* const String4SubjectAsAProgrammer = {
			"### 이 프로젝트의 실험 목표 | Subject As A Programmer ###"
			"\n"
			"\n"	"1. Core"
			"\n"	"[ ] "    "> 전반의 데이터를 다루는 Core 객체를 둔다"
			"\n"	"[ ] "    "> Core 객체에 Singleton은 사용하지 않는다"
			"\n"	"[ ] "    "> Director와 함께 각 노드의 생성 과정에 넣어준다"
			"\n"	"[ ] "    "> Scene 과 함께 이동한다."
			"\n"
			"\n"	"2. 객체"
			"\n"	"[ ] "    "> 게임에 객체가 필요하다면 Core에 생성을 요청하고, 그 결과를 가지고 객체를 생성한다."
			"\n"	"[ ] "    "> 게임에 관여하는 기능의 Update 코드는 가급적 Core에 둔다."
			"\n"	"[ ] "    "> Scene Graph 를 걷어내도 콘솔 환경에서 데모를 만들 정도의 독립성을 유지한다."
		};


		const char* const String4Road2Version_0_0_1 = {
			"### Road 2 Version 0.0.1 ###"
			"\n"
			"\n"	"[o] " "Terrain : 이동 가능 지역 과 불가능 지역 설정"
			"\n"	"[ ] " "Snake Container : 뱀의 구성 요소를 추가, 삭제"
			"\n"	"[ ] " "Move Direction Indicator : WASD Key 를 이용해 다음 이동 방향을 지정"
		};

		const char* const String4Road2Version_0_0_0 = {
			"### Road 2 Version 0.0.0 ###"
			"\n"
			"\n"	"[o] " "Make Project"
			"\n"	"[o] " "Cleanup"
		};

	} VersionInfo;
}