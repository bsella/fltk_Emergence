#pragma once
#include <list>
#include <gui/graphics_view.h>
#include "toolbox_item.h"

class Toolbox : public Graphics_View{
public:
	Toolbox(int x, int y, int w, int h);
	~Toolbox();
	static std::list<Item*> toolbox_items;
	static void add(Toolbox_Item*);
	static void remove(Toolbox_Item*);
private:
	void mouse_wheel_event(int,int)override;
	void mouse_click_event(int,int,int)override;
	void draw()override;
};
