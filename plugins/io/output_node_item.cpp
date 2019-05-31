#include "output_node_item.h"
#include "output_node.h"

Output_Node_Item::Output_Node_Item(int x, int y): Node_Item(x,y,50,50, new Output_Node){}

Node_Item* Output_Node_Item::make(int x, int y, void*){
	return new Output_Node_Item(x,y);
}

void Output_Node_Item::draw_body()const{
	fl_color(FL_GREEN);
	fl_rect(_x, _y, _w, _h);
}
