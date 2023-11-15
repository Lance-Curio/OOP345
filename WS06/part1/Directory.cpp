
#include <iostream>
#include <vector>
#include <string>
#include "Resource.h"
#include "Flags.h"
#include "Directory.h"

using namespace std;

namespace sdds {
	Directory::Directory(const std::string name){
		m_name = name;
	}
	void Directory::update_parent_path(const std::string& update_path){
		for (auto& i : m_contents) {
			if (m_parent_path != "/") {
				i->update_parent_path(update_path);
			}
		}
	}
	NodeType Directory::type() const{
		return NodeType::DIR;
	}
	std::string Directory::path() const{
		return m_parent_path + m_name;
	}
	std::string Directory::name() const{
		return m_name;
	}

	int Directory::count() const{
		return static_cast<int>(m_contents.size());
	}

	size_t Directory::size() const{
		size_t result = 0u;

		for (auto& item : m_contents) {
			result += item->size();
		}

		return result;
	}

	Directory& Directory::operator+=(Resource* res){
		for (auto& item : m_contents) {
			if (item->name() != res->name()) {
				m_contents.push_back(res);
				m_contents.back()->update_parent_path(path());
			}
			else {
				throw "Error";
			}
		}

		return *this;
	}

	Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flag){
		Resource* result = nullptr;
		for (auto& item : m_contents) {
			if (item->name() == name) {
				result = item;
			}
			else if (item->type() == NodeType::DIR && !flag.empty()) {
				Directory* dir = dynamic_cast<Directory*>(item);
				if (dir) {
					result = dir->find(name, flag);
					if (result != nullptr) {
						break;
					}
				}
			}
		}
		return result;
	}

	Directory::~Directory(){
		for (auto& item : m_contents) {
			delete item;
		}
	}
}

