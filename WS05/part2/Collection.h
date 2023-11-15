// Lance Curio
// 104319223
// lcurio@myseneca.ca
// 2023-10-22
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>

namespace sdds {
	template <typename T>
	class Collection {
		std::string m_name{};
		T* m_items{};
		size_t m_size{};
		void (*m_observer)(const Collection<T>&, const T&);
	public:
		Collection(const std::string name) {
			m_name = name;
			m_items = nullptr;
			m_size = 0;
			m_observer = nullptr;
		}

		Collection(const Collection& other) = delete;
		Collection(Collection&& other) = delete;
		Collection& operator=(const Collection& other) = delete;
		Collection& operator=(Collection&& other) = delete;
		~Collection() {
			delete[] m_items;
		}

		const std::string& name() const {
			return m_name;
		}
		size_t size() const {
			return m_size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		}
		Collection<T>& operator+=(const T& item) {
			bool hasItem = false;
			for (size_t i = 0; i < m_size; i++) {
				if (item.title() == m_items[i].title()) {
					hasItem = true;
				}
			}
			if (!hasItem) {
				T* newItem = new T[m_size + 1];
				for (size_t i = 0; i < m_size; i++) {
					newItem[i] = m_items[i];
				}
				delete[] m_items;
				newItem[m_size] = item;
				m_items = newItem;
				m_size++;
				if (m_observer) {
					m_observer(*this, item);
				}
			}
			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx >= m_size) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
			}
			return m_items[idx];
		}
		T* operator[](const std::string& title) const {
			for (size_t i = 0; i < m_size; i++) {
				if (m_items[i].title() == title) {
					return &m_items[i];
				}
			}
			return nullptr;
		}
	};
	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& collect){
		for (size_t i = 0; i < collect.size(); i++) {
			os << collect[i];
		}
		return os;
	}
}
#endif // !SDDS_COLLECTION_H
