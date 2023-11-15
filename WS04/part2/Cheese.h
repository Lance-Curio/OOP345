// LANCE CURIO
// 104319223
// lcurio@myseneca.ca
// October 10, 2023
#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H

#include <string>


namespace sdds {
	class Cheese {
		std::string m_name{"NaC"};
		size_t m_weight{};
		double m_price{};
		std::string m_feature{};
	public:
		Cheese() {};
		Cheese(const std::string& str);
		Cheese slice(size_t weight);

		//set of queries
		std::string getName() const;
		size_t getWeight() const;
		double getPrice() const;
		std::string getFeature() const;
	};
	std::ostream& operator<<(std::ostream& os, const Cheese& other);
}
#endif // !SDDS_CHEESE_H
