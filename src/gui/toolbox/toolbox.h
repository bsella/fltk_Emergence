#pragma once
#include <list>
#include <gui/graphics_view.h>
#include "toolbox_item.h"
class Toolbox_Category;

class Toolbox : public Graphics_View{
public:
	Toolbox(int x, int y, int w, int h);
	~Toolbox();
	static std::list<Item*> toolbox_items;
	static void add(Toolbox_Item*);
	static Toolbox_Category* add_category(const char*, const char* icon= nullptr);
	static void remove(Toolbox_Item*);
	static void update_content_height();
private:
	void mouse_wheel_event(int,int)override;
	void mouse_click_event(int,int,int)override;
	void draw()override;
	int scroll_y=0;
	static int content_height;
};
