// Lance Curio
// 104319223
// lcurio@myseneca.ca
// 2023-10-22
#include <iomanip>
#include <iostream>
#include <fstream>
#include "SpellChecker.h"

using namespace std;

namespace sdds {
    size_t SpellChecker::m_replace[6]{};
    SpellChecker::SpellChecker(const char* filename) {
        ifstream file(filename);
        if (file) {
            std::string line;
            for (size_t i = 0; i < 6; i++) {
                std::string line;
                if (std::getline(file, line)) {
                    size_t j = 0;
                    for (; j < line.length() && line[j] != ' '; j++) {
                        m_badWords[i] += line[j];
                    }
                    for (; j < line.length(); j++) {
                        if (line[j] != ' ') {
                            m_goodWords[i] += line[j];
                        }
                    }
                }
            }
        }
        else {
            throw "Bad file name!";
        }
    }

    void SpellChecker::operator()(std::string& text){
        for (size_t i = 0; i < 6; i++) {
            size_t pos = text.find(m_badWords[i]);
            if (pos != string::npos) {
                text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
                m_replace[i]++;
            }
            pos = text.find(m_badWords[i]);
            if (pos != string::npos) {
                --i;
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const{
        out << "Spellchecker Statistics" << endl;
        for (size_t i = 0; i < 6; i++) {
            out << setw(15) << right << m_badWords[i] << ": " << m_replace[i] << " replacements" << endl;
        }
    }



}