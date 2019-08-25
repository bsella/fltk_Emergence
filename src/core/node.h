#pragma once
#include <vector>
#include <list>
class Data_t;

class Node{
public:
	Node(int, bool hasOutput=true);
    virtual ~Node();
	const bool hasOutput;
    void connect(int,Node*);
	void disconnect(int);
	Data_t* cache= nullptr;
	bool valid;
	virtual void compile(std::vector<Node*>& program);
	virtual void update_cache()=0;

protected:
    std::vector<Node*> inodes;
    bool is_looping(Node*)const;

	virtual void update_valid();
	bool uniform= false;

private:
	std::list<Node*> onodes;
	void update_uniform();

	friend class Node_Item;
};
