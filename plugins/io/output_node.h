#include <core/node.h>
#include <vector>
#include <core/type_manager.h>

class Output_Node : public Node{
public:
	Output_Node();
	static Node* make(void*);
	std::vector<Node*> program;
	unsigned int pixel_cache;
private:
	void update_cache()override;
	void update_types()override;
	void update_valid()override;
	func_t to_color;
};
