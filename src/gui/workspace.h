#pragma once
#include "graphics_view.h"
class Node_Item;

class Workspace : public Graphics_View{
public:
	Workspace(int x, int y, int w, int h);
	~Workspace();
	void add_node(Node_Item*);
	void remove_node(Node_Item*);
private:
	int handle(int)override;
};
