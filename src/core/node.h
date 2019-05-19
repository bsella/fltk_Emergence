#pragma once
#include <vector>
class Node{
public:
	Node(int, bool hasOutput=true);
    ~Node();
	const bool hasOutput;
    void connect(int,Node*);
	void disconnect(int);
protected:
    std::vector<Node*> inodes;
    bool is_looping(Node*)const;
};
