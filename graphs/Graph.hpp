#ifndef __ALGORITHMS_GRAPH_HPP__
#define __ALGORITHMS_GRAPH_HPP__

#include "helpers/Base.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

namespace subox {
namespace algorithms {
namespace graphs {

template< typename TObject = unsigned, template< typename...> class TContainer = std::vector >
struct Graph : public Base<TObject> {
	typedef typename Base<TObject>::MyArr EdgeList;
	typedef TContainer<EdgeList> AdjacList;
	typedef typename AdjacList::iterator iterator;
	typedef typename AdjacList::const_iterator const_iterator;

	Graph( typename AdjacList::size_type const vertexSize = 0 ) {
		generateNumbers(vertexSize);
	}

	~Graph(){}

	void assignNumbers( AdjacList&& _adjList ){
		adjList = _adjList;
	}

	void generateNumbers( std::size_t const capacity = 0, bool const = false ) override {
		if (capacity) {
			adjList.clear();
			increaseAdjList( capacity );
		}
	}

	void addEdge( TObject const& v1, TObject const& v2 ) {
		if (adjList.size() <= v1){
			increaseAdjList( v1 );
		}

		if (adjList.size() <= v2 ) {
			increaseAdjList( v2 );
		}
		adjList[ v1 ].emplace_back( v2 );
		adjList[ v2 ].emplace_back( v1 );
	}

	EdgeList const& getEdges( TObject const& vertex ) const {
		return adjList[vertex];
	}

	const_iterator begin() const {
		return adjList.cbegin();
	}

	const_iterator end() const {
		return adjList.cend();
	}

	EdgeList const& operator[]( TObject const& item ) const {
		return getEdges( item );
	}

	typename AdjacList::size_type size() const {
		return adjList.size();
	}

	void print() const override {
		for (typename AdjacList::size_type v = 0; v < adjList.size(); ++v ) {
			for( TObject const& item : adjList[v] ) {
				std::cout << v << " --- " << item << std::endl;
			}
		}
		
	 };

	bool calc(TObject const=1) {
		//todo
		std::cerr << "Error: Not a sort type" << std::endl;
		return false;
	}

	constexpr std::string name() const override {
		return "Graph";
	}

private:
	void increaseAdjList( TObject const newSize ) {
		adjList.reserve( newSize + 1 );
		for (std::size_t i = adjList.size(); i < newSize; ++i) {
			adjList.emplace_back( typename Base<TObject>::MyArr() );
		}
	}

	void assignNumbers( EdgeList const& /*initNumbers */ ) override {
	}

	inline void push( TObject const& item ) {
		adjList.emplace_back( item );
	}

	AdjacList adjList;
};

}
}
}

#endif // __ALGORITHMS_GRAPH_HPP__
