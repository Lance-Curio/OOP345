// Lance Curio
// 104319223
// lcurio@myseneca.ca
// 10-01-2023
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include "Book.h"
#include <iostream>

namespace sdds {
	template<typename T, unsigned C>
	class Collection {
		T m_items[C]{};
		unsigned m_cnt{};
		static T m_smallestItem;
		static T m_largestItem;
	protected:
		void setSmallestItem(const T& item);
		void setLargestItem(const T& item);
		T& operator[](unsigned index);
		void incrSize();
	public:
		static T getSmallestItem();
		static T getLargestItem();

		unsigned size() const {
			return m_cnt;
		}
		unsigned capacity() const {
			return C;
		}
		bool operator+=(const T& item);

		std::ostream& print(std::ostream& os) const;
	};
	template<typename T, unsigned C>
	T Collection<T, C>::m_smallestItem = 9999;

	template<typename T, unsigned C>
	T Collection<T, C>::m_largestItem = -9999;

	template<>
	Book Collection<Book, 10>::m_smallestItem("", 1, 10000);

	template<>
	Book Collection<Book, 10>::m_largestItem("", 10000, 1);

	template<>
	Book Collection<Book, 72>::m_smallestItem("", 1, 10000);

	template<>
	Book Collection<Book, 72>::m_largestItem("", 10000, 1);

	template<>
	std::ostream& Collection<Book, 72>::print(std::ostream& os) const{
		os << "| ---------------------------------------------------------------------------|\n";
		for (unsigned i = 0; i < m_cnt; ++i) {
			os << "| ";
			m_items[i].print(os) << " |" << std::endl;
		}
		os << "| ---------------------------------------------------------------------------|\n";
		return os;
	}

	template <>
	std::ostream& Collection<Book, 10>::print(std::ostream& os) const {
		os << "| ---------------------------------------------------------------------------|\n";
		for (unsigned i = 0; i < m_cnt; ++i) {
			os << "| ";
			m_items[i].print(os) << " |" << std::endl;
		}
		os << "| ---------------------------------------------------------------------------|\n";
		return os;
	}


	template<typename T, unsigned C>
	void Collection<T, C>::setSmallestItem(const T& item) {
		if (item < m_smallestItem) {
			m_smallestItem = item;
		}
	}

	template<typename T, unsigned C>
	void Collection<T, C>::setLargestItem(const T& item) {
		if (m_largestItem < item) {
			m_largestItem = item;
		}
	}

	template<typename T, unsigned C>
	inline T& Collection<T, C>::operator[](unsigned index){
		if (index < m_cnt) {
			return m_items[index];
		}
		return m_items[0];
	}

	template<typename T, unsigned C>
	inline void Collection<T, C>::incrSize(){
		m_cnt++;
	}

	template<typename T, unsigned C>
	inline T Collection<T, C>::getSmallestItem(){
		return m_smallestItem;
	}

	template<typename T, unsigned C>
	inline T Collection<T, C>::getLargestItem()
	{
		return m_largestItem;
	}

	template<typename T, unsigned C>
	inline bool Collection<T, C>::operator+=(const T& item){
		if (size() != capacity()) {
			setSmallestItem(item);
			setLargestItem(item);

			m_items[m_cnt++] = item;

			return true;
		}
		return false;
	}

	template<typename T, unsigned C>
	inline std::ostream& Collection<T, C>::print(std::ostream& os) const{
		os << "[";
		for (unsigned i = 0; i < m_cnt; ++i) {
			os << m_items[i];
			if (i < m_cnt - 1) {
				os << ",";
			}
		}
		os << "]\n";
		return os;
	}
}

#endif // !SDDS_COLLECTION_H
