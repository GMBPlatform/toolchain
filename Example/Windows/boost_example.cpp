
#include <iostream>
#include "boost/thread.hpp"

void ThFunc(void *p, int a, int b, int c, int d)
{
	const char *pszMessage = (const char *)p;
	std::cout << pszMessage << ":" << (a + b + c + d) << std::endl;
	boost::this_thread::sleep(boost::posix_time::seconds(2));          // 2초 동안 정지
}

int main(int argc, char **argv)
{
	static const char *pszMessage = "boost thread";
	boost::thread t(ThFunc, (void *)pszMessage, 1, 1024, 2048, 4096);  // 여러개의 인자를 쓰레드 함수에 전달 할 수 있음.

	t.timed_join(boost::posix_time::seconds(1));                       // 1초 동안 쓰레드 종료 대기
	t.join();                                                          // 쓰레드 종료 대기 (무한)

	return 0;
}