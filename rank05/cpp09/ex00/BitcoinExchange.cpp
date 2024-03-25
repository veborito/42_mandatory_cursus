#include "BitcoinExchange.hpp"

#include <cctype>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// ---------- Constructors, operators overload -------------------------
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(std::string data) {
    std::ifstream ifs(data);
    if (!ifs.is_open()) {
        std::cerr
            << "data file cannot be open, please provide a data file in csv "
               "format.\n";
        exit(1);
    }
    std::string line;
    std::string date;
    int pos;
    float rate;
    while (ifs.good()) {
        std::getline(ifs, line);
        if (std::isdigit(line[0])) {
            pos = line.find(",");
            date = line.substr(0, pos);
            rate = std::strtof(
                line.substr(pos + 1, line.size() - pos + 1).c_str(), NULL);
            m_dataBase[date] = rate;
        }
    }
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &instance) {
    *this = instance;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
    (void)rhs;
    return *this;
}
//---------------------- Class functions ----------------------------------

std::map<std::string, float> const &BitcoinExchange::getDatabase() const {
    return this->m_dataBase;
}

bool BitcoinExchange::m_checkInput(std::string const &line) const {
    int pos = line.find("|");
    if (pos == 0) return false;
    if (std::isdigit(line[0])) {
        int i = -1;
        int c = 0;
        while (line.substr(0, 10)[++i])
            if (line[i] == '-') c++;
        if (c != 2) return false;
        std::stringstream sy;
        std::stringstream sm;
        std::stringstream sd;
        int y;
        int m;
        int d;
        try {
            sy << line.substr(0, 4);
            sy >> y;
            sm << line.substr(5, 2);
            sm >> m;
            sd << line.substr(8, 2);
            sd >> d;
        } catch (std::exception &e) {
            return false;
        }
        if (d < 1 or m < 1 or d > 31 or m > 12 or y < 2009 or y > 2022 or
            (y == 2009 and m == 1 and d < 2)) {
            return false;
        }
    }
    return true;
}

void BitcoinExchange::m_processInput(std::string const &fullDate,
                                     float const &value) {
    std::map<std::string, float>::iterator it;
    float res = 0;
    if (value < 0)
        std::cerr << "Error: not a positive number.\n";
    else if (value > 1000)
        std::cerr << "Error: too large number.\n";
    else {
        it = this->m_dataBase.find(fullDate);
        if (it != this->m_dataBase.end()) {
            res = it->second * value;
            std::cout << fullDate << " => " << value << " = " << res << '\n';
        } else {
            this->m_dataBase.insert(std::pair<std::string, float>(fullDate, 0));
            it = this->m_dataBase.find(fullDate);
            it--;
            res = it->second * value;
            it++;
            this->m_dataBase.erase(it);
            std::cout << fullDate << " => " << value << " = " << res << '\n';
        }
    }
}

void BitcoinExchange::exchange(std::string const &input) {
    std::ifstream ifs(input);
    if (!ifs.is_open()) {
        std::cerr << "Error: could not open file.\n";
        exit(1);
    }
    std::string line;
    std::string fullDate;
    float value = -1;
    while (ifs.good()) {
        std::getline(ifs, line);
        if (line != "\n" and isdigit(line[0])) {
            if (this->m_checkInput(line) == false) {
                std::cerr << "Error: bad input => " << line << '\n';
                continue;
            }
            value = strtof(line.substr(13, line.size() - 13).c_str(), NULL);
            if (value or (value == 0 and line[13] == '0')) {
                this->m_processInput(line.substr(0, 10), value);
            } else
                std::cerr << "Error: bad input => " << line << '\n';
        }
    }
}

// ---------------------- Functions out of class scope --------------------

std::ostream &operator<<(std::ostream &o, BitcoinExchange const &instance) {
    std::map<std::string, float>::const_iterator it =
        instance.getDatabase().begin();
    o << "Data base :\n";
    while (it != instance.getDatabase().end()) {
        std::cout << it->first << " => " << it->second << '\n';
        it++;
    }
    return o;
}
