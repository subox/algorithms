#ifndef __ALGORITHMS_SORT_EXECUTOR_HPP__
#define __ALGORITHMS_SORT_EXECUTOR_HPP__

#include "Executor.hpp"
#include "../sort/insertion/Insertion.hpp"
#include "../sort/selection/Selection.hpp"
#include "../sort/shell/Shell.hpp"
#include "Config.hpp"

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
				item.reset( selectSortOrder<sorting::Selection< T, Config<T,S>::SearchArraySize >>() );
				break;
			case OperType::InsertionSort:
				item.reset( selectSortOrder<sorting::Insertion< T, Config<T,S>::SearchArraySize >>() );
				break;
			case OperType::ShellSort:
				item.reset( selectSortOrder<sorting::Shell< T, Config<T,S>::SearchArraySize >>() );
				break;
			default:
				return false;
		}

		tests.push_front( std::move(item) );
		return true;
	}

private:
	using typename Executor<T,S>::BaseTempl;
	using Executor<T,S>::tests;
	using Executor<T,S>::config;

	template< typename SORT >
	BaseTempl* selectSortOrder() {
		BaseTempl* item = nullptr;
		switch ( config.arrasSort ) {
			case ArraySort::Random:
				item = new SORT(1000,0);
				break;
			case ArraySort::Ascend:
				item = new SORT();
				break;
			case ArraySort::Descend:
				item = new SORT(true);
				break;
			default:
				item = new SORT(1000,0);
				break;
		}

		return item;
	}
};

}
}

#endif // __ALGORITHMS_SORT_EXECUTOR_HPP__
