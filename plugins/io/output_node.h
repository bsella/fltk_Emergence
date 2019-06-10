#include <core/node.h>
#include <vector>

class Output_Node : public Node{
public:
   	Output_Node();
	static Node* make(void*);
	std::vector<Node*> program;
private:
	void kernel()override;
	void connect(int, Node*)override;
};
