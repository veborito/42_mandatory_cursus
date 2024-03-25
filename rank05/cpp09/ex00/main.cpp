#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    } else if (argc > 2) {
        std::cerr << "Error: too many arguments.\n";
        return 1;
    }
    (void)argv;
    BitcoinExchange btcExchange("data.csv");
    btcExchange.exchange(argv[1]);
    return 0;
}
