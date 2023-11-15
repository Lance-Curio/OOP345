// LANCE CURIO
// 104319223
// lcurio@myseneca.ca
// October 10, 2023
#include <iostream>
#include "CheeseParty.h"
#include "Cheese.h"

using namespace std;

namespace sdds {
	CheeseParty::CheeseParty() {
		m_cheese = nullptr;
		m_size = 0;
	}

	CheeseParty& CheeseParty::addCheese(const Cheese& cheese){
		bool exist = false;
		for (size_t i = 0; i < m_size; i++) {
			if (m_cheese[i] == &cheese) {
				exist = true;
			}
		}
		if (!exist) {
			const Cheese** newCheese = new const Cheese * [m_size + 1];
			for (size_t i = 0; i < m_size; i++) {
				newCheese[i] = m_cheese[i];
			}
			delete[] m_cheese;
			newCheese[m_size] = &cheese;
			m_cheese = newCheese;
			m_size++;
		}
		return *this;
	}

	CheeseParty& CheeseParty::removeCheese(){
		for (size_t i = 0; i < m_size; i++) {
			if (m_cheese[i]->getWeight() == 0.0) {
				m_cheese[i] = nullptr;
			}
		}
		return *this;
	}

	CheeseParty::CheeseParty(const CheeseParty& other){
		*this = other;
	}

	CheeseParty::CheeseParty(CheeseParty&& other){
		*this = move(other);
		other.m_cheese = nullptr;
		other.m_size = 0;
	}

	CheeseParty& CheeseParty::operator=(const CheeseParty& other) {
		if (this != &other) {
			//2. cleanup	
			delete[] m_cheese;

			//3. shallow copy
			if (other.m_cheese != nullptr) {
				m_size = other.m_size;
				m_cheese = new const Cheese * [m_size];
			}
			//.4 deep copy
			for (size_t i = 0; i < m_size; ++i) {
				m_cheese[i] = other.m_cheese[i];
			}
		}
		else {
			m_cheese = nullptr;
			m_size = 0;
		}
		return *this;
	}

	CheeseParty& CheeseParty::operator=(CheeseParty&& other) {
		if (this != &other) {
			//2. cleanup
			delete[] m_cheese;

			//3. shallow copy
			m_size = other.m_size;
			//4. move
			m_cheese = other.m_cheese;
			other.m_cheese = nullptr; 
			other.m_size = 0;
		}
		return *this;
	}

	CheeseParty::~CheeseParty(){
		delete[] m_cheese;
	}


	std::ostream& operator<<(std::ostream& os,const CheeseParty& party){
		os << "--------------------------" << endl
			<< "Cheese Party" << endl
			<< "--------------------------" << endl;
		if (party.m_cheese) {
			for (size_t i = 0; i < party.m_size; i++) {
				if (party.m_cheese[i] != nullptr) {
					os << *party.m_cheese[i];
				}
			}
		}
		else {
			os << "This party is just getting started!" << endl;
		}
		os << "--------------------------" << endl;

		return os;
	}


}