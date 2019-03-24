#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <FL/Fl_Double_Window.H>
#include <list>
#include "node_item.h"

class Workspace : public Fl_Double_Window{
public:
	Workspace(int x, int y, int w, int h);
	~Workspace();
	void add_node(NodeItem*);
	void remove_node(NodeItem*);
private:
	std::list<NodeItem*> nodes;
	std::list<NodeItem*> selected;
	void draw()override;
	int handle(int)override;
	float zoom;
	static int rb_from_x, rb_from_y, rb_to_x, rb_to_y;
	void update_rubberband(int, int);
	void reset_rubberband();
	NodeItem* top_node(int,int,int*)const;
};

#endif // WORKSPACE_H
