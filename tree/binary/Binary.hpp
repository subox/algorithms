#ifndef __ALGORITHMS_TREE_BINARY_HPP__
#define __ALGORITHMS_TREE_BINARY_HPP__ 

#include "helpers/Base.hpp"
#include <algorithm>
#include <cassert>
#include <memory>
#include <iomanip>

namespace subox {
namespace algorithms {
namespace tree {

template< typename KEY, typename VALUE >
struct Node {
	Node( KEY const& _key, VALUE const& _value )
		: key(_key)
		, value(_value) {}

	KEY key;
	VALUE value;
	std::unique_ptr<Node> left;
	std::unique_ptr<Node> right;
};

template< typename KEY, typename VALUE = KEY >
struct Binary : public Base<VALUE> {
	typedef std::unique_ptr<Node<KEY, VALUE>> NodePtr;

	Binary() = default;

	void assignNumbers( typename ArrayBase<KEY>::MyArr const& initNumbers ) override {
		for (KEY key : initNumbers) {
			push( key );
		}
	}

	bool calc(VALUE const=0) override {
		KEY key = 0;
		VALUE val = 0;
		if (getMinimum(key,val)) {
			std::cout << "min: " << key << ":" << val << std::endl;
		}

		if (getMaximum(key,val)) {
			std::cout << "max: " << key << ":" << val << std::endl;
		}

		return true;
	}

	void print() const override {
		postOrderPrint( root.get() );
	}

	void push( VALUE const& item ) override {
		root = addNode( item, 10 * item, std::move(root) );
	}

	bool get( KEY const& key, VALUE& value ) const {
		Node<KEY,VALUE>* node = root.get();
		short whichBranch = 0;
		bool found = false;
		while (nullptr != node && false == found) {
			whichBranch = compareTo( node->key, key );
			if (whichBranch < 0) {
				node = node->left.get();
			} else if (whichBranch > 0) {
				node = node->right.get();
			} else {
				value = node->value;
				found = true;
			}
		}

		return found;
	}

	bool getMinimum( KEY& key, VALUE& value ) const {
		Node<KEY,VALUE>* node = root.get();
		bool minExists = false;
		if (nullptr != node) {
			minExists = true;
			while (nullptr != node->left) {
				node = node->left.get();
			}
			key = node->key;
			value = node->value;
		}

		return minExists;
	}

	bool getMaximum( KEY& key, VALUE& value ) const {
		Node<KEY,VALUE>* node = root.get();
		bool maxExists = false;
		if (nullptr != node) {
			maxExists = true;
			while (nullptr != node->right) {
				node = node->right.get();
			}
			key = node->key;
			value = node->value;
		}

		return maxExists;
	}


private:
	NodePtr addNode(
			KEY const& key
			,VALUE const& value
			,NodePtr node = nullptr ) {
		if (nullptr == node) {
		   node.reset( new Node<KEY,VALUE>( key, value ) );
		} else {
			short const whichBranch = compareTo( node->key, key );
			if (whichBranch < 0) {
				node->left = addNode( key, value, std::move(node->left) );
			} else if (whichBranch > 0) {
				node->right = addNode( key, value, std::move(node->right) );
			} else {
				node->value = value;
			}
		}

		return node;
	}
	
	void postOrderPrint( Node<KEY,VALUE>* node, short const indent = 0 ) const {
		if (nullptr != node) {
			if (nullptr != node->right) {
				postOrderPrint( node->right.get(), indent + 4 );
			}
			if (indent) {
				std::cout << std::setw(indent) << ' ';
			}
			std::cout << node->value << "\n";
			if (nullptr != node->left) {
				postOrderPrint( node->left.get(), indent + 4 );
			}
		}
	}

	short compareTo( KEY const& k1, KEY const& k2 ) const {
		if (k1 > k2) return -1;
		if (k1 < k2) return 1;
		return 0;
	}

	constexpr std::string name() const override {
		return "Binary Tree";
	}

	NodePtr root;
};


}
}
}

#endif // __ALGORITHMS_TREE_BINARY_HPP__
