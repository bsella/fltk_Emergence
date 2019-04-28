#pragma once
#include <list>
#include <gui/graphics_view.h>
class Toolbox_Item;

class Toolbox : public Graphics_View{
public:
	Toolbox(int x, int y, int w, int h);
	~Toolbox();
	static void add(const char* id, const char* text, const char* icon_path= nullptr);
	static void remove(Toolbox_Item*);
	static std::list<Item*> toolbox_items;
private:
	void mouse_wheel_event(int,int)override;
	void draw()override;
};
