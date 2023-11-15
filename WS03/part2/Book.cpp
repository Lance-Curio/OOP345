// Lance Curio
// 104319223
// lcurio@myseneca.ca
// 10-01-2023
#include <iostream>
#include <iomanip>
#include "Book.h"

using namespace std;

namespace sdds {
	Book::Book() {
		m_title = "Invalid book data";
		m_numChapters = 0;
		m_numPages = 0;
	}

	Book::Book(const std::string& title, unsigned nChapters, unsigned nPages) {
		m_title = title;
		m_numChapters = nChapters;
		m_numPages = nPages;
		
	}

	std::ostream& Book::print(std::ostream& os) const {
		if (!m_title.empty() && m_numChapters > 0 && m_numPages > 0) {
			double avg = static_cast<double>(m_numPages) / m_numChapters;
			string rightOutput = m_title + "," + to_string(m_numChapters) + "," + to_string(m_numPages);
			string leftOutput = "(" + to_string(avg) + ")";
			os << setw(56) << right << rightOutput << " | " << setw(15) << left << setprecision(6) << leftOutput;
		}
		else {
			os << "| Invalid book data";
		}
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Book& bk) {
		bk.print(os);
		return os;
	}

	Book::operator bool() {
		return m_title.length();
	}
	Book& Book::operator=(const Book& other)
	{
		if (this != &other) {
			m_title = other.m_title;
			m_numChapters = other.m_numChapters;
			m_numPages = other.m_numPages;
		}
		return *this;
	}
	bool Book::operator<(const Book& other) const
	{
		return ((double)m_numPages / m_numChapters) < ((double)other.m_numPages / other.m_numChapters);
	}
	bool Book::operator>(const Book& other) const
	{
		return ((double)m_numPages / m_numChapters) > ((double)other.m_numPages / other.m_numChapters);
	}
}