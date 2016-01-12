#ifndef __ALGORITHMS_BASE_HPP__
#define __ALGORITHMS_BASE_HPP__

#include "GenerateNumbers.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <functional>

namespace subox {
namespace algorithms {

template< typename T >
struct Base {
	Base() = default;

	virtual ~Base(){}

	virtual void generateNumbers( std::size_t const capacity = 0, bool const reverse = false ) {
		if (false == reverse) {
			for (std::size_t i = 0; i < capacity; ++i) {
				push(i);
			}
		} else {
			for (std::size_t i = capacity; i > 0; --i) {
				push(i - 1);
			}
		}
	}

	virtual void generateNumbers( std::size_t const capacity, T max, T min ) {
		helper::GenerateNumbers< T >::generate(
										capacity
										,min
										,max
										,std::bind(
												&Base::push
												,this
												,std::placeholders::_1 ));
	}

	virtual void print() const = 0;

	virtual bool calc(T const=1) {
		std::cerr << "Error: Not a sort type" << std::endl;
		return false;
	}

	virtual constexpr std::string name() const {
		return "Unknown";
	}

protected:
	virtual void push( T const& item ) = 0;
};

}
}

#endif // __ALGORITHMS_BASE_HPP__
