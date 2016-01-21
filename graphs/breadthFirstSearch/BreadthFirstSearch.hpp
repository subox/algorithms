#ifndef __ALGORITHMS_BREADTH_FIRST_SEARCH_HPP__
#define __ALGORITHMS_BREADTH_FIRST_SEARCH_HPP__

#include "graphs/Graph.hpp"
#include <unordered_map>
#include <iostream>
#include <queue>

namespace subox {
namespace algorithms {
namespace graphs {

template<
	typename TObject = unsigned
	,template< typename...> class TContainer = std::unordered_map >
struct BreadFirstSearch {
	BreadFirstSearch( Graph<TObject> const& g, TObject const _source )
			: source( _source )	{
		bfs(g);	
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
	void bfs( Graph<TObject> const& g ) {
		std::queue<TObject> q;
		q.emplace( source );
		visitedVertexes[source] = source;

		while (!q.empty()) {
			TObject const v = q.front();
			q.pop();
			for (auto w : g[v]){
				if (notVisited( w )) {
					q.push( w );
					visitedVertexes[w] = v;
				}
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

#endif // __ALGORITHMS_BREADTH_FIRST_SEARCH_HPP__
