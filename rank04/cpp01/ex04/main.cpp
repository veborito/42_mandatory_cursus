#include <iostream>
#include <fstream>
#include <string>

void fileError(std::string filename);
void copyFile(std::ifstream *ifs, std::ofstream *ofs);
void replace(std::ifstream *ifs, std::ofstream *ofs, std::string strToErase,
             std::string strToInsert);

void fileError(std::string filename) {
    std::cerr << filename << " cannot be open !\n";
    exit(1);
}

void copyFile(std::ifstream *ifs, std::ofstream *ofs) {
    std::string line;
    std::getline(*ifs, line, '\0');
    *ofs << line << '\n';
    exit(0);
}

void replace(std::ifstream *ifs, std::ofstream *ofs, std::string strToErase,
             std::string strToInsert) {
    if (strToErase == "")
        copyFile(ifs, ofs);
    std::string line;
    size_t pos;
    std::getline(*ifs, line, '\0');
    pos = line.find(strToErase);
    while (pos != std::string::npos) {
        line.erase(pos, strToErase.length());
        line.insert(pos, strToInsert);
        pos = line.find(strToErase);
    }
    *ofs << line;
}

int main(int ac, char *av[]) {
    if (ac != 4) {
        std::cerr << "Usage <filename> <s1> <s2>\n";
        return 1;
    }
    std::string filename = av[1];
    std::ifstream ifs(filename);
    if (!ifs.is_open())
        fileError(filename);
    std::ofstream ofs(filename + ".replace");
    if (!ofs.is_open())
        fileError(filename + ".replace");
    replace(&ifs, &ofs, static_cast<std::string>(av[2]),
            static_cast<std::string>(av[3]));
    ifs.close();
    ofs.close();
    return 0;
}
