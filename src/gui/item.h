#pragma once
#include <vector>
#include "core/node.h"
class Item{
public:
	Item(int x, int y, int w, int h);
	virtual ~Item();
	inline int x()const{return _x;}
	inline int y()const{return _y;}
	inline int w()const{return _w;}
	inline int h()const{return _h;}
	void set_pos(int,int);

protected:
	virtual bool inside(int,int)const;
	int _x,_y, _w,_h;
	const int width, height;

	inline void set_hover()          {flags|=1;}
	inline void reset_hover()        {flags&=254;}
	inline bool is_hover()      const{return flags&1;}
	inline void set_selected()       {flags|=2;}
	inline void reset_selected()     {flags&=253;}
	inline bool is_selected()   const{return flags&2;}

	virtual void mouse_enter_event(int,int);
	virtual void mouse_leave_event();
	virtual void mouse_move_event(int,int);
	virtual void mouse_press_event(int,int);
	virtual void mouse_release_event();
	virtual void mouse_drag_event();
	virtual void mouse_click_event(int,int,int);

private:
	unsigned char flags; // 1:hover 2:select

	friend class Graphics_View;

	bool inside(int,int,int,int)const;
	void move(int,int);
	void scale(float);
	virtual void draw()const=0;

};
