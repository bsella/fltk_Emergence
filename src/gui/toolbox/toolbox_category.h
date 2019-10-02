#pragma once
#include <vector>
#include "toolbox_item.h"

class Toolbox_Category : public Toolbox_Item{
public:
	Toolbox_Category(const char* title, const char* icon_path);
	~Toolbox_Category();
	void add(Toolbox_Item*);
	void remove(Toolbox_Item*);
private:
	static constexpr int category_height = 30;
	bool open=true;
	std::vector<Toolbox_Item*> sub_items;
	void draw()const override;
	void toggle_open();

	void mouse_enter_event(int,int)override;
	void mouse_leave_event()override;
	void mouse_move_event(int,int)override;
	void mouse_press_event(int,int)override;
	void mouse_release_event()override;
	void mouse_drag_event(int,int)override;
	void mouse_click_event(int,int,int)override;

	static Fl_PNG_Image open_icon;
	static Fl_PNG_Image closed_icon;
};
