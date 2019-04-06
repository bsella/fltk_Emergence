#pragma once
#include "graphics_view.h"
class Node_Item;

class Workspace : public Graphics_View{
public:
	Workspace(int x, int y, int w, int h);
	~Workspace();
	void add_node(Node_Item*);
	void remove_node(Node_Item*);
private:
	void mouse_press_event(int,int,int)override;
	void mouse_release_event(int)override;
	void mouse_drag_event(int,int,int)override;
	void dnd_enter_event(int,int)override;
	void dnd_drag_event(int,int)override;
	void dnd_leave_event()override;
};
