#include <cstdint>
#include <iostream>

#include "Data.h"
#include "Serializer.hpp"

int main() {
    Data data = {12, 10};
    Data *data_ptr = &data;

    std::cout << "Data before serialization content:" << data.x << ' ' << data.y
              << '\n';
    std::cout << "Data adress:" << data_ptr << '\n';
    uintptr_t ptr = Serializer::serialize(data_ptr);
    std::cout << "uintptr_t adress:" << ptr << '\n';
    Data *other_data_ptr = Serializer::deserialize(ptr);

    if (data_ptr == other_data_ptr) {
        std::cout << "Other data before serialization content:"
                  << other_data_ptr->x << ' ' << other_data_ptr->y << '\n';
        std::cout << "Other data adress:" << other_data_ptr << '\n';
    }

    return 0;
}
