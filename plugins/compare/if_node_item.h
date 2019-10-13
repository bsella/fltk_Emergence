#include "if_node.h"
#include <gui/node_item.h>

class If_Node_Item : public Node_Item{
public:
   	If_Node_Item();
	static Node_Item* make(std::istream*);
private:
	void draw_body()const override;
	unsigned int color()const override;
};
