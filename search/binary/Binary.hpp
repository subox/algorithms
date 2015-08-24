#ifndef __ALGORITHMS_SEARCH_BINARY_HPP__
#define __ALGORITHMS_SEARCH_BINARY_HPP__

#include "helpers/Base.hpp"

namespace subox {
namespace algorithms {
namespace search {

template< typename T >
struct Binary : public Base<T> {
	Binary( std::size_t capacity = 0, bool const reverse = false )
		: Base<T>(capacity, reverse){}

	Binary( std::size_t capacity, T max, T min )
		: Base<T>(capacity, max, min) {
	}

	Binary( typename Base<T>::MyArr const& newArr )
		: Base<T>(newArr ) {
	}

	// TODO: protect when array is unsorted
	bool calc( T const key ) override {
		unsigned lo = 0,
				hi = size() - 1,
				mid = 0;
		bool keyFound = false;
		while (lo <= hi && false == keyFound ) {
			mid = lo + ((hi - lo) / 2);
			if (key < arr[mid]) {
				hi = mid - 1;
			} else if (key > arr[mid]) {
				lo = mid + 1;
			} else {
				keyFound = true;
			}
		}

		return keyFound;
	}

private:
	constexpr std::string name() const override {
		return "Binary Search";
	}

	using Base<T>::arr;
	using Base<T>::size;
};


}
}
}

#endif // __ALGORITHMS_SEARCH_BINARY_HPP__
