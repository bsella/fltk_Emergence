#pragma once
#include <list>
#include <gui/graphics_view.h>
#include <gui/node_item.h>
class Toolbox_Item;

class Toolbox : public Graphics_View{
public:
	Toolbox(int x, int y, int w, int h);
	~Toolbox();
	static std::list<Item*> toolbox_items;
	static void add(make_node_item_t factory, const char* text, const char* icon_path= nullptr);
	static void remove(Toolbox_Item*);
private:
	void mouse_wheel_event(int,int)override;
	void draw()override;
};
