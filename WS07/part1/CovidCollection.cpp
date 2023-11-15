#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "CovidCollection.h"

using namespace std;
namespace sdds {
	CovidCollection::CovidCollection(const std::string filename) {
		Covid covidData;
		fstream file(filename);
		if (!file.is_open()) {
			throw "Error, File Cannot Open";
		}
		else {
			string line;
			while (getline(file, line)) {
				covidData.m_country = line.substr(0, 25);
				covidData.m_city = line.substr(25, 25);
				covidData.m_variant = line.substr(50, 25);
				covidData.m_year = std::stoi(line.substr(75, 5));
				covidData.num_cases = std::stoul(line.substr(80, 5));
				covidData.num_deaths = std::stoul(line.substr(85, 5));

				covidData.m_country = trimString(covidData.m_country);
				covidData.m_city = trimString(covidData.m_city);
				covidData.m_variant = trimString(covidData.m_variant);
				collection.push_back(covidData);
			}
		}


	}

	std::string CovidCollection::trimString(std::string str) {
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
		return str;
	}

	void CovidCollection::display(std::ostream& out) const {
		for_each(collection.begin(), collection.end(), [&out](const Covid data) {
			out << data;
			});
	}

	std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
		out << "| " << setw(21) << left << theCovid.m_country << " | " << setw(15) << theCovid.m_city << " | "
			<< setw(20) << theCovid.m_variant << " | " << right << setw(6);
		if (theCovid.m_year > 0) {
			out << theCovid.m_year << " | ";
		}
		else {
			out << " " << " | ";
		}

		out << setw(4) << theCovid.num_cases << " | "
			<< setw(3) << theCovid.num_deaths << " | " << endl;

		return out;
	}

}