#ifndef __ALGORITHMS_SORTING_MERGE_HPP__
#define __ALGORITHMS_SORTING_MERGE_HPP__

#include "helpers/Base.hpp"
#include "sort/insertion/Insertion.hpp"
#include "sort/merge/MergeBase.hpp"
#include <algorithm>
#include <cassert>

namespace subox {
namespace algorithms {
namespace sorting {

template< typename T >
struct RecursiveMerge : public MergeBase<T> {
	RecursiveMerge() = default;

	RecursiveMerge( typename ArrayBase<T>::MyArr const& newArr )
		: MergeBase<T>( newArr ) {
	}	

private:
	bool startSorting() override {
		std::size_t const low = 0
					,high = this->size() - 1;

		sort( low, high );

		return true;
	}

	void sort( std::size_t const _low, std::size_t const high ) {
		// TODO: analyze why swapping 2 vector items takes so much time
		if (high <= _low){// + Cutoff - 1) {
			//Insertion<T>::sort( this->arr, _low, high);
		} else {
			std::size_t const low = _low
					, middle = _low + ((high - _low) / 2) ;

			sort( low, middle );
			sort( middle + 1, high);
			this->merge( low, middle, high);
		}
	}

	constexpr std::string name() const override {
		return "RecursiveMerge Sort";
	}

	static constexpr unsigned short Cutoff = 7; // Up to 7 items insertion sort is most effective
};


}
}
}

#endif // __ALGORITHMS_SORTING_MERGE_HPP__
