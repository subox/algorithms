#ifndef __ALGORITHMS_SORTING_INSERTION_HPP__
#define __ALGORITHMS_SORTING_INSERTION_HPP__ 

#include "helpers/ArrayBase.hpp"
#include "helpers/helpers.hpp"
#include <algorithm>
#include <cassert>

namespace subox {
namespace algorithms {
namespace sorting {

template< typename T >
struct Insertion : public ArrayBase<T> {
	Insertion() = default;

	bool calc(T const=0) override {
		sort( arr, 0, arr.size() - 1 );

		assert( true == std::is_sorted(this->arr.begin(), this->arr.end()) );

		return true;
	}

	static void sort(
			typename ArrayBase<T>::MyArr& _arr
			,std::size_t const low
			,std::size_t const high ) {
		using subox::algorithms::helpers::swapValues;
		for (std::size_t i = low; i <= high; ++i ) {
			for (std::size_t j = i; j > 0; --j) {
				if (_arr[j] < _arr[j - 1]) {
					swapValues( _arr[j], _arr[j - 1] );
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


	using ArrayBase<T>::arr;
	using ArrayBase<T>::size;
};


}
}
}

#endif // __ALGORITHMS_SORTING_INSERTION_HPP__
