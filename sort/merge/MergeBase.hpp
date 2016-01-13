#ifndef __ALGORITHMS_SORTING_MERGE_BASE_HPP__
#define __ALGORITHMS_SORTING_MERGE_BASE_HPP__

#include "helpers/ArrayBase.hpp"
#include "sort/insertion/Insertion.hpp"
#include <algorithm>
#include <cassert>

namespace subox {
namespace algorithms {
namespace sorting {

template< typename T >
struct MergeBase : public ArrayBase<T> {
	MergeBase() = default;

	bool calc(T const=0) override {
		auxiliaryArr = this->arr;	

		bool result = startSorting();

		assert( true == std::is_sorted(this->arr.begin(), this->arr.end()) );

		return result;
	}

protected:
	virtual bool startSorting() = 0;

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

	virtual constexpr std::string name() const = 0;

	typename ArrayBase<T>::MyArr auxiliaryArr;
};


}
}
}

#endif // __ALGORITHMS_SORTING_MERGE_BASE_HPP__
