#ifndef __ALGORITHMS_SEARCH_EXECUTOR_HPP__
#define __ALGORITHMS_SEARCH_EXECUTOR_HPP__

#include "Executor.hpp"

namespace subox {
namespace algorithms {

template< typename T, std::size_t S = Config<T>::SearchArraySize >
struct SearchExecutor : public Executor<T,S> {
	SearchExecutor( Config<T,S> const& _config )
		: Executor<T,S>(_config) {}

	bool push( OperType const operType ) override {
		std::unique_ptr<BaseTempl> item;
		switch( operType ) {
			case OperType::BinarySearch:
				item.reset( new search::Binary< T >(Config<T,S>::SearchArraySize) );
				break;
			default:
				return false;
		}

		this->tests.push_front( std::move(item) );
		return true;
	}

	using typename Executor<T,S>::BaseTempl;
};

}
}

#endif // __ALGORITHMS_SEARCH_EXECUTOR_HPP__
