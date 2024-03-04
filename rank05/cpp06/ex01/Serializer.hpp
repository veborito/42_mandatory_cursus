#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.h"
#include <cstdint>

class Serializer {
   public:
    virtual Serializer &operator=(Serializer const &rhs) = 0;

    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t ptr);

   private : Serializer();
    Serializer(Serializer const &instance);
    virtual ~Serializer();
};

#endif
