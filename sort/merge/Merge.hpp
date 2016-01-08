#ifndef __ALGORITHMS_SORTING_MERGE_HPP__
#define __ALGORITHMS_SORTING_MERGE_HPP__

#include "helpers/Base.hpp"
#include "sort/insertion/Insertion.hpp"
#include <algorithm>
#include <cassert>

namespace subox {
namespace algorithms {
namespace sorting {

template< typename T >
struct Merge : public Base<T> {
	Merge( std::size_t capacity = 0, bool const reverse = false )
		: Base<T>(capacity, reverse){}

	Merge( std::size_t capacity, T max, T min )
		: Base<T>(capacity, max, min) {
	}

	Merge( typename Base<T>::MyArr const& newArr )
		: Base<T>( newArr ) {
	}	

	bool calc(T const=0) override {
		auxiliaryArr = this->arr;	
		std::size_t const low = 0
					,high = this->size() - 1;

		sort( low, high );

		assert( true == std::is_sorted(this->arr.begin(), this->arr.end()) );

		return true;
	}

private:
	void sort( std::size_t const _low, std::size_t const high ) {
		// TODO: analyze why swapping 2 vector items takes so much time
		if (high <= _low){// + Cutoff - 1) {
			//Insertion<T>::sort( this->arr, _low, high);
		} else {
			std::size_t const low = _low
					, middle = _low + ((high - _low) / 2) ;

			sort( low, middle );
			sort( middle + 1, high);
			merge( low, middle, high);
		}
	}

	void merge(
			std::size_t const low
			,std::size_t const middle
			,std::size_t const high ) {
		std::size_t i = low
					,j= low
					,k= middle + 1;

		for (; i <= high; ++i) {
			auxiliaryArr[i] = this->arr[i];
		}

		for (i = low; i <= high; ++i) {
			if (j > middle) {
				this->arr[i] = auxiliaryArr[k++];
			} else if (k > high) {
				this->arr[i] = auxiliaryArr[j++];
			} else if (auxiliaryArr[j] < auxiliaryArr[k]) {
				this->arr[i] = auxiliaryArr[j++];
			} else {
				this->arr[i] = auxiliaryArr[k++];
			}
		}
	}

	constexpr std::string name() const override {
		return "Merge Sort";
	}

	static constexpr unsigned short Cutoff = 7; // Up to 7 items insertion sort is most effective
	typename Base<T>::MyArr auxiliaryArr;
};


}
}
}

#endif // __ALGORITHMS_SORTING_MERGE_HPP__
