#pragma once
#include <vector>

class Item{
public:
	Item(int x, int y, int w, int h);
	virtual ~Item();
	inline int x()const{return _x;}
	inline int y()const{return _y;}
	virtual inline int w()const{return _w;}
	virtual inline int h()const{return _h;}
	void set_pos(int,int);
	int _x,_y, _w,_h;

	virtual bool inside(int,int)const;
	bool inside(int,int,int,int)const;

	void move(int,int);
	virtual void scale(float);

	inline void set_hover()          {flags|=1;}
	inline void reset_hover()        {flags&=254;}
	inline bool is_hover()      const{return flags&1;}
	inline void set_selected()       {flags|=2;}
	inline void reset_selected()     {flags&=253;}
	inline bool is_selected()   const{return flags&2;}

protected:
	const int width, height;

	virtual void mouse_enter_event(int,int);
	virtual void mouse_leave_event();
	virtual void mouse_move_event(int,int);
	virtual void mouse_press_event(int,int);
	virtual void mouse_release_event();
	virtual void mouse_drag_event(int,int);
	virtual void mouse_click_event(int,int,int);

private:
	unsigned char flags=0; // 1:hover 2:select

	virtual void draw()const=0;

	friend class Graphics_View;
};
