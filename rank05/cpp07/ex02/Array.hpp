#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
   public:
    Array();
    Array(unsigned int n);
    Array(Array<T> const &instance);
    ~Array();

    Array &operator=(Array<T> const & rhs);
    T &operator[](int idx);
	T const &operator[](int idx) const;

    unsigned int size() const;

	class IndexOutOfRangeException : public std::exception {
		public:
		 virtual char const *what() const throw();
	};
	class NullArrayException : public std::exception {
		public:
		 virtual char const *what() const throw();
	};
   private:
    T *arr;
    unsigned int arr_size;
};

#include "Array.tpp"

#endif
