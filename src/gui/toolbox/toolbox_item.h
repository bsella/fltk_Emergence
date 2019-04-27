#pragma once
#include <gui/item.h>
#include <string>
#include <FL/Fl_PNG_Image.H>

class Toolbox_Item : public Item {
public:
	Toolbox_Item(int y, const std::string& id, const char* text, const char* icon_path);
	~Toolbox_Item();
	static const unsigned int h;
private:
	Fl_PNG_Image* icon;
	const std::string& id;
	const char* text;
	void mouse_enter_event(int,int)override;
	void mouse_leave_event()override;
	void mouse_drag_event(int,int)override;
	void draw()const override;

	friend class Toolbox;
};
