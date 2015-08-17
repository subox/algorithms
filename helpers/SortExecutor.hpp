#ifndef __ALGORITHMS_SORT_EXECUTOR_HPP__
#define __ALGORITHMS_SORT_EXECUTOR_HPP__

#include "Executor.hpp"

namespace subox {
namespace algorithms {

template< typename T, std::size_t S = Config<T>::SearchArraySize >
struct SortExecutor : public Executor<T,S> {
	SortExecutor( Config<T,S> const& _config )
		: Executor<T,S>(_config) {}

	bool push( OperType const operType ) override {
		std::unique_ptr<BaseTempl> item;
		switch( operType ) {
			case OperType::SelectionSort:
				item.reset( new sorting::Selection< T, Config<T,S>::SearchArraySize >(1000) );
				break;
			default:
				return false;
		}

		tests.push_front( std::move(item) );
		return true;
	}

	using typename Executor<T,S>::BaseTempl;
	using Executor<T,S>::tests;
};

}
}

#endif // __ALGORITHMS_SORT_EXECUTOR_HPP__
