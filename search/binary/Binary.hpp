#ifndef __ALGORITHMS_SEARCH_BINARY_HPP__
#define __ALGORITHMS_SEARCH_BINARY_HPP__

#include "../../helpers/Base.hpp"

namespace subox {
namespace algorithms {
namespace search {

template< typename T, std::size_t N >
struct Binary : public Base<T,N> {
	Binary() = default;

	Binary( T max, T min = 0 )
		: Base<T,N>(max, min) {
	}

	Binary( typename Base<T,N>::MyArr const& newArr )
		: Base<T,N>(newArr ) {
	}

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

	using Base<T,N>::arr;
	using Base<T,N>::size;
};


}
}
}

#endif // __ALGORITHMS_SEARCH_BINARY_HPP__
