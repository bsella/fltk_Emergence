#include <gui/node_item.h>
class Fl_Widget;

class Output_Node_Item : public Node_Item{
public:
   	Output_Node_Item(int,int);
   	~Output_Node_Item()override;
	static Node_Item* make(int,int,void*);
private:
	bool image_valid= false;
	void draw_body()const override;
	unsigned int* draw_buffer;
	void update_image();
	void scale(double)override;
	void context_menu(std::vector<Fl_Menu_Item>&)override;
	static void export_output(Fl_Widget*, void*);
};
