#pragma once
#include <FL/Fl_Double_Window.H>
#include <list>
#include "item.h"

class Graphics_View : public Fl_Double_Window{
public:
	Graphics_View(int x, int y, int w, int h);
	~Graphics_View();
	void add_item(Item*);
	void remove_item(Item*);
protected:
	static Item* hover;
	std::list<Item*> items;
	virtual int handle(int)override;

private:
	std::list<Item*> selected;
	void draw()override;
	float zoom;
	void update_rubberband(int, int);
	void reset_rubberband();
	Item* top_item(int,int,int*)const;
};
