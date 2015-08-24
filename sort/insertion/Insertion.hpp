#ifndef __ALGORITHMS_SORTING_INSERTION_HPP__
#define __ALGORITHMS_SORTING_INSERTION_HPP__ 

#include "helpers/Base.hpp"
#include <algorithm>

namespace subox {
namespace algorithms {
namespace sorting {

template< typename T >
struct Insertion : public Base<T> {
	Insertion( std::size_t capacity, bool const reverse = false )
		: Base<T>(capacity, reverse){}

	Insertion( std::size_t capacity, T max, T min )
		: Base<T>(capacity, max, min) {
	}

	Insertion( typename Base<T>::MyArr const& newArr )
		: Base<T>(newArr ) {
	}	

	bool calc(T const=0) override {
		bool foundPlace = false;
		for (std::size_t i = 0; i < size(); ++i ) {
			for (std::size_t j = i; j > 0 && (false == foundPlace); --j) {
				if (arr[j] < arr[j - 1]) {
					std::swap( arr[j], arr[j - 1] );
				} else {
					foundPlace = true;
				}
			}
			foundPlace = false;
		}

		return true;
	}

private:
	constexpr std::string name() const override {
		return "Insertion Sort";
	}

	using Base<T>::arr;
	using Base<T>::size;
};


}
}
}

#endif // __ALGORITHMS_SORTING_INSERTION_HPP__
