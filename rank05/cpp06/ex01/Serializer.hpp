#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

class Serializer {
   public:
    Serializer();
    Serializer(Serializer const &instance);
    virtual ~Serializer();

    virtual Serializer &operator=(Serializer const &rhs) = 0;
};

#endif
