#pragma once
#include <FL/Fl_Browser.H>
#include <string>

class Node_Box : public Fl_Browser{
public:
	Node_Box(int x, int y, int w, int h);
	~Node_Box();
	void addTool(const char* id, const char* text, const char* icon_path);
	void remove(int item);
private:
	void item_draw(void* item, int x, int y, int w, int h) const override;
    int handle(int);
    void* hover=nullptr;
};
