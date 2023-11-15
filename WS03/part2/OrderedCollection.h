// Lance Curio
// 104319223
// lcurio@myseneca.ca
// 10-01-2023
#ifndef SDDS_ORDERED_COLLECTION_H
#define SDDS_ORDERED_COLLECTION_H

#include "Collection.h"

namespace sdds{
	template <typename T>
	class OrderedCollection : public Collection<T, 72>
	{
	public:
		bool operator+=(const T& item) {
			if (this->size() < this->capacity()) {
				Collection<T, 72>::incrSize();
				if (item > Collection<T, 72>::getLargestItem()) {
					Collection<T, 72>::operator[](Collection<T, 72>::size() - 1) = item;
					Collection<T, 72>::setLargestItem(item);
				}
				else {
					unsigned int index = 0;
					bool flag = false;
					while (!flag && index < Collection<T, 72>::size()) {
						if (Collection<T, 72>::operator[](index) > item) {
							flag = true;
						}
						else {
							index++;
						}
					}
					for (unsigned i = Collection<T, 72>::size() - 1; i > index; i--) {
						Collection<T, 72>::operator[](i) = Collection<T, 72>::operator[](i - 1);
					}
					Collection<T, 72>::operator[](index) = item;
				}

				Collection<T, 72>::setSmallestItem(item);
				return true;
			}
			else {
				return false;
			}
		}
	};
}

#endif // !SDDS_ORDERED_COLLECTION_H
