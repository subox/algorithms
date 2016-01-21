#ifndef __ALGORITHMS_DEPTH_FIRST_SEARCH_HPP__
#define __ALGORITHMS_DEPTH_FIRST_SEARCH_HPP__

#include "graphs/Graph.hpp"
#include <unordered_map>
#include <iostream>

namespace subox {
namespace algorithms {
namespace graphs {

template<
	typename TObject = unsigned
	,template< typename...> class TContainer = std::unordered_map >
struct DepthFirstSearch {
	DepthFirstSearch( Graph<TObject> const& g, TObject const _source )
			: source( _source )	{
		dfs(g, source);	
	}

	inline bool hasPathTo( TObject const vertex ) {
		return visitedVertexes.end() != visitedVertexes.find(vertex);
	}

	void printPathTo( TObject const vertex ) {
		if (hasPathTo(vertex)) {
			for (TObject i = vertex; i != source; i = visitedVertexes[i]) {
				std::cout << i << "-";
			}
			std::cout << source << std::endl;
		}
	}

	void print() {
		for (auto pair : visitedVertexes) {
			std::cout << pair.first << ":" << pair.second << std::endl;
		}
	}

private:
	void dfs( Graph<TObject> const& g, TObject const vertex ) {
		visitedVertexes[vertex] = vertex; 
		for (auto w : g[vertex]){
			if (notVisited( w )) {
				dfs( g, w );
				visitedVertexes[w] = vertex;
			}
		}
	}

	inline bool notVisited( TObject const vertex ) {
		return visitedVertexes.end() == visitedVertexes.find(vertex);
	}

	TContainer<TObject,TObject> visitedVertexes;
	TObject const source;
};

}
}
}

#endif // __ALGORITHMS_DEPTH_FIRST_SEARCH_HPP__
