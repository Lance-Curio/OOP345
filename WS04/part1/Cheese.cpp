#include <iostream>
#include <string>
#include <iomanip>
#include "Cheese.h"

using namespace std;

namespace sdds {
	Cheese::Cheese(const string& str) {
		size_t pos = 0;

		pos = str.find_first_of(",");
		string name = str.substr(0, pos);
		m_name = name;
		m_name.erase(0, m_name.find_first_not_of(" "));
		m_name.erase(m_name.find_last_not_of(" ") + 1);

		pos = str.find(",", pos) + 1;
		size_t comma = str.find(',', pos);
		string weight = str.substr(pos, comma - pos);
		m_weight = stoul(weight);

		pos = str.find(",", pos) + 1;
		size_t nextcomma = str.find(',', pos);
		string price = str.substr(pos, nextcomma - pos);
		m_price = stod(price);

		pos = str.find(",", pos) + 1;
		m_feature = str.substr(pos);

		for (int i = 0; i < int(m_feature.length()); i++) {
			if (m_feature[i] == ' ') {
				m_feature.erase(i, 1);
				--i;
			}
		}
		for (int i = 0; i < int(m_feature.length()); i++) {
			if (m_feature[i] == ',') {
				m_feature[i] = ' ';
			}
		}
		m_feature += ' ';
	}



	Cheese Cheese::slice(size_t weight){
		if (weight <= this->m_weight) {
			Cheese slicedCheese(*this);

			this->m_weight -= weight;

			return slicedCheese;
		}
		return Cheese();
	}

	string Cheese::getName() const{
		return m_name;
	}

	size_t Cheese::getWeight() const{
		return m_weight;
	}

	double Cheese::getPrice() const{
		return m_price;
	}

	std::string Cheese::getFeature() const{
		return m_feature;
	}
	std::ostream& operator<<(std::ostream& os, const Cheese& other){
		os << "|"
			<< left << setw(21) << other.getName()
			<< "|"
			<< setw(5) << other.getWeight()
			<< "|"
			<< fixed << setw(5) << setprecision(2) << other.getPrice()
			<< "|"
			<< right << setw(34) << other.getFeature()
			<< "|" << endl;
		return os;
	}
}