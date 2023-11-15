// Lance Curio
// 104319223
// lcurio@myseneca.ca
// November 12, 2023
#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H

#include <string>
#include <vector>
#include <iostream>
#include <list>

namespace sdds {
	struct Covid {
		std::string m_country;
		std::string m_city;
		std::string m_variant;
		std::string m_status{ "General" };
		int m_year{};
		unsigned int num_cases{};
		unsigned int num_deaths{};
	};

	class CovidCollection {
		std::vector<Covid> collection;
	public:
		std::string trimString(std::string str);
		CovidCollection(const std::string filename);
		void display(std::ostream& out, std::string country = "ALL") const;
		void sort(const std::string& field = "country");
		bool inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const;
		std::list<Covid> getListForDeaths(unsigned int deaths) const;
		void updateStatus();
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif // !SDDS_COVIDCOLLECTION_H
