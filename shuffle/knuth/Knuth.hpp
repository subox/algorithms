#ifndef __ALGORITHMS_SHUFFLE_KNUTH_HPP__
#define __ALGORITHMS_SHUFFLE_KNUTH_HPP__

#include "helpers/Base.hpp"
#include <algorithm>
#include <random>

namespace subox {
namespace algorithms {
namespace shuffle {

template< typename T >
struct Knuth : public Base<T> {
	Knuth( std::size_t capacity = 0, bool const reverse = false )
		: Base<T>(capacity, reverse){}

	Knuth( std::size_t capacity, T max, T min )
		: Base<T>(capacity, max, min) {
	}

	Knuth( typename Base<T>::MyArr const& newArr )
		: Base<T>(newArr ) {
	}	

	bool calc(T const=0) override {
		std::random_device rd;
		std::mt19937 mt(rd());

		for (std::size_t i = 0; i < size(); ++i) {
			std::uniform_int_distribution< T > dist(0, i);
			std::swap( arr[i], arr[dist(mt)] );
		}

		return true;
	}

private:
	constexpr std::string name() const override {
		return "Knuth Shuffle";
	}

	using Base<T>::arr;
	using Base<T>::size;
};


}
}
}

#endif // __ALGORITHMS_SHUFFLE_KNUTH_HPP____
