#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
   public:
    Array<T>();
    Array<T>(unsigned int n);
    Array<T>(Array<T> const &instance);
    ~Array();

    Array<T> const &operator=(Array<T> const & rhs);

    unsigned int size();
   private:
    T *arr;
    unsigned int arr_size;

};
#endif
