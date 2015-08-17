#include "search/binary/Binary.hpp"
#include "sort/selection/Selection.hpp"
#include "helpers/Config.hpp"
#include "helpers/SearchExecutor.hpp"
#include "helpers/SortExecutor.hpp"
#include <iostream>
#include <chrono>

using namespace subox::algorithms;

template <typename T, std::size_t N>
typename Base<T,N>::MyArr Base<T,N>::arr;

void count() {
	search::Binary< unsigned long, 1000000 > bin;
	search::Binary< unsigned long, 1000000 > abin;

	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//	bin.search( 25789 );
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	std::cout << "Printing took "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
	          << "us.\n";
}

int main() {

    Config<unsigned long> searchConfig;
    SearchExecutor<unsigned long> searchExec(searchConfig);
    searchExec.push( OperType::BinarySearch );
    searchExec.execute();
    
    constexpr static std::size_t SortArrSize = 20000;
    Config<unsigned long, SortArrSize> sortConfig;
    //sortConfig.shouldPrint = Print::Both;
    SortExecutor<unsigned long, SortArrSize> sortExec(sortConfig);
    sortExec.push( OperType::SelectionSort );
    sortExec.execute();

	//std::array< unsigned, 10 > array = {1,3,6,8,9,10, 12, 17, 19, 20};

	return 0;
}
