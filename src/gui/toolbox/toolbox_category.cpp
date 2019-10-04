#include "toolbox_category.h"
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <algorithm>
#include "resources.h"

Toolbox_Category::Toolbox_Category(const char* title, const char* icon_path)
	: Toolbox_Item(category_height, title, icon_path){
}

Toolbox_Category::~Toolbox_Category(){
	for(auto item : sub_items)
		delete item;
}

Fl_PNG_Image Toolbox_Category::open_icon(RELATIVE("src/gui/toolbox/open.png"));
Fl_PNG_Image Toolbox_Category::closed_icon(RELATIVE("src/gui/toolbox/closed.png"));

void Toolbox_Category::add(Toolbox_Item* item){
	sub_items.push_back(item);
	if(open) _h+=item->_h;
}

void Toolbox_Category::remove(Toolbox_Item* item){
	sub_items.erase(std::find(sub_items.begin(), sub_items.end(), item));
}

void Toolbox_Category::draw()const{	
	fl_draw_box(FL_UP_BOX, _x, _y, _w, category_height, 0x008000ff);
	fl_color(FL_WHITE);
	fl_draw(text, _x+36, _y+category_height/2+4);
	if(!open)
		closed_icon.draw(_x+4, _y+category_height/2- closed_icon.h()/2);
	else{
		open_icon.draw(_x+4, _y+category_height/2- open_icon.h()/2);
		int temp_y = _y+category_height;
		for(const auto item : sub_items){
			item->_w =_w;
			item->_x =_x;
			item->_y =temp_y;
			item->draw();

			temp_y+= item->_h;
		}
	}
}
void Toolbox_Category::toggle_open(){
	_h= category_height;
	if(!open){
		for(const auto item : sub_items)
			_h+=item->_h;
	}
	open= !open;
}
Toolbox_Item* hover= nullptr;
void Toolbox_Category::mouse_enter_event(int x, int y){
	if(open && y-_y>category_height)
		for(auto item : sub_items)
			if(item->inside(x,y)){
				item->mouse_enter_event(x,y);
				hover= item;
				return;
			}
}
void Toolbox_Category::mouse_leave_event(){
	if(hover){
		hover->mouse_leave_event();
		hover=nullptr;
	}
}
void Toolbox_Category::mouse_move_event(int x, int y){
	if(!open) return;
	if(y-_y>category_height){
		for(auto item : sub_items)
			if(item->inside(x,y)){
				if(item==hover) item->mouse_move_event(x,y);
				else{
					if(hover) hover->mouse_leave_event();
					item->mouse_enter_event(x,y);
					hover= item;
				}
				return;
			}
	}else{
		if(hover){
			hover->mouse_leave_event();
			hover=nullptr;
		}
	}
}
void Toolbox_Category::mouse_press_event(int x, int y){
	if(hover) hover->mouse_press_event(x,y);
}
void Toolbox_Category::mouse_release_event(){
	if(hover) hover->mouse_release_event();
}
void Toolbox_Category::mouse_drag_event(int dx, int dy){
	if(hover) hover->mouse_drag_event(dx,dy);
}
void Toolbox_Category::mouse_click_event(int x, int y, int button){
	if(y-_y<=category_height)
		toggle_open();
	else
		if(hover) hover->mouse_click_event(x,y, button);
	draw();
}
