// LANCE CURIO
// 104319223
// lcurio@myseneca.ca
// October 10, 2023
#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H

#include "Cheese.h"

namespace sdds {
	class CheeseParty {
		const Cheese** m_cheese{};
		size_t m_size{};
	public:
		CheeseParty();
		CheeseParty& addCheese(const Cheese& cheese);
		CheeseParty& removeCheese();

		CheeseParty(const CheeseParty& other);
		CheeseParty(CheeseParty&& other);
		CheeseParty& operator=(const CheeseParty& other);
		CheeseParty& operator=(CheeseParty&& other);
		~CheeseParty();

		friend std::ostream& operator<<(std::ostream& os, const CheeseParty& party);
	};
}
#endif // !SDDS_CHEESEPARTY_H
