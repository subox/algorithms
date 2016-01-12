#include "helpers/Config.hpp"
#include "helpers/Executor.hpp"
#include <iostream>
#include <chrono>

using namespace subox::algorithms;

int main() {

	{
	constexpr static std::size_t SortArrSize = 20000;
	Config<unsigned long, SortArrSize> searchConfig;
	searchConfig.arraySort = ArraySort::Ascend;
	Executor<unsigned long, SortArrSize> searchExec(searchConfig);
	searchExec.push( OperType::BinarySearch );
	searchExec.execute();
	}
	{
	constexpr static std::size_t SortArrSize = 20000;
	Config<unsigned long, SortArrSize> sortConfig;
//	sortConfig.shouldPrint = Print::Both;
	sortConfig.valuesMax = 10;
	sortConfig.arraySort = ArraySort::Random;
	Executor<unsigned long, SortArrSize> sortExec(sortConfig);
	sortExec.push( OperType::SelectionSort );
	sortExec.push( OperType::InsertionSort );
	sortExec.push( OperType::ShellSort );
	sortExec.push( OperType::RecursiveMergeSort );
	sortExec.push( OperType::BottomUpMergeSort );
	sortExec.push( OperType::QuickSort );
	sortExec.execute();
	}
	{
	constexpr static std::size_t SortArrSize = 20000;
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
