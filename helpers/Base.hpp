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

	Base() = default;

	Base( std::string const& testName )
		: _name(testName) {
		for (std::size_t i=0; i < N; ++i) {
			arr[i]=i;
		}
	}

	Base(
		std::string const& testName
		,T max
		,T min ) {
		helper::GenerateNumbers< T, typename Base< T, N >::MyArr >::generate( arr, min, max );
    }

	Base( std::string const& testName, MyArr const& newArr )
		: Base(testName) {
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

	std::string name() const {
		return _name;
	}

protected:
	constexpr std::size_t size() const {
		return N;
	}

	static MyArr arr;
	std::string _name;
};

}
}

#endif // __ALGORITHMS_BASE_HPP__
