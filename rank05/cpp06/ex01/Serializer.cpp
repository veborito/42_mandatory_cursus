#include "Serializer.hpp"
#include "Data.h"

#include <cstdint>

Serializer::Serializer() {}
Serializer::Serializer(Serializer const &instance) { *this = instance; }
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t ptr) {
    return reinterpret_cast<Data*>(ptr);

}

Serializer &Serializer::operator=(Serializer const &rhs) {
    (void)rhs;
    return *this;
}
