#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <FL/Fl_Double_Window.H>
#include <list>
#include "node_item.h"

class Workspace : public Fl_Double_Window{
public:
	Workspace(int x, int y, int w, int h);
	~Workspace();
	void add_node(BaseNodeItem*);
	void remove_node(BaseNodeItem*);
private:
	std::list<BaseNodeItem*> nodes;
	void draw()override;
	int handle(int)override;
	float zoom;
};

#endif // WORKSPACE_H
