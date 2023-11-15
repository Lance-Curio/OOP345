#include <iostream>
#include <string>
#include "Resource.h"
#include "Flags.h"
#include "File.h"

using namespace std;

namespace sdds{
	File::File(std::string filename, std::string contents) : Resource(){
		m_name = filename;
		m_contents = contents;
	}
	void File::update_parent_path(const std::string& update_path){
		m_parent_path = update_path;
	}

	NodeType File::type() const{
		return NodeType::FILE;
	}

	std::string File::path() const{
		return m_parent_path + m_name;
	}

	std::string File::name() const{
		return m_name;
	}

	int File::count() const{
		return -1;
	}

	size_t File::size() const{
		return m_contents.length();
	}


}