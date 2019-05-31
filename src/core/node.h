#pragma once
#include <vector>
#include "data_t.h"

class Node{
public:
	Node(int, bool hasOutput=true);
    ~Node();
	const bool hasOutput;
    void connect(int,Node*);
	void disconnect(int);
protected:
	Data_t* cache;
	virtual void kernel()=0;
    std::vector<Node*> inodes;
    bool is_looping(Node*)const;

	friend class Node_Item;
};
