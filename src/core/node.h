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
	void compile(std::vector<Node*>& program);
	virtual void compile_recursive(std::vector<Node*>& program);
	virtual void execute();

protected:
    std::vector<Node*> inodes;
    bool is_looping(Node*)const;
	virtual void update_valid();
	bool uniform= false;
	void invalidate_output_types();
	virtual void update_types();
	unsigned int compile_id=0;
	static unsigned int last_compile_id;
	void (*main_func)(Node**, void*);
	bool valid_types= false;

private:
	std::list<Node*> onodes;
	void update_uniform();
	virtual void update_cache();

	friend class Node_Item;
};
