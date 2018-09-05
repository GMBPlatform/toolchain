
#include <iostream>
#include "boost/thread.hpp"

void ThFunc(void *p, int a, int b, int c, int d)
{
	const char *pszMessage = (const char *)p;
	std::cout << pszMessage << ":" << (a + b + c + d) << std::endl;
	boost::this_thread::sleep(boost::posix_time::seconds(2));          // 2�� ���� ����
}

int main(int argc, char **argv)
{
	static const char *pszMessage = "boost thread";
	boost::thread t(ThFunc, (void *)pszMessage, 1, 1024, 2048, 4096);  // �������� ���ڸ� ������ �Լ��� ���� �� �� ����.

	t.timed_join(boost::posix_time::seconds(1));                       // 1�� ���� ������ ���� ���
	t.join();                                                          // ������ ���� ��� (����)

	return 0;
}