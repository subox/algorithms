#ifndef __ALGORITHMS_SORTING_INSERTION_HPP__
#define __ALGORITHMS_SORTING_INSERTION_HPP__ 

#include "../../helpers/Base.hpp"
#include <algorithm>

namespace subox {
namespace algorithms {
namespace sorting {

template< typename T, std::size_t N >
struct Insertion : public Base<T,N> {
	Insertion() = default; 

	Insertion( T max, T min = 0 )
		: Base<T,N>(max, min) {
	}

	Insertion( typename Base<T,N>::MyArr const& newArr )
		: Base<T,N>(newArr ) {
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
	void swapIfDifferent( std::size_t const i, std::size_t const min ) {
		if (min != i) {
			std::swap( arr[i], arr[min] );
		}
	}

	constexpr std::string name() const override {
		return "Insertion Sort";
	}

	using Base<T,N>::arr;
	using Base<T,N>::size;
	using Base<T,N>::print;
};


}
}
}

#endif // __ALGORITHMS_SORTING_INSERTION_HPP__
