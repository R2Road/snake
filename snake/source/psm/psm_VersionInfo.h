#pragma once

namespace psm
{

	//
	// 2022.05.06 by R
	//
	// �������� �ʰ� ��̰� �۾��� �̾�� �� �ֵ��� ��� ����� ������ ��.
	//

	static struct
	{

		const char VersionNumber_1 = '0';
		const char VersionNumber_2 = '0';
		const char VersionNumber_3 = '0';

		const char String4Version[20] = { 'S', 'n', 'a', 'k', 'e', ' ', 'M', 'i', 'n', 'i', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };


		const char* const String4SubjectAsAProgrammer = {
			"### �� ������Ʈ�� ���� ��ǥ | Subject As A Programmer ###"
			"\n"
			"\n"	"1. Core"
			"\n"	"[ ] "    "> ������ �����͸� �ٷ�� Core ��ü�� �д�"
			"\n"	"[ ] "    "> Core ��ü�� Singleton�� ������� �ʴ´�"
			"\n"	"[ ] "    "> Director�� �Բ� �� ����� ���� ������ �־��ش�"
			"\n"	"[ ] "    "> Scene �� �Բ� �̵��Ѵ�."
			"\n"
			"\n"	"2. ��ü"
			"\n"	"[ ] "    "> ���ӿ� ��ü�� �ʿ��ϴٸ� Core�� ������ ��û�ϰ�, �� ����� ������ ��ü�� �����Ѵ�."
			"\n"	"[ ] "    "> ���ӿ� �����ϴ� ����� Update �ڵ�� ������ Core�� �д�."
			"\n"	"[ ] "    "> Scene Graph �� �Ⱦ�� �ܼ� ȯ�濡�� ���� ���� ������ �������� �����Ѵ�."
		};


		const char* const String4Road2Version_0_0_1 = {
			"### Road 2 Version 0.0.1 ###"
			"\n"
			"\n"	"[o] " "Terrain : �̵� ���� ���� �� �Ұ��� ���� ����"
			"\n"	"[ ] " "Snake Container : ���� ���� ��Ҹ� �߰�, ����"
			"\n"	"[ ] " "Move Direction Indicator : WASD Key �� �̿��� ���� �̵� ������ ����"
		};

		const char* const String4Road2Version_0_0_0 = {
			"### Road 2 Version 0.0.0 ###"
			"\n"
			"\n"	"[o] " "Make Project"
			"\n"	"[o] " "Cleanup"
		};

	} VersionInfo;
}