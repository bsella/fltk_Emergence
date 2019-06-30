#pragma once
#include <FL/Fl_Widget.H>
#include <list>
class Item;

class Graphics_View : public Fl_Widget{
public:
	Graphics_View(int x, int y, int w, int h);
	virtual ~Graphics_View();
	void add_item(Item*);
	void remove_item(Item*);
protected:
	Item* hover= nullptr;
	std::list<Item*>* items= nullptr;
	virtual void mouse_enter_event(int,int);
	virtual void mouse_leave_event();
	virtual void mouse_move_event(int,int);
	virtual void mouse_click_event(int,int,int);
	virtual void mouse_press_event(int,int,int);
	virtual void mouse_drag_event(int,int,int);
	virtual void mouse_release_event(int);
	virtual void mouse_wheel_event(int,int);
	virtual void dnd_enter_event(int,int);
	virtual void dnd_drag_event(int,int);
	virtual void dnd_drop_event(int,int);
	virtual void dnd_leave_event();
	virtual void draw()override;

private:
	int handle(int)override;
};
