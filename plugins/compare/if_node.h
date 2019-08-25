#include <core/node.h>

class If_Node : public Node{
public:
   	If_Node();
	static Node* make(void*);
private:
	std::vector<Node*> then_program;
	std::vector<Node*> else_program;
	void update_cache()override;
	void compile(std::vector<Node*>& program)override;
};
