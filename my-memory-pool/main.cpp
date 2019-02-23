#include "pool.h"
#include <chrono>
#include <iostream>

int main(int argc, char *argv[])
{
	using namespace std::chrono;

	auto t1 = high_resolution_clock::now();
	{
		Pool<8> test_pool;
		for (int ii = 0; ii < 10000000; ++ii)
		{
			auto p = test_pool.allocate(sizeof(int));
			test_pool.deallocate(p, sizeof(int));
		}
	}
	auto t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(t2 - t1).count();

	std::cout << "time with pool: " << duration << " micro seconds" << std::endl;

	auto t3 = high_resolution_clock::now();
	{
		for (int ii = 0; ii < 10000000; ++ii)
		{
			auto p = malloc(sizeof(int));
			free(p);
		}
	}
	auto t4 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(t4 - t3).count();

	std::cout << "time without pool: " << duration2 << " micro seconds" << std::endl;

	getchar();

	return 0;
}

