#include <core/node.h>
#include <gui/node_item.h>

class If_Node : public Node{
public:
   	If_Node();
	static Node* make(void*);
private:
	void update_cache()override;
	void prepare_program(std::vector<Node*>& program)const override;
};
