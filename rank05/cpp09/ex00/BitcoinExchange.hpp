#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange {
   public:
    BitcoinExchange();
    BitcoinExchange(std::string data);
    BitcoinExchange(BitcoinExchange const &instance);
    ~BitcoinExchange();

    BitcoinExchange &operator=(BitcoinExchange const &rhs);

    std::map<std::string, float> const  &getDatabase() const;
    void exchange(std::string const &input);
   private:
    std::map<std::string, float> m_dataBase;

    bool m_checkInput(std::string const &line) const;
    void m_processInput(std::string const &fullDate, float const &value);
};

bool isNumber(std::string const &s);

std::ostream &operator<<(std::ostream &o, BitcoinExchange const &instance);

#endif 
