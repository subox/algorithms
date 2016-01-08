#ifndef __ALGORITHMS_SORT_EXECUTOR_HPP__
#define __ALGORITHMS_SORT_EXECUTOR_HPP__

#include "Executor.hpp"
#include "sort/insertion/Insertion.hpp"
#include "sort/selection/Selection.hpp"
#include "sort/shell/Shell.hpp"
#include "sort/merge/RecursiveMerge.hpp"
#include "sort/merge/BottomUpMerge.hpp"
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
				item.reset( this->template selectSortOrder<sorting::Selection< T >>() );
				break;
			case OperType::InsertionSort:
				item.reset( this->template selectSortOrder<sorting::Insertion< T >>() );
				break;
			case OperType::ShellSort:
				item.reset( this->template selectSortOrder<sorting::Shell< T >>() );
				break;
			case OperType::RecursiveMergeSort:
				item.reset( this->template selectSortOrder<sorting::RecursiveMerge< T >>() );
				break;
			case OperType::BottomUpMergeSort:
				item.reset( this->template selectSortOrder<sorting::BottomUpMerge< T >>() );
				break;
			default:
				return false;
		}

		this->tests.push_front( std::move(item) );
		return true;
	}

private:
	using typename Executor<T,S>::BaseTempl;
};

}
}

#endif // __ALGORITHMS_SORT_EXECUTOR_HPP__
