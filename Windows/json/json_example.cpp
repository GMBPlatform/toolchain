#include "json/json.h"

#ifdef _DEBUG
#pragma comment(lib, "json_vc141_libmtd.lib") // json debug lib
#else
#pragma comment(lib, "json_vc141_libmt.lib") // json release lib
#endif

int main()
{
	Json::Value root;        // json�� ���� ��ü�̴�.
	root["level"] = 123;    // level�� Ű������ ������ 123�̶�� ���� ����
	root["id"] = "qwerty";
	root["password"] = "qwerty";
	root["isBeta"] = false;

	Json::Value item;
	item.append("stone");    // item�� stone�̶�� ���� �ִ´�.
	item.append("Dirt");
	root["item"] = item;    // item�̶�� �迭�� �߰��Ѵ�.

	Json::Value friendList;
	Json::Value billy;
	billy["level"] = 1;
	Json::Value sam;
	sam["level"] = 10;
	friendList.append(billy);    // �迭�� ��ü�� �߰��Ѵ�.
	friendList.append(sam);
	root["friendList"] = friendList;    // friendList��� ��ü�� root��ü�� �߰�

	Json::StyledWriter writer;
	std::string str = writer.write(root);    // str�� ������� json�� �ѱ��.


	std::cout << str.c_str() << std::endl;    // json�� �ֿܼ� ����Ѵ�.
	getchar();
	return 0;
}
