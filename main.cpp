#include "helpers/Config.hpp"
#include "helpers/Executor.hpp"
#include <iostream>
#include <chrono>
#include "tree/binary/Binary.hpp"
#include "graphs/Graph.hpp"

using namespace subox::algorithms;

int main() {

	{
		graphs::Graph<int> g(10);
		g.addEdge( 8, 2 );
		g.print();
	}
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
	{
	constexpr static std::size_t ArrSize = 10;
	Config<int, ArrSize> config;
//	config.shouldPrint = Print::Both;
	config.initNumbers = { 2, 3, 7, 10, 8, 2, 5, 6, 4 };
//	config.arraySort = ArraySort::Descend;
	Executor<int, ArrSize> exec(config);
	exec.push( OperType::BinaryTree );
	exec.execute();
	}

	return 0;
}
