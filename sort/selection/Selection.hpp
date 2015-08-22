#ifndef __ALGORITHMS_SORTING_SELECTION_HPP__
#define __ALGORITHMS_SORTING_SELECTION_HPP__

#include "helpers/Base.hpp"
#include <algorithm>

namespace subox {
namespace algorithms {
namespace sorting {

template< typename T, std::size_t N >
struct Selection : public Base<T,N> {
	Selection( bool const reverse = false )
		: Base<T,N>(reverse){}

	Selection( T max, T min )
		: Base<T,N>(max, min) {
	}

	Selection( typename Base<T,N>::MyArr const& newArr )
		: Base<T,N>( newArr ) {
	}	

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

		return true;
	}

private:
	void swapIfDifferent( std::size_t const i, std::size_t const min ) {
		if (min != i) {
			std::swap( this->arr[i], this->arr[min] );
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
