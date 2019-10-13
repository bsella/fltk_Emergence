#pragma once
#include <core/node.h>

class Color_Node : public Node{
public:
   	Color_Node(std::istream*);
    ~Color_Node()override;
	static Node* make(std::istream*);
private:
	void update_cache()override;
	void save(std::ostream&)const override;
	inline const char* id()const override;
};
