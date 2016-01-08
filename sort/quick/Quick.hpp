#ifndef __ALGORITHMS_SORTING_QUICK_HPP__
#define __ALGORITHMS_SORTING_QUICK_HPP__ 

#include "helpers/Base.hpp"
#include "helpers/helpers.hpp"
#include <algorithm>
#include <cassert>

namespace subox {
namespace algorithms {
namespace sorting {

template< typename T >
struct Quick : public Base<T> {
	Quick( std::size_t capacity, bool const reverse = false )
		: Base<T>(capacity, reverse){}

	Quick( std::size_t capacity, T max, T min )
		: Base<T>(capacity, max, min) {
	}

	Quick( typename Base<T>::MyArr const& newArr )
		: Base<T>(newArr ) {
	}	

	bool calc(T const=0) override {
		std::random_shuffle(this->arr.begin(), this->arr.end());
		sort( 0, arr.size() - 1 );

		assert( true == std::is_sorted(this->arr.begin(), this->arr.end()) );

		return true;
	}

private:
	std::size_t partition( std::size_t const low, std::size_t const high ) {
		using subox::algorithms::helpers::swapValues;
		int i = low
			,j = high + 1;

		while (true) {
			while (arr[++i] < arr[low]) {
				if (high == i) break;
			}

			while (arr[low] < arr[--j]) {
				if (low == j) break;
			}

			if (j <= i) {
				break;
			} else {
				swapValues(arr[i], arr[j]);
			}
		}

		swapValues(arr[low], arr[j]);

		return j;
	}

	void sort( std::size_t const low, std::size_t const high ) {
		if (high > low) {
			const std::size_t k = partition( low, high );
			sort( low, k == 0 ? k : k - 1 );
			sort( k + 1, high );
		}
	}

	constexpr std::string name() const override {
		return "Quick Sort";
	}


	using Base<T>::arr;
	using Base<T>::size;
};


}
}
}

#endif // __ALGORITHMS_SORTING_QUICK_HPP__
