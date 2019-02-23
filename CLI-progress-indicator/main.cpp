#include "progress_indicator.hpp"

#include <chrono>
#include <thread>

int main(int argc, char *argv[])
{
	using namespace std::this_thread;
	using namespace std::chrono;

	ProgressIndicator indicator;

	for (int i = 0; i < 100; ++i) {
		indicator.ProgressTo(i);
		sleep_for(milliseconds(50));
	}

	return 0;
}
