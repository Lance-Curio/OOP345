// Lance Curio
// 104319223
// lcurio@myseneca.ca
// 2023-10-22
#include <iomanip>
#include <iostream>
#include <string>
#include "Book.h"

using namespace std;
namespace sdds {

    const string& sdds::Book::title() const {
        return m_title;
    }

    const std::string& Book::country() const {
        return m_country;
    }

    const size_t& Book::year() const {
        return m_year;
    }

    double& Book::price() {
        return m_price;
    }

    Book::Book(const string& strBook) {
        size_t pos = 0;

        m_author = strBook.substr(0, strBook.find(','));
        m_author.erase(0, m_author.find_first_not_of(" "));
        m_author.erase(m_author.find_last_not_of(" ") + 1);

        pos = strBook.find(',') + 1;

        m_title = strBook.substr(pos, strBook.find(',', pos) - pos);
        m_title.erase(0, m_title.find_first_not_of(" "));
        m_title.erase(m_title.find_last_not_of(" ") + 1);

        pos = strBook.find(',', pos) + 1;

        m_country = strBook.substr(pos, strBook.find(',', pos) - pos);
        m_country.erase(0, m_country.find_first_not_of(" "));
        m_country.erase(m_country.find_last_not_of(" ") + 1);

        pos = strBook.find(',', pos) + 1;

        m_price = stod(strBook.substr(pos, strBook.find(',', pos) - pos));

        pos = strBook.find(',', pos) + 1;

        m_year = stoul(strBook.substr(pos, strBook.find(',', pos) - pos));

        m_desc = strBook.substr(strBook.find(',', pos) + 1);
        m_desc.erase(0, m_desc.find_first_not_of(" "));
        m_desc.erase(m_desc.find_last_not_of(" ") + 1);
    }


    std::ostream& operator<<(std::ostream& os, const Book book) {
        os << setw(20) << right << book.m_author << " | "
            << setw(22) << right << book.m_title << " | "
            << setw(5) << right << book.m_country << " | "
            << setw(4) << right << book.m_year << " | "
            << setw(6) << setprecision(2) << fixed << book.m_price << " | "
            << book.m_desc << endl;
        return os;
    }

}
