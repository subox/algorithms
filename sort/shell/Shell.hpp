#ifndef __ALGORITHMS_SORTING_SHELL_HPP__
#define __ALGORITHMS_SORTING_SHELL_HPP__ 

#include "helpers/Base.hpp"
#include <algorithm>

namespace subox {
namespace algorithms {
namespace sorting {

template< typename T >
struct Shell : public Base<T> {
	Shell( std::size_t capacity = 0, bool const reverse = false )
		: Base<T>(capacity, reverse){}

	Shell( std::size_t capacity, T max, T min )
		: Base<T>(capacity, max, min) {
	}

	Shell( typename Base<T>::MyArr const& newArr )
		: Base<T>(newArr ) {
	}	

	bool calc(T const=0) override {
		std::size_t h = getHmax();

		bool foundPlace = false;
		while (h >= 1) {
			for (std::size_t i = h; i < size(); ++i ) {
				for (std::size_t j = i; j >= h && (false == foundPlace); j -= h) {
					if (arr[j] < arr[j - h]) {
						std::swap( arr[j], arr[j - h] );
					} else {
						foundPlace = true;
					}
				}
				foundPlace = false;
			}
			h /= 3;
		}

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

	using Base<T>::arr;
	using Base<T>::size;
};


}
}
}

#endif // __ALGORITHMS_SORTING_SHELL_HPP__
