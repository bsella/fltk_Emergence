#include <gui/node_item.h>

class Output_Node_Item : public Node_Item{
public:
   	Output_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
private:
	bool image_valid= false;
	void draw_body()const override;
	std::vector<unsigned int> draw_buffer;
	void update_image();
	void scale(float)override;
};
