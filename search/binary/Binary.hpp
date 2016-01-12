#ifndef __ALGORITHMS_SEARCH_BINARY_HPP__
#define __ALGORITHMS_SEARCH_BINARY_HPP__

#include "helpers/ArrayBase.hpp"
#include <cassert>

namespace subox {
namespace algorithms {
namespace search {

template< typename T >
struct Binary : public ArrayBase<T> {
	Binary() = default;

	Binary( typename ArrayBase<T>::MyArr const& newArr )
		: ArrayBase<T>(newArr ) {
	}

	// TODO: protect when array is unsorted
	bool calc( T const key ) override {
		assert( true == std::is_sorted(this->arr.begin(), this->arr.end()) );

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

	using ArrayBase<T>::arr;
	using ArrayBase<T>::size;
};


}
}
}

#endif // __ALGORITHMS_SEARCH_BINARY_HPP__
