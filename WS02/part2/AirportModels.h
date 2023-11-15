// Lance Curi0
// 104319223
// lcurio@myseneca.ca
// September 24-2023
#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H

#include <iostream>


namespace sdds {
	struct Airport {
		std::string a_code{};
		std::string a_name{};
		std::string a_city{};
		std::string a_state{};
		std::string a_country{};
		double a_lat{};
		double a_log{};
		const std::string& getState() const { return a_state; }
		const std::string& getCountry() const { return a_country; }
		friend std::ostream& operator<<(std::ostream& os, const Airport& air);
	};

	class AirportLog {
		Airport* air;
		size_t count;
	public:
		AirportLog();
		AirportLog(const char* filename);
		AirportLog(const AirportLog& other);
		AirportLog& operator=(const AirportLog& other);
		AirportLog(AirportLog&& other);
		AirportLog& operator=(AirportLog&& other);
		~AirportLog();


		void addAirport(const Airport& airport);
		AirportLog findAirport(const char* state, const char* country) const;
		Airport operator[](size_t index) const;
		explicit operator size_t() const;
	};
}

#endif