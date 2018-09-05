#include <iostream>
#include <boost/flyweight.hpp>
#include <boost/flyweight/key_value.hpp>
#include <boost/flyweight/no_tracking.hpp>
#include <boost/noncopyable.hpp>

//피보나치 수는 0과 1로 시작하며, 다음 피보나치 수는 바로 앞의 두 피보나치 수의 합이 된다.0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946...


struct compute_fibonacci;
typedef boost::flyweights::flyweight<boost::flyweights::key_value<int, compute_fibonacci>, boost::flyweights::no_tracking> fibonacci;

struct compute_fibonacci :private boost::noncopyable
{
	compute_fibonacci(int n) : result(n == 0 ? 0 : n == 1 ? 1 : fibonacci(n - 2).get() + fibonacci(n - 1).get()) {}
	operator int()const { return result; }
	int result;
};

int main()
{
	for (int n = 0; n<40; ++n) 
	{
		std::cout << "F(" << n << ")=" << fibonacci(n) << std::endl;
	}
	getchar();
	return 0;
}