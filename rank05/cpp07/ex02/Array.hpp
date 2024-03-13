#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
   public:
    Array();
    Array(unsigned int n);
    Array(Array<T> const &instance);
    ~Array();

    Array &operator=(Array<T> const & rhs);
    T &operator[](unsigned int idx);

    unsigned int size() const;
   private:
    T *arr;
    unsigned int arr_size;

};
#endif
