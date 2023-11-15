// Lance Curio
// 104319223
// lcurio@myseneca.ca
// November 05 2023
#ifndef SDDS_DIRECTORY_H
#define SDDS_DIRECTORY_H

#include <vector>
#include <string>
#include "Resource.h"

namespace sdds {
	class Directory : public Resource {
		std::vector<Resource*> m_contents;
	public:
		Directory(const std::string name);
		void update_parent_path(const std::string& update_path);
		NodeType type() const;
		std::string path() const;
		std::string name() const;
		int count() const;
		size_t size() const;
		Directory& operator+=(Resource* res);
		Resource* find(const std::string& n_name, const std::vector<OpFlags> &flag = std::vector<OpFlags>());
		void remove(const std::string& name, const std::vector<OpFlags>&flag = std::vector<OpFlags>());
		void display(std::ostream&, const std::vector<FormatFlags>&flag = std::vector<FormatFlags>()) const;
		~Directory();
		Directory& operator=(const Directory& other) = delete;
		Directory& operator=(Directory&& other) = delete;
		Directory(const Directory& other) = delete;
		Directory(Directory&& other) = delete;
	};
}
#endif // !SDDS_DIRECTORY_H
