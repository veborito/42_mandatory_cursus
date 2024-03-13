#include "Array.hpp"

int main(void) {
    Array<int> *tab = new Array<int>(3);
    Array<int> tab2(*tab);

    delete tab;
    tab2.size();
    return 0;
}
