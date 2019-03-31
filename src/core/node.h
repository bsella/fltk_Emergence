#pragma once
#include <vector>
class Node{
public:
	Node(int);
	~Node();
	void connect(int,Node*);
	void disconnect(int);
protected:
    std::vector<Node*> inodes;
	bool is_looping(Node*)const;
};
