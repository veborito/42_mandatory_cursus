#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(Serializer const &instance) { *this = instance; }
Serializer::~Serializer() {}

Serializer &Serializer::operator=(Serializer const &rhs) {
    (void)rhs;
    return *this;
}
