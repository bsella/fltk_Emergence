#include <core/node.h>
#include <vector>

class Output_Node : public Node{
public:
	Output_Node();
	static Node* make(void*);
	std::vector<Node*> program;
	void render(int, int, unsigned int*);
private:
	void update_cache()override;
	void update_types()override;
	void update_valid()override;
	unsigned int* current_pixel;
};
