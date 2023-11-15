// Lance Curio
// 104319223
// lcurio@myseneca.ca
// November 05 2023
#include <iostream>
#include <vector>
#include <fstream>
#include "File.h"
#include "Directory.h"
#include "Filesystem.h"
using namespace std;
namespace sdds {
	Filesystem::Filesystem(const std::string& filename, const std::string root) {
        ifstream file(filename);
        if (file.is_open()) {
            m_root = new Directory(root);
            m_current = m_root;
            std::string line;
            while (std::getline(file, line)) {
                Directory* Dir = m_root;
                if (line.find('|') != std::string::npos) {
                    std::vector<std::string> lineComponent = splitString(line, '|');
                    std::vector<std::string> pathComponent = splitString(lineComponent.front(), '/');
                    for (size_t i = 0; i < pathComponent.size() - 1; i++) {
                        Resource* resource = Dir->find(pathComponent[i] + '/');
                        if (resource == nullptr) {
                            Directory* newDir = new Directory(pathComponent[i] + '/');
                            *Dir += newDir;
                            Dir = newDir;
                        }
                        else {
                            Dir = static_cast<Directory*>(resource);
                        }
                    }
                    if (Dir->find(pathComponent.back()) == nullptr) {
                        File* newFile = new File(pathComponent.back(), lineComponent.back());
                        *Dir += newFile;
                    }
                }
                else {
                    std::vector<std::string> pathComponent = splitString(line, '/');
                    for (size_t i = 0; i < pathComponent.size(); i++) {
                        Resource* resource = Dir->find(pathComponent[i] + '/');
                        if (resource == nullptr) {
                            Directory* newDir = new Directory(pathComponent[i] + '/');
                            *Dir += newDir;
                            Dir = newDir;
                        }
                        else {
                            Dir = static_cast<Directory*>(resource);
                        }
                    }
                }
            }
        }
        else {
            throw ("File cannot open.");
        }
	}

    std::vector<std::string> Filesystem::splitString(std::string str, const char seperate) {
        std::vector<std::string> flag;
        size_t pos = 0;
        while ((pos = str.find(seperate)) != std::string::npos) {
            flag.push_back(this->removeWhitespace(str.substr(0, pos)));
            str.erase(0, pos + 1);
        }
        str = this->removeWhitespace(str);
        if (!str.empty()) {
            flag.push_back(str);
        }
        return flag;
    }
    std::string Filesystem::removeWhitespace(std::string str) {
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ') + 1);
        return str;
    }
	Filesystem& Filesystem::operator+=(Resource* res){
		*m_current += res;
		return *this;
	}
	Directory* sdds::Filesystem::change_directory(const std::string& dirName){
        if (dirName.empty()) {
            m_current = m_root;
        }
        else {
            if (m_current->find(dirName) != nullptr) {
                m_current = dynamic_cast<Directory*>(m_current->find(dirName));
            }
            else {
                throw std::invalid_argument("Cannot change directory! DIR_NAME not found!");
            }
        }
		return m_current;
	}

	Directory* Filesystem::get_current_directory(const std::string& dirName){
		if (dirName == "") {
			m_current = m_root;
		}
		else {
			if (m_current->find(dirName) != nullptr) {
				m_current = dynamic_cast<Directory*>(m_current->find(dirName));
			}
			else {
				throw invalid_argument("Cannot change directory! DIR_NAME not found!");
			}
		}
		return m_current;
	}

	Filesystem& Filesystem::operator=(Filesystem&& other){
		if (this != &other) {
			delete m_root;
			m_root = other.m_root;
			m_current = other.m_current;
			other.m_current = nullptr;
			other.m_root = nullptr;
		}
		return *this;
	}

	Filesystem::Filesystem(Filesystem&& other){
		*this = std::move(other);
	}

	Filesystem::~Filesystem(){
		delete m_root;
	}
}