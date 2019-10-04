#pragma once
#include "graphics_view.h"
class Node_Item;

class Workspace : public Graphics_View{
public:
	Workspace(int x, int y, int w, int h);
	~Workspace();
	void add_node(Node_Item*);

	static void insert(Fl_Widget*, void*);
	static void select_all(Fl_Widget*, void*);
	static void remove_selected(Fl_Widget*, void*);

private:
	std::list<Node_Item*> selected;
	double zoom;
	double zero_x, zero_y;
	void draw()override;
	void update_rubberband(int, int);
	void reset_rubberband();

	void mouse_press_event(int,int,int)override;
	void mouse_release_event(int)override;
	void mouse_drag_event(int,int,int)override;
	void dnd_enter_event(int,int)override;
	void dnd_drag_event(int,int)override;
	void dnd_drop_event(int,int)override;
	void dnd_leave_event()override;
	void mouse_wheel_event(int,int)override;
	void mouse_click_event(int,int,int)override;

	void select(Node_Item*);
	void deselect(Node_Item*);
	void deselect_all();
};
