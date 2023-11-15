// Lance Curio
// 104319223
// lcurio@myseneca.ca
// 2023-10-22
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>

namespace sdds {
	class Movie {
		std::string m_title{""};
		size_t m_year{0};
		std::string m_desc{""};
	public:
		Movie();
		Movie(const std::string& strMovie);
		const std::string& title() const;
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_desc);
			spellChecker(m_title);
		}
	};
}
#endif // !SDDS_MOVIE_H
