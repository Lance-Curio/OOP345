#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include <iostream>
#include <string>
#include <vector>
#include "Resource.h"

namespace sdds {
	class File : public Resource {
		std::string m_contents{};
	public:
		File() = default;
		File(std::string filename, std::string contents = "");
		void update_parent_path(const std::string& update_path);
		NodeType type() const; 
		std::string path() const;
		std::string name() const;
		int count() const;
		size_t size() const;
	};
}
#endif // !SDDS_FILE_H
