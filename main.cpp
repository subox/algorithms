#include "search/binary/Binary.hpp"
#include "sort/selection/Selection.hpp"
#include "helpers/Config.hpp"
#include "helpers/SearchExecutor.hpp"
#include "helpers/SortExecutor.hpp"
#include "helpers/Executor.hpp"
#include <iostream>
#include <chrono>

using namespace subox::algorithms;

int main() {

	Config<unsigned long> searchConfig;
	SearchExecutor<unsigned long> searchExec(searchConfig);
	searchExec.push( OperType::BinarySearch );
	searchExec.execute();
	{
	constexpr static std::size_t SortArrSize = 20000;
	Config<unsigned long, SortArrSize> sortConfig;
	//sortConfig.shouldPrint = Print::Both;
//	sortConfig.arraySort = ArraySort::Descend;
	SortExecutor<unsigned long, SortArrSize> sortExec(sortConfig);
	sortExec.push( OperType::SelectionSort );
	sortExec.push( OperType::InsertionSort );
	sortExec.push( OperType::ShellSort );
	sortExec.execute();
	}
	{
	constexpr static std::size_t SortArrSize = 100;
	Config<int, SortArrSize> config;
//	config.shouldPrint = Print::Both;
	config.arraySort = ArraySort::Descend;
	Executor<int, SortArrSize> exec(config);
	exec.push( OperType::KnuthShuffle );
	exec.execute();
	}
	//std::array< unsigned, 10 > array = {1,3,6,8,9,10, 12, 17, 19, 20};

	return 0;
}
