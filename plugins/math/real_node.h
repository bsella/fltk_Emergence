#pragma once
#include <core/node.h>

class Real_Node : public Node{
public:
   	Real_Node(std::istream*);
    ~Real_Node()override;
	static Node* make(std::istream*);
private:
	void update_cache()override;
	void save(std::ostream&)const override;
	inline const char* id()const override;
};
