#ifndef __ALGORITHMS_HELPERS_HPP__
#define __ALGORITHMS_HELPERS_HPP__ 

namespace subox {
namespace algorithms {
namespace helpers {

template< typename T >
void swapValues( T& a, T& b ) {
	const T tmp = a;
	a = b;
	b = tmp;
}


}
}
}

#endif // __ALGORITHMS_HELPERS_HPP__
