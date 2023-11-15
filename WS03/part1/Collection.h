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

	public:
		static T getSmallestItem();
		static T getLargestItem();

		unsigned size() const {
			return m_cnt;
		}
		unsigned capacity() const {
			return C;
		}
		bool operator+=(const T& item) {
			if (size() != capacity()) {
				setSmallestItem(item);
				setLargestItem(item);

				m_items[m_cnt++] = item;

				return true;
			}
			return false;
		}
		std::ostream& print(std::ostream& os) const {
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
	};
	template<typename T, unsigned C>
	T Collection<T, C>::m_smallestItem = 9999;

	template<typename T, unsigned C>
	T Collection<T, C>::m_largestItem = -9999;

	template<>
	Book Collection<Book, 10>::m_smallestItem("", 1, 10000);

	template<>
	Book Collection<Book, 10>::m_largestItem("", 10000, 1);

	template<typename T, unsigned C>
	void Collection<T, C>::setSmallestItem(const T& item) {
		if (item < m_smallestItem) {
			m_smallestItem = item;
		}
	}

	template<typename T, unsigned C>
	void Collection<T, C>::setLargestItem(const T& item) {
		if (item > m_largestItem) {
			m_largestItem = item;
		}
	}
	template<typename T, unsigned C>
	inline T Collection<T, C>::getSmallestItem()
	{
		return m_smallestItem;
	}
	template<typename T, unsigned C>
	inline T Collection<T, C>::getLargestItem()
	{
		return m_largestItem;
	}
}

#endif // !SDDS_COLLECTION_H
