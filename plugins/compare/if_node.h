#include <core/node.h>
#include <core/type_manager.h>

class If_Node : public Node{
public:
   	If_Node();
	static Node* make(void*);
private:
	std::vector<Node*> then_program;
	std::vector<Node*> else_program;
	void update_cache()override;
	void compile_specific(std::vector<Node*>&, bool)override;
	void update_types()override;
	bool last_res;
};
