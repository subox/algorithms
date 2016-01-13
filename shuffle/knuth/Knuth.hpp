#ifndef __ALGORITHMS_SHUFFLE_KNUTH_HPP__
#define __ALGORITHMS_SHUFFLE_KNUTH_HPP__

#include "helpers/ArrayBase.hpp"
#include "helpers/helpers.hpp"
#include <algorithm>
#include <random>

namespace subox {
namespace algorithms {
namespace shuffle {

template< typename T >
struct Knuth : public ArrayBase<T> {
	Knuth() = default;

	bool calc(T const=0) override {
		using subox::algorithms::helpers::swapValues;
		std::random_device rd;
		std::mt19937 mt(rd());

		for (std::size_t i = 0; i < size(); ++i) {
			std::uniform_int_distribution< T > dist(0, i);
			swapValues( arr[i], arr[dist(mt)] );
		}

		return true;
	}

private:
	constexpr std::string name() const override {
		return "Knuth Shuffle";
	}

	using ArrayBase<T>::arr;
	using ArrayBase<T>::size;
};


}
}
}

#endif // __ALGORITHMS_SHUFFLE_KNUTH_HPP____
