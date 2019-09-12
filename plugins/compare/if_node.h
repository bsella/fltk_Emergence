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
	void compile_recursive(std::vector<Node*>&)override;
	void update_types()override;
	func_t to_bool;
	bool last_res;
};
