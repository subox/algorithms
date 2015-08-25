#ifndef __ALGORITHMS_CONFIG_HPP__
#define __ALGORITHMS_CONFIG_HPP__

#include <vector>

namespace subox {
namespace algorithms {

enum class Print {
	Disable = 0
	,Before = 1
	,After = 2
	,Both
};

enum class ArraySort {
	Random
	,Ascend
	,Descend
};

template< typename T, std::size_t S = 200000000L >
struct Config {
	std::vector< T > searchNumbers;
	Print shouldPrint = Print::Disable;
	ArraySort arraySort = ArraySort::Random;
	T valuesMin = 0;
	T valuesMax = 1000;
	unsigned executions = 1;
	bool sameArrayValues = true;
	unsigned short maxThreads = 1;
	static constexpr std::size_t SearchArraySize = S;
};

}
}

#endif // __ALGORITHMS_CONFIG_HPP__
