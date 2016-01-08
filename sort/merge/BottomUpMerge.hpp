#ifndef __ALGORITHMS_SORTING_BOTTOM_UP_MERGE_HPP__
#define __ALGORITHMS_SORTING_BOTTOM_UP_MERGE_HPP__

#include "helpers/Base.hpp"
#include "sort/insertion/Insertion.hpp"
#include "sort/merge/MergeBase.hpp"
#include <algorithm>
#include <cassert>

namespace subox {
namespace algorithms {
namespace sorting {

template< typename T >
struct BottomUpMerge : public MergeBase<T> {
	BottomUpMerge( std::size_t capacity = 0, bool const reverse = false )
		: MergeBase<T>(capacity, reverse){}

	BottomUpMerge( std::size_t capacity, T max, T min )
		: MergeBase<T>(capacity, max, min) {
	}

	BottomUpMerge( typename Base<T>::MyArr const& newArr )
		: MergeBase<T>( newArr ) {
	}	

private:
	bool startSorting() override {
		sort();

		return true;
	}

	void sort() {
		this->auxiliaryArr = this->arr;

		for (unsigned subArrSize = 1; subArrSize < this->arr.size(); subArrSize += subArrSize) {
			for (unsigned low = 0; low < (this->arr.size() - subArrSize); low += subArrSize + subArrSize) {
				this->merge(
					low
					, low + subArrSize - 1
					, std::min(
							static_cast<std::size_t>(low + subArrSize + subArrSize - 1)
							, this->arr.size() - 1));
			}
		}
	}

	constexpr std::string name() const override {
		return "BottomUpMerge Sort";
	}
};

}
}
}

#endif // __ALGORITHMS_SORTING_BOTTOM_UP_MERGE_HPP__
