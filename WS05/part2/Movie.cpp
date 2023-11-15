// Lance Curio
// 104319223
// lcurio@myseneca.ca
// 2023-10-22
#include <iomanip>
#include <iostream>
#include <string>
#include "Movie.h"

using namespace std;

namespace sdds {
    Movie::Movie() {};
    Movie::Movie(const std::string& strMovie) {
        size_t pos = 0;

        m_title = strMovie.substr(0, strMovie.find(','));
        m_title.erase(0, m_title.find_first_not_of(" "));
        m_title.erase(m_title.find_last_not_of(" ") + 1);

        pos = strMovie.find(',') + 1;

        m_year = stoul(strMovie.substr(pos, strMovie.find(',', pos) - pos));

        m_desc = strMovie.substr(strMovie.find(',', pos) + 1);
        m_desc.erase(0, m_desc.find_first_not_of(" "));
        m_desc.erase(m_desc.find_last_not_of(" ") + 1);
	}
	const std::string& Movie::title() const{
		return m_title;
	}

    std::ostream& operator<<(std::ostream& os, const Movie& movie){
        os << right << setw(40) << movie.m_title << " | "
            << setw(4) << movie.m_year << " | "
            << left << movie.m_desc << endl;
        return os;
    }

}