#ifndef NODEBOX_H
#define NODEBOX_H

#include <FL/Fl_Browser.H>
#include <string>

class NodeBox : public Fl_Browser{
public:
	NodeBox(int x, int y, int w, int h);
	~NodeBox();
	void addTool(const char* id, const char* text, const char* icon_path);
	void remove(int item);
private:
	void item_draw(void* item, int x, int y, int w, int h) const override;
    int handle(int);
    void* hover=nullptr;
};

#endif // NODEBOX_H
