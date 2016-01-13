#ifndef __ALGORITHMS_SORTING_SELECTION_HPP__
#define __ALGORITHMS_SORTING_SELECTION_HPP__

#include "helpers/ArrayBase.hpp"
#include "helpers/helpers.hpp"
#include <algorithm>
#include <cassert>

namespace subox {
namespace algorithms {
namespace sorting {

template< typename T >
struct Selection : public ArrayBase<T> {
	Selection() = default;

	bool calc(T const=0) override {
		std::size_t min = 0;
		for (std::size_t i = 0; i < this->size(); ++i) {
			min = i;
			for (std::size_t j = i + 1; j < this->size(); ++j) {
				if (this->arr[min] > this->arr[ j ]) {
					min = j;
				}
			}
			swapIfDifferent( i, min );
		}

		assert( true == std::is_sorted(this->arr.begin(), this->arr.end()) );

		return true;
	}

private:
	void swapIfDifferent( std::size_t const i, std::size_t const min ) {
		using subox::algorithms::helpers::swapValues;
		if (min != i) {
			swapValues( this->arr[i], this->arr[min] );
		}
	}

	constexpr std::string name() const override {
		return "Selection Sort";
	}
};


}
}
}

#endif // __ALGORITHMS_SORTING_SELECTION_HPP__
