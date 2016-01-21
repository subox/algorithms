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

template< typename TObject, template< typename...> class TContainer = std::vector >
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
		adjList.reserve( capacity );
		adjList.clear();
		for (std::size_t i = 0; i < capacity; ++i) {
			adjList.emplace_back( typename Base<TObject>::MyArr() );
		}
	}

	bool addEdge( TObject const& v1, TObject const& v2 ) {
		if (adjList.size() > v1 and adjList.size() > v2 ) {
			adjList[ v1 ].emplace_back( v2 );
			adjList[ v2 ].emplace_back( v1 );
			return true;
		}

		return false;
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
