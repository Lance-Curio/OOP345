// Name: LANCE CURIO	
// Seneca Student ID: 104319223
// Seneca email: lcurio@myseneca.ca
// Date of completion: 11-11-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>

namespace sdds {
	class Station {
		size_t m_id;
		std::string m_name;
		std::string m_desc;
		size_t m_serialNumber;
		size_t m_stock;

		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;

	};
}
#endif // !SDDS_STATION_H
