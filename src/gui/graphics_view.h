#pragma once
#include <FL/Fl_Double_Window.H>
#include <list>
class Item;

class Graphics_View : public Fl_Double_Window{
public:
	Graphics_View(int x, int y, int w, int h);
	~Graphics_View();
	void add_item(Item*);
	void remove_item(Item*);
protected:
	static Item* hover;
	std::list<Item*> items;
	int handle(int)override;
	virtual void mouse_move_event(int,int);
	virtual void mouse_click_event(int,int,int);
	virtual void mouse_press_event(int,int,int);
	virtual void mouse_drag_event(int,int,int);
	virtual void mouse_release_event(int);
	virtual void mouse_wheel_event(int,int);
	virtual void dnd_enter_event(int,int);
	virtual void dnd_drag_event(int,int);
	virtual void dnd_leave_event();

private:
	std::list<Item*> selected;
	void draw()override;
	float zoom;
	void update_rubberband(int, int);
	void reset_rubberband();
	Item* top_item(int,int,int*)const;
};
