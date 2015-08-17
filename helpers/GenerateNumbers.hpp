#ifndef __ALGORITHMS_HELPER_RANDOM_HPP__
#define __ALGORITHMS_HELPER_RANDOM_HPP__

#include <random>

namespace subox {
namespace algorithms {
namespace helper {

template< typename T, typename ARR >
struct GenerateNumbers {
	static T generate( ARR& arr, T const min, T const max ) {
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution< T > dist(min, max);

		for (T& i : arr) {
			i = dist(mt);
		}

	}
};

}
}
}

#endif // __ALGORITHMS_HELPER_RANDOM_HPP__
