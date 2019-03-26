#pragma once
#include <vector>
class Node{
public:
	Node(int);
	~Node();
protected:
    std::vector<Node*> inodes;
};
