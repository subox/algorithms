#ifndef __ALGORITHMS_BASE_HPP__
#define __ALGORITHMS_BASE_HPP__

#include "GenerateNumbers.hpp"
#include <vector>
#include <iostream>
#include <string>

namespace subox {
namespace algorithms {

template< typename T >
struct Base {
	typedef std::vector< T > MyArr;

	Base( std::size_t const capacity = 0, bool const reverse = false ) {
		arr.reserve( capacity );
		if (false == reverse) {
			for (std::size_t i = 0; i < capacity; ++i) {
				arr.emplace_back(i);
			}
		} else {
			for (std::size_t i = capacity; i > 0; --i) {
				arr.emplace_back(i - 1);
			}
		}
	}

	Base( std::size_t const capacity, T max, T min ) {
		arr.reserve( capacity );
		helper::GenerateNumbers< T, typename Base< T >::MyArr >::generate( arr, capacity, min, max );
	}

	Base( MyArr const& newArr ) {
		 arr = newArr;
	}

	virtual ~Base(){}

	void print() const {
		for (T i : arr) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	virtual bool calc(T const=1) {
		std::cerr << "Error: Not a sort type" << std::endl;
		return false;
	}

	virtual constexpr std::string name() const {
		return "Unknown";
	}

protected:
	constexpr std::size_t size() const {
		return arr.size();
	}

	MyArr arr;
};

}
}

#endif // __ALGORITHMS_BASE_HPP__
