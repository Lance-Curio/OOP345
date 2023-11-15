// LANCE CURIO
// 104319223
// lcurio@myseneca.ca
// October 10, 2023
#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H

#include "Cheese.h"

namespace sdds {
	class CheeseShop { 
		std::string m_name{"No Name"};
		Cheese const** m_cheese{};
		size_t m_size{};
	public:
		CheeseShop() {};
		CheeseShop(const std::string& name = "No Name");
		CheeseShop& addCheese(const Cheese& cheese);

		CheeseShop(const CheeseShop& other);
		CheeseShop(CheeseShop&& other);
		CheeseShop& operator=(const CheeseShop& other);
		CheeseShop& operator=(CheeseShop&& other);
		~CheeseShop();

		friend std::ostream& operator<<(std::ostream& os,const CheeseShop& shop);
	};
}
#endif // !SDDS_CHEESESHOP_H
