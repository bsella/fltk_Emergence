#include "node_box.h"
#include <FL/Fl_PNG_Image.H>
#include <FL/fl_draw.H>
struct item_data{
	std::string id;
	Fl_Image* icon;
};
NodeBox::NodeBox(int x, int y, int w, int h):Fl_Browser(x,y,w,h){}
void NodeBox::addTool(const char* id, const char* text, const char* icon_path){
	item_data *newItem = new item_data{std::string(id), new Fl_PNG_Image(icon_path)};
	add(text, newItem);
	icon(size(), newItem->icon);
}
void NodeBox::item_draw(void* item, int x, int y, int w, int h)const{
	if(!item)
		return;
	Fl_Browser::item_draw(item,x,y,w,h);
	fl_line(x, y+h, x+w, y+h);
}
void NodeBox::remove(int line){
	if(line < 1 || line > size()) return;
	delete ((item_data*)data(line))->icon;
	Fl_Browser::remove(line);
}
NodeBox::~NodeBox(){
	for(int i=1; i<=size(); i++)
		remove(i);
	clear();
}
int NodeBox::handle(int e){
	static void* tmp;
			const char *msg = "It works!";
	switch(e){
		case FL_ENTER:
			hover= find_item(Fl::event_y());
			if(!hover) return 0;
			return 1;
		case FL_MOVE:
			tmp= find_item(Fl::event_y());
			if(tmp==hover) return 0;
			hover=tmp;
			return 1;
		case FL_LEAVE:
			if(!hover) return 0;
			hover= nullptr;
			return 1;
		case FL_DRAG:
			Fl::copy(msg,strlen(msg),0);
 			Fl::dnd();
			return 1;
	    default:break;
	}
	return Fl_Browser::handle(e);
}
