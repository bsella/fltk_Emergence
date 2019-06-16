#include <core/node.h>
#include <vector>

class Output_Node : public Node{
public:
   	Output_Node();
	static Node* make(void*);
	std::vector<Node*> program;
	Node* first;
private:
	void update_cache()override;
	void update_valid()override;
	void prepare_program(std::vector<Node*>&) override;
};
