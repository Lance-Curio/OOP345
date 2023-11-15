// Lance Curi0
// 104319223
// lcurio@myseneca.ca
// September 24-2023
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include "AirportModels.h"

using namespace std;

namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Airport& airport){
		if (airport.a_code.empty()) {
			os << "Empty Airport";
		}
		else {
			os << std::right << std::setw(20) << std::setfill('.') << "Airport Code" << " : " << std::left << std::setw(30) << airport.a_code << std::endl;
			os << std::right << std::setw(20) << std::setfill('.') << "Airport Name" << " : " << std::left << std::setw(30) << airport.a_name << std::endl;
			os << std::right << std::setw(20) << std::setfill('.') << "City" << " : " << std::left << std::setw(30) << airport.a_city << std::endl;
			os << std::right << std::setw(20) << std::setfill('.') << "State" << " : " << std::left << std::setw(30) << airport.a_state << std::endl;
			os << std::right << std::setw(20) << std::setfill('.') << "Country" << " : " << std::left << std::setw(30) << airport.a_country << std::endl;
			os << std::right << std::setw(20) << std::setfill('.') << "Latitude" << " : " << std::left << std::setw(30) << airport.a_lat << std::endl;
			os << std::right << std::setw(20) << std::setfill('.') << "Longitude" << " : " << std::left << std::setw(30) << airport.a_log << std::endl;
		}
		return os;
	}

	AirportLog::AirportLog() : air(nullptr), count(0) {}

	AirportLog::AirportLog(const char* filename) : air(nullptr), count(0) {
		ifstream inFile(filename);

		if (inFile.is_open()) {
			string header;
			getline(inFile, header);

			string line;
			while (getline(inFile, line)) {
				count++;
			}

			air = new Airport[count];

			inFile.clear();
			inFile.seekg(0); 
			getline(inFile, header);

			for (size_t i = 0; i < count; i++) {
				getline(inFile >> ws, air[i].a_code, ',');
				getline(inFile >> ws, air[i].a_name, ',');
				getline(inFile >> ws, air[i].a_city, ',');
				getline(inFile >> ws, air[i].a_state, ',');
				getline(inFile >> ws, air[i].a_country, ',');
				inFile >> air[i].a_lat;
				inFile.ignore(9999, ',');
				inFile >> air[i].a_log;
				inFile.ignore(9999, '\n');
			}
		}
	}

	void AirportLog::addAirport(const Airport& airport) {
		Airport* newAirports = new Airport[count + 1];

		for (size_t i = 0; i < count; i++) {
			newAirports[i] = air[i];
		}

		newAirports[count] = airport;

		count++;

		delete[] air;

		air = newAirports;
	}

	AirportLog AirportLog::findAirport(const char* state, const char* country) const {
		AirportLog result;

		for (size_t i = 0; i < count; i++) {
			if(strcmp(air[i].getState().c_str(), state) == 0 && 
				strcmp(air[i].getCountry().c_str(), country) == 0) {
				result.addAirport(air[i]);
			}
		}

		return result;
	}

	Airport AirportLog::operator[](size_t index) const {
		if (index < count) {
			return air[index];
		}
		else {
			Airport emptyAirport;
			return emptyAirport;
		}
	}

	AirportLog::AirportLog(AirportLog&& other) {
		air = nullptr;
		*this = std::move(other);
	}

	AirportLog& AirportLog::operator=(AirportLog&& other) {
		if (this != &other) {
			delete[] air;

			count = other.count;
			other.count = 0;

			air = other.air;
			other.air = nullptr;
		}

		return *this;
	}

	AirportLog& AirportLog::operator=(const AirportLog& other) {
		if (this != &other) {
			delete[] air;

			count = other.count;

			if (other.air != nullptr) {
				air = new Airport[count];

				for (size_t i = 0; i < count; i++) {
					air[i].a_code = other.air[i].a_code;
					air[i].a_name = other.air[i].a_name;
					air[i].a_city = other.air[i].a_city;
					air[i].a_state = other.air[i].a_state;
					air[i].a_country = other.air[i].a_country;
					air[i].a_lat = other.air[i].a_lat;
					air[i].a_log = other.air[i].a_log;
				}
			}
		}
		return *this;
	}

	AirportLog::AirportLog(const AirportLog& other) {	
		air = nullptr;
		*this = other;
	}


	AirportLog::operator size_t() const {
		return count;
	}

	AirportLog::~AirportLog(){
		delete[] air;
		air = nullptr;
	}
		
}