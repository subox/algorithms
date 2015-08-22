#ifndef __ALGORITHMS_EXECUTOR_HPP
#define __ALGORITHMS_EXECUTOR_HPP

#include "Config.hpp"
#include "Base.hpp"
#include "sort/selection/Selection.hpp"
#include "sort/insertion/Insertion.hpp"
#include "sort/shell/Shell.hpp"
#include "search/binary/Binary.hpp"
#include "shuffle/knuth/Knuth.hpp"
#include <forward_list>
#include <memory>
#include <chrono>

namespace subox {
namespace algorithms {

enum class OperType {
	BinarySearch
	,SelectionSort
	,InsertionSort
	,ShellSort
	,KnuthShuffle
};

template< typename T, std::size_t S >
struct Executor {
	Executor( Config<T,S> const& _config )
		: config(_config) {}

	virtual ~Executor(){}

	virtual bool push( OperType const operType ) {
		std::unique_ptr<BaseTempl> item;
		switch( operType ) {
			case OperType::BinarySearch:
				item.reset( new search::Binary< T, Config<T,S>::SearchArraySize > );
				break;
			case OperType::SelectionSort:
				item.reset( this->template selectSortOrder<sorting::Selection< T, Config<T,S>::SearchArraySize >>() );
				break;
			case OperType::InsertionSort:
				item.reset( this->template selectSortOrder<sorting::Insertion< T, Config<T,S>::SearchArraySize >>() );
				break;
			case OperType::ShellSort:
				item.reset( this->template selectSortOrder<sorting::Shell< T, Config<T,S>::SearchArraySize >>() );
				break;
			case OperType::KnuthShuffle:
				item.reset( this->template selectSortOrder<shuffle::Knuth< T, Config<T,S>::SearchArraySize >>() );
				break;
			default:
				return false;
		}

		tests.push_front( std::move(item) );
		return true;
	}

	void execute() {
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;
		for (std::unique_ptr<BaseTempl>& test : tests) {
			printArray( Print::Before, config.shouldPrint, test );
			start = std::chrono::steady_clock::now();
			test->calc();
			end = std::chrono::steady_clock::now();
			printArray( Print::After, config.shouldPrint, test );
			printCalcLast( start, end, test->name() );
		}
	}

protected:
	typedef Base<T, Config<T,S>::SearchArraySize> BaseTempl;
	Config<T,S> config;
	std::forward_list<std::unique_ptr<BaseTempl>> tests;

	template< typename SORT >
	BaseTempl* selectSortOrder() {
		BaseTempl* item = nullptr;
		switch ( config.arraySort ) {
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

private:
	void printCalcLast(
			std::chrono::steady_clock::time_point const& start
			,std::chrono::steady_clock::time_point const& end
			,std::string const& testName ) const {
		std::cout << testName << " took "
				<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
				<< "us.\n";
	}

	void printArray(
			Print p,
			Print const isDisabled
			,std::unique_ptr<BaseTempl>& item ) {
		if (isDisabled == p
			||isDisabled == Print::Both) {
			item->print(); 
		}
	}
};

}
}

#endif // __ALGORITHMS_EXECUTOR_HPP
