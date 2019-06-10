#include <gui/node_item.h>

class Output_Node_Item : public Node_Item{
public:
   	Output_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
private:
	void connect(int, Node_Item*)override;
	void draw_body()const override;
	std::vector<unsigned int> image;
	void update_image();
	void scale(float)override;
};
