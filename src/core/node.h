#pragma once
#include <vector>
#include <list>
class Data_t;

class Node{
public:
	Node(int, bool hasOutput=true);
    ~Node();
	const bool hasOutput;
    virtual void connect(int,Node*);
	void disconnect(int);
	Data_t* cache;
	bool valid;
	virtual void prepare_program(std::vector<Node*>& program)const;
	virtual void update_cache()=0;

protected:
    std::vector<Node*> inodes;
    bool is_looping(Node*)const;

	bool uniform= false;

private:
	std::list<Node*> onodes;
	void update_valid();
	void update_uniform();

	friend class Node_Item;
};
