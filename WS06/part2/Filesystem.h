// Lance Curio
// 104319223
// lcurio@myseneca.ca
// November 05 2023
#ifndef SDDS_FILESYSTEM_H
#define SDDS_FILESYSTEM_H

#include <string>
#include <vector>
#include "Directory.h"

namespace sdds {
	class Filesystem{
		Directory* m_root;
		Directory* m_current;
	public:
		Filesystem(const std::string& filename, const std::string dirRoot = "");
		std::vector<std::string> splitString(std::string str, const char seperate);
		std::string removeWhitespace(std::string str);

		Filesystem& operator+=(Resource* res);
		Directory* change_directory(const std::string& dirName = "");
		Directory* get_current_directory(const std::string& = "");

		Filesystem& operator=(const Filesystem& other) = delete;
		Filesystem& operator=(Filesystem&& other);
		Filesystem(const Filesystem& other) = delete;
		Filesystem(Filesystem&& other);
		~Filesystem();
	}; 
}
#endif // !SDDS_FILESYSTEM_H
