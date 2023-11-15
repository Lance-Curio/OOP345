#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H

#include <string>
#include <vector>
#include <iostream>

namespace sdds {
	struct Covid {
		std::string m_country;
		std::string m_city;
		std::string m_variant;
		int m_year;
		unsigned int num_cases;
		unsigned int num_deaths;
	};

	class CovidCollection {
		std::vector<Covid> collection;
	public:
		std::string trimString(std::string str);
		CovidCollection(const std::string filename);
		void display(std::ostream& out) const;
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif // !SDDS_COVIDCOLLECTION_H
