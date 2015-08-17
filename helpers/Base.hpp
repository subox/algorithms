#ifndef __ALGORITHMS_BASE_HPP__
#define __ALGORITHMS_BASE_HPP__

#include <array>
#include <iostream>
#include <string>

namespace subox {
namespace algorithms {

template< typename T, std::size_t N >
struct Base {
	typedef std::array< T, N > MyArr;

	Base() {
		for (std::size_t i=0; i < N; ++i) {
			arr[i]=i;
		}
	}

	Base( T max, T min ) {
		helper::GenerateNumbers< T, typename Base< T, N >::MyArr >::generate( arr, min, max );
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
		return N;
	}

	static MyArr arr;
};

}
}

#endif // __ALGORITHMS_BASE_HPP__
