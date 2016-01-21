#ifndef __ALGORITHMS_CONNECTED_COMPONENTS_HPP__
#define __ALGORITHMS_CONNECTED_COMPONENTS_HPP__

#include "graphs/Graph.hpp"
#include <unordered_map>
#include <iostream>

namespace subox {
namespace algorithms {
namespace graphs {

template<
	typename TObject = unsigned
	,template< typename...> class TContainer = std::unordered_map >
struct ConnectedComponents {
	ConnectedComponents( Graph<TObject> const& g ) {
		for (TObject v = 0; v < g.size(); ++v) {
			if (notVisited(v)) {
				dfs(g, v);
				++count;
			}
		}
	}

	inline TObject getCount() const {
		return count;
	}

	bool isConnected( TObject const v1, TObject const v2 ) {
		return visitedVertexes[v1] == visitedVertexes[v2];
	}

	void print() {
		for (auto pair : visitedVertexes) {
			std::cout << pair.first << ":" << pair.second << std::endl;
		}
	}

private:
	void dfs( Graph<TObject> const& g, TObject const vertex ) {
		visitedVertexes[vertex] = count;
		for (auto w : g[vertex]){
			if (notVisited( w )) {
				dfs( g, w );
			}
		}
	}

	inline bool notVisited( TObject const vertex ) {
		return visitedVertexes.end() == visitedVertexes.find(vertex);
	}

	TContainer<TObject,TObject> visitedVertexes;
	TObject count = 0;
};

}
}
}

#endif // __ALGORITHMS_CONNECTED_COMPONENTS_HPP__
