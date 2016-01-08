#ifndef __ALGORITHMS_SORTING_INSERTION_HPP__
#define __ALGORITHMS_SORTING_INSERTION_HPP__ 

#include "helpers/Base.hpp"
#include <algorithm>
#include <cassert>

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
		sort( arr, 0, arr.size() - 1 );

		assert( true == std::is_sorted(this->arr.begin(), this->arr.end()) );

		return true;
	}

	static void sort(
			typename Base<T>::MyArr& _arr
			,std::size_t const low
			,std::size_t const high ) {
		for (std::size_t i = low; i <= high; ++i ) {
			for (std::size_t j = i; j > 0; --j) {
				if (_arr[j] < _arr[j - 1]) {
					std::swap( _arr[j], _arr[j - 1] );
				} else {
					break;
				}
			}
		}

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
