#pragma once
#include <vector>

class Item{
public:
	Item();
	Item(int w, int h);
	Item(int x, int y, int w, int h);
	virtual ~Item();
	int _x,_y, _w,_h;

	virtual bool inside(int,int)const;
	bool inside(int,int,int,int)const;

	void set_pos(int,int);
	void move(int,int);

protected:
	virtual void mouse_enter_event(int,int);
	virtual void mouse_leave_event();
	virtual void mouse_move_event(int,int);
	virtual void mouse_press_event(int,int);
	virtual void mouse_release_event();
	virtual void mouse_drag_event(int,int);
	virtual void mouse_click_event(int,int,int);

private:
	virtual void draw()const=0;

	friend class Graphics_View;
};
