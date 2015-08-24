#ifndef __ALGORITHMS_HELPER_RANDOM_HPP__
#define __ALGORITHMS_HELPER_RANDOM_HPP__

#include <random>
#include <iostream>

namespace subox {
namespace algorithms {
namespace helper {

template< typename T, typename ARR >
struct GenerateNumbers {
	static void generate( ARR& arr, std::size_t const capacity, T const min, T const max ) {
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution< T > dist(min, max);

		for (std::size_t i=0; i < capacity; ++i) {
			arr.push_back(dist(mt));
		}

	}
};

}
}
}

#endif // __ALGORITHMS_HELPER_RANDOM_HPP__
