#ifndef __ALGORITHMS_SHUFFLE_KNUTH_HPP__
#define __ALGORITHMS_SHUFFLE_KNUTH_HPP__

#include "helpers/Base.hpp"
#include <algorithm>
#include <random>

namespace subox {
namespace algorithms {
namespace shuffle {

template< typename T, std::size_t N >
struct Knuth : public Base<T,N> {
	Knuth( bool const reverse = false )
		: Base<T,N>(reverse){}

	Knuth( T max, T min )
		: Base<T,N>(max, min) {
	}

	Knuth( typename Base<T,N>::MyArr const& newArr )
		: Base<T,N>(newArr ) {
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

	using Base<T,N>::arr;
	using Base<T,N>::size;
};


}
}
}

#endif // __ALGORITHMS_SHUFFLE_KNUTH_HPP____
