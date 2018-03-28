#pragma once

#include "GraphNode.h"

typedef GraphNode<std::pair<std::string, std::pair<int, int>>, int> Node;

class NodeSearchCostComparer {
public:
	bool operator()(Node * n1, Node * n2) {
		std::pair<std::string, std::pair<int, int>> p1 = n1->data();
		std::pair<std::string, std::pair<int, int>> p2 = n2->data();
		return p1.second.second > p2.second.second;
	}
};
