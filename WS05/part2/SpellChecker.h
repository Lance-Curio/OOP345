// Lance Curio
// 104319223
// lcurio@myseneca.ca
// 2023-10-22
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
#include <string>

namespace sdds {
	class SpellChecker {
		std::string m_badWords[6];
		std::string m_goodWords[6];
		static size_t m_replace[6];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif // !SDDS_SPELLCHECKER_H
