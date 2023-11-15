// Lance Curio
// 104319223
// lcurio@myseneca.ca
// November 12, 2023
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
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
		file.close();
	}

	std::string CovidCollection::trimString(std::string str) {
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
		return str;
	}

	void CovidCollection::display(std::ostream& out, std::string country) const {
		size_t totalCase = accumulate(collection.begin(), collection.end(), (size_t)0, [](size_t sum, const Covid data) {
			return sum + data.num_cases; });
		size_t totalDeath = accumulate(collection.begin(), collection.end(), (size_t)0, [](size_t sum, const Covid data) {
			return sum + data.num_deaths; });
		if (country != "ALL") {
			out << "Displaying information of country = " << country << endl;
			size_t countryCase = accumulate(collection.begin(), collection.end(), (size_t)0, [country](size_t sum, const Covid data) {
				if (data.m_country == country) {
					sum += data.num_cases;
				}
				return sum;
				});
			size_t countryDeath = accumulate(collection.begin(), collection.end(), (size_t)0, [country](size_t sum, const Covid data) {
				if (data.m_country == country) {
					sum += data.num_deaths;
				}
				return sum;
				});
			for_each(collection.begin(), collection.end(), [&out, country](const Covid data) {
				if (data.m_country == country) {
					out << data << endl;
				}
				});
			out << "----------------------------------------------------------------------------------------" << endl
				<< "| " << setw(78) << right << "Total cases in " + country << ": " << countryCase << " |" << endl
				<< "| " << setw(78) << right << "Total deaths in " + country << ": " << countryDeath << " |" << endl;
			double percentCase = static_cast<double>((countryCase) / static_cast<double>(totalCase)) * 100;
			double percentDeath = static_cast<double>((countryDeath) / static_cast<double>(totalDeath)) * 100;
			out << "| " << setw(86) << right << country + " has " + to_string(percentCase) + "% of global cases and " + to_string(percentDeath) + "% of global deaths |" << endl;
		}
		else {
			for_each(collection.begin(), collection.end(), [&out](const Covid data) {
				out << data << endl; });
			out << "| " << setw(79) << right << "Total cases around the world: " << totalCase << " |" << endl;
			out << "| " << setw(79) << right << "Total deaths around the world: " << totalDeath << " |" << endl;
		}
	}

	void CovidCollection::sort(const std::string& field) {
		std::sort(collection.begin(), collection.end(), [field](Covid& a, Covid& b) {
			if (field == "country") {
				if (a.m_country == b.m_country) {
					return a.num_deaths < b.num_deaths;
				}
				return a.m_country < b.m_country;
			}
			else if (field == "city") {
				if (a.m_city == b.m_city) {
					return a.num_deaths < b.num_deaths;
				}
				return a.m_city < b.m_city;
			}
			else if (field == "variant") {
				if (a.m_variant == b.m_variant) {
					return a.num_deaths < b.num_deaths;
				}
				return a.m_variant < b.m_variant;
			}
			else if (field == "year") {
				if (a.m_year == b.m_year) {
					return a.num_deaths < b.num_deaths;
				}
				return a.m_year < b.m_year;
			}
			else if (field == "cases") {
				if (a.num_cases == b.num_cases) {
					return a.num_deaths < b.num_deaths;
				}
				return a.num_cases < b.num_cases;
			}
			else {
				if (a.m_country == b.m_country) {
					return a.num_deaths < b.num_deaths;
				}
				return a.m_country < b.m_country;
			}
			});
	}


	bool CovidCollection::inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const {
		bool result = false;
		for_each(collection.begin(), collection.end(), [&](const Covid data) {
			if (variant == data.m_variant && country == data.m_country && deaths < data.num_deaths) {
				result = true;
			}
			});
		return result;
	}

	std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) const {
		list<Covid> result;
		copy_if(collection.begin(), collection.end(), back_inserter(result), [deaths](const Covid data) {
			return data.num_deaths >= deaths;
			});
		return result;
	}

	void CovidCollection::updateStatus() {
		std::transform(collection.begin(), collection.end(), collection.begin(), [](Covid data) {
			if (data.num_deaths > 300) {
				data.m_status = "EPIDEMIC";
			}
			else if (data.num_deaths < 50) {
				data.m_status = "EARLY";
			}
			else {
				data.m_status = "MILD";
			}
			return data;
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
			<< setw(3) << theCovid.num_deaths << " | "
			<< "| " << right << setw(8) << theCovid.m_status << " |";

		return out;
	}
}