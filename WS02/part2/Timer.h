// Lance Curi0
// 104319223
// lcurio@myseneca.ca
// September 24-2023
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <iostream>
#include <chrono>

namespace sdds {
	class Timer {	
		std::chrono::steady_clock::time_point time;
	public:
		void start();
		long long stop();
	};
}
#endif // !SDDS_TIMER_H
