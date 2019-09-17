#include "real_node_item.h"
#include "real_node.h"
#include <real/real_t.h>
#include <FL/fl_draw.H>
#include <string>
#include "real_chooser.h"
#include <FL/Fl_Menu_Item.H>

Real_Node_Item::Real_Node_Item(int x, int y, void* ptr): Node_Item(x, y, 70, 16, new Real_Node(ptr)){}

void Real_Node_Item::draw_body()const{
	fl_color(FL_WHITE);
	fl_rectf(_x, _y, _w, _h);
	fl_color(FL_BLACK);
	fl_rect(_x, _y, _w, _h);
	fl_draw(std::to_string(((Real_t*)core_node->cache)->value).c_str(), _x, _y+_h-2);
}

Node_Item* Real_Node_Item::make(int x, int y, void* ptr){
	return new Real_Node_Item(x,y, ptr);
}

bool Real_Node_Item::settle(){
	return real_chooser(this);
}

static void real_edit_value(Fl_Widget*, void* ptr){
	Real_Node_Item* node= (Real_Node_Item*)ptr;
	double temp= ((Real_t*)node->cache())->value;
	if(!real_chooser(node))
	((Real_t*)node->cache())->value= temp;
}
void Real_Node_Item::context_menu(std::vector<Fl_Menu_Item>& menu){
	menu.back().flags|= FL_MENU_DIVIDER;

	menu.push_back({"Edit Value", 0, real_edit_value, this, 0,0,0,0,0});

	Node_Item::context_menu(menu);
}
