#ifndef __ALGORITHMS_SORTING_SELECTION_HPP__
#define __ALGORITHMS_SORTING_SELECTION_HPP__

#include "../../helpers/GenerateNumbers.hpp"
#include "../../helpers/Base.hpp"
#include <algorithm>

namespace subox {
namespace algorithms {
namespace sorting {

template< typename T, std::size_t N >
struct Selection : public Base<T,N> {
	Selection() : Base<T,N>("Selection Sort") {
		for (std::size_t i=0; i < N; ++i) {
			arr[i]=i;
		}
	}

	Selection( T max, T min = 1 ) : Base<T,N>("Selection Sort") {
		helper::GenerateNumbers< T, typename Base< T, N >::MyArr >::generate( arr, min, max );
	}

	Selection( typename Base<T,N>::MyArr const& newArr )
		: Base<T,N>( "Selection Sort", newArr ) {
	}


	bool calc(T const=0) override {
        std::size_t min = 0;
        for (std::size_t i = 0; i < size(); ++i) {
            min = i;
            for (std::size_t j = i + 1; j < size(); ++j) {
                if (arr[min] > arr[ j ]) {
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
               std::swap( arr[i], arr[min] );
        }
    }

	using Base<T,N>::arr;
	using Base<T,N>::size;
};


}
}
}

#endif // __ALGORITHMS_SORTING_SELECTION_HPP__
