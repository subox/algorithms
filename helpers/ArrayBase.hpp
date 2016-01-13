#ifndef __ALGORITHMS_ARRAYBASE_HPP__
#define __ALGORITHMS_ARRAYBASE_HPP__

#include "helpers/Base.hpp"
#include <vector>
#include <string>
#include <functional>

namespace subox {
namespace algorithms {

template< typename T >
struct ArrayBase : public Base<T> {
	ArrayBase() = default;

	void generateNumbers( std::size_t const capacity = 0, bool const reverse = false ) override {
		arr.reserve( capacity );
		Base<T>::generateNumbers( capacity, reverse	);
	}

	void generateNumbers( std::size_t const capacity, T const max, T const min ) override {
		arr.reserve( capacity );
		Base<T>::generateNumbers( capacity, max, min );
	}

	virtual void assignNumbers( typename Base<T>::MyArr const& initNumbers ) {
		arr = initNumbers;
	}

	virtual ~ArrayBase(){}

	void print() const override {
		for (T i : arr) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

protected:
	void push( T const& item ) override {
		arr.emplace_back( item );
	}

	constexpr std::size_t size() const {
		return arr.size();
	}

	typename Base<T>::MyArr arr;
};

}
}

#endif // __ALGORITHMS_ARRAYBASE_HPP__
