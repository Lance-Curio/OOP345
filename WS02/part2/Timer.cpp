// Lance Curi0
// 104319223
// lcurio@myseneca.ca
// September 24-2023
#include "Timer.h"

using namespace std;
using namespace chrono;

namespace sdds{
	void Timer::start() {
		time = steady_clock::now();
	}

	long long Timer::stop() {
		auto end = steady_clock::now();
		auto duration = duration_cast<nanoseconds>(end - time);

		return duration.count();
	}
}