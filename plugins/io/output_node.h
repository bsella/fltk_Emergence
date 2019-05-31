#include <core/node.h>

class Output_Node : public Node{
public:
   	Output_Node();
	static Node* make(void*);
private:
	void kernel()override;
};
