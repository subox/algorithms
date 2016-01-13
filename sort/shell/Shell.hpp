#ifndef __ALGORITHMS_SORTING_SHELL_HPP__
#define __ALGORITHMS_SORTING_SHELL_HPP__ 

#include "helpers/ArrayBase.hpp"
#include "helpers/helpers.hpp"
#include <algorithm>
#include <cassert>

namespace subox {
namespace algorithms {
namespace sorting {

template< typename T >
struct Shell : public ArrayBase<T> {
	Shell() = default;

	bool calc(T const=0) override {
		using subox::algorithms::helpers::swapValues;
		std::size_t h = getHmax();

		bool foundPlace = false;
		while (h >= 1) {
			for (std::size_t i = h; i < size(); ++i ) {
				for (std::size_t j = i; j >= h && (false == foundPlace); j -= h) {
					if (arr[j] < arr[j - h]) {
						swapValues( arr[j], arr[j - h] );
					} else {
						foundPlace = true;
					}
				}
				foundPlace = false;
			}
			h /= 3;
		}

		assert( true == std::is_sorted(this->arr.begin(), this->arr.end()) );

		return true;
	}

private:
	// TODO: Change it to metafunction
	std::size_t getHmax() const {
		std::size_t h = 1;
		while (h < size() / 3) {
			h = 3 * h + 1;
		}
		return h;
	}

	constexpr std::string name() const override {
		return "Shell Sort";
	}

	using ArrayBase<T>::arr;
	using ArrayBase<T>::size;
};


}
}
}

#endif // __ALGORITHMS_SORTING_SHELL_HPP__
