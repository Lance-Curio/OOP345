// LANCE CURIO
// 104319223
// lcurio@myseneca.ca
// October 10, 2023
#include <string>
#include <iostream>
#include "CheeseShop.h"

using namespace std;

namespace sdds {
	CheeseShop::CheeseShop(const string& name) {
		m_name = name;
	}

	CheeseShop& CheeseShop::addCheese(const Cheese& cheese){
		const Cheese* copy = new const Cheese(cheese);
		const Cheese** newCheese = new const Cheese * [m_size + 1];
		for (size_t i = 0; i < m_size; i++) {
			newCheese[i] = m_cheese[i];
		}
		delete[] m_cheese;
		m_cheese = newCheese;
		m_cheese[m_size] = copy;
		m_size++;
		return *this;
	}

	CheeseShop::~CheeseShop() {
		for (size_t i = 0; i < m_size; i++){
			delete m_cheese[i];
		}
		delete[] m_cheese;
	}

	CheeseShop::CheeseShop(const CheeseShop& other){
		*this = other;
	}

	CheeseShop::CheeseShop(CheeseShop&& other){
		*this = move(other);
	}

	CheeseShop& CheeseShop::operator=(const CheeseShop& other) {
		if (this != &other) {
			for (size_t i = 0; i < m_size; i++) {
				delete m_cheese[i];
			}
			delete[] m_cheese;
			m_name = other.m_name;
			m_size = other.m_size;
			if (other.m_cheese != nullptr) {
				m_cheese = new const Cheese * [m_size];
			}
			for (size_t i = 0; i < m_size; i++) {
				m_cheese[i] = new const Cheese(*other.m_cheese[i]);
			}
		}
		else {
			m_cheese = nullptr;
			m_size = 0;
		}
		return *this;
	}

	CheeseShop& CheeseShop::operator=(CheeseShop&& other) {
		if (this != &other) {
			for (size_t i = 0; i < m_size; i++) {
				delete m_cheese[i];
			}
			delete[] m_cheese;

			m_cheese = other.m_cheese;
			m_size = other.m_size;
			m_name = other.m_name;

			other.m_cheese = nullptr;
			other.m_name = "";
			other.m_size = 0;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os,const CheeseShop& shop) {
		os << "--------------------------" << endl
			<< shop.m_name << endl
			<< "--------------------------" << endl;
		if (shop.m_cheese) {
			for (size_t i = 0; i < shop.m_size; i++) {
				if (shop.m_cheese[i]) {
					os << *shop.m_cheese[i];
				}
			}
		}
		else {
			os << "This shop is out of cheese!" << endl;
		}
		os << "--------------------------" << endl;

		return os;
	}
}
