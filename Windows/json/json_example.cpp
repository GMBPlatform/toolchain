#include "json/json.h"

#ifdef _DEBUG
#pragma comment(lib, "json_vc141_libmtd.lib") // json debug lib
#else
#pragma comment(lib, "json_vc141_libmt.lib") // json release lib
#endif

int main()
{
	Json::Value root;        // json의 메인 객체이다.
	root["level"] = 123;    // level을 키값으로 가지는 123이라는 값을 생성
	root["id"] = "qwerty";
	root["password"] = "qwerty";
	root["isBeta"] = false;

	Json::Value item;
	item.append("stone");    // item에 stone이라는 값을 넣는다.
	item.append("Dirt");
	root["item"] = item;    // item이라는 배열을 추가한다.

	Json::Value friendList;
	Json::Value billy;
	billy["level"] = 1;
	Json::Value sam;
	sam["level"] = 10;
	friendList.append(billy);    // 배열에 객체를 추가한다.
	friendList.append(sam);
	root["friendList"] = friendList;    // friendList라는 객체를 root객체에 추가

	Json::StyledWriter writer;
	std::string str = writer.write(root);    // str에 만들어진 json을 넘긴다.


	std::cout << str.c_str() << std::endl;    // json을 콘솔에 출력한다.
	getchar();
	return 0;
}
