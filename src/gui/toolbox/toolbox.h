#pragma once
#include <string>
#include <list>
#include <gui/graphics_view.h>
#include "toolbox_item.h"

class Toolbox : public Graphics_View{
public:
	Toolbox(int x, int y, int w, int h);
	~Toolbox();
	static void add(const std::string& id, const char* text, const char* icon_path= nullptr);
	static void remove(Toolbox_Item*);
private:
	static std::list<Item*> toolbox_items;
	void mouse_wheel_event(int,int)override;
	void draw()override;
};
