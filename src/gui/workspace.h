#pragma once
#include "graphics_view.h"
#include "node_item.h"
class Workspace : public Graphics_View{
public:
	Workspace(int x, int y, int w, int h);
	~Workspace();
	void add_node(NodeItem*);
	void remove_node(NodeItem*);
private:
	int handle(int)override;
};
