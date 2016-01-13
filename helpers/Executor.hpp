#ifndef __ALGORITHMS_EXECUTOR_HPP
#define __ALGORITHMS_EXECUTOR_HPP

#include "Config.hpp"
#include "Base.hpp"
#include "sort/selection/Selection.hpp"
#include "sort/insertion/Insertion.hpp"
#include "sort/shell/Shell.hpp"
#include "sort/merge/RecursiveMerge.hpp"
#include "sort/merge/BottomUpMerge.hpp"
#include "sort/quick/Quick.hpp"
#include "search/binary/Binary.hpp"
#include "shuffle/knuth/Knuth.hpp"
#include "tree/binary/Binary.hpp"
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
	,RecursiveMergeSort
	,BottomUpMergeSort
	,QuickSort
	,KnuthShuffle
	,BinaryTree
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
				item.reset( new search::Binary< T > );
				break;
			case OperType::SelectionSort:
				item.reset( new sorting::Selection< T > );
				break;
			case OperType::InsertionSort:
				item.reset( new sorting::Insertion< T > );
				break;
			case OperType::ShellSort:
				item.reset( new sorting::Shell< T > );
				break;
			case OperType::RecursiveMergeSort:
				item.reset( new sorting::RecursiveMerge< T > );
				break;
			case OperType::BottomUpMergeSort:
				item.reset( new sorting::BottomUpMerge< T > );
				break;
			case OperType::QuickSort:
				item.reset( new sorting::Quick< T > );
				break;
			case OperType::KnuthShuffle:
				item.reset( new shuffle::Knuth< T > );
				break;
			case OperType::BinaryTree:
				item.reset( new tree::Binary< T > );
				break;
			default:
				return false;
		}

		if (config.initNumbers.empty()) {
			item = selectSortOrder( std::move(item) );
		} else {
			item->assignNumbers( config.initNumbers );
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
	typedef Base<T> BaseTempl;
	Config<T,S> config;
	std::forward_list<std::unique_ptr<BaseTempl>> tests;

	template< typename OPER >
	std::unique_ptr<OPER> selectSortOrder( std::unique_ptr<OPER> item ) {
		switch ( config.arraySort ) {
			case ArraySort::Random:
				item->generateNumbers( Config<T,S>::SearchArraySize, config.valuesMax, config.valuesMin );
				break;
			case ArraySort::Ascend:
				item->generateNumbers( Config<T,S>::SearchArraySize );
				break;
			case ArraySort::Descend:
				item->generateNumbers( Config<T,S>::SearchArraySize, true );
				break;
			default:
				item->generateNumbers( Config<T,S>::SearchArraySize, config.valuesMax, config.valuesMin );
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
			std::cout << "print:" << std::endl;
			item->print(); 
		}
	}
};

}
}

#endif // __ALGORITHMS_EXECUTOR_HPP
