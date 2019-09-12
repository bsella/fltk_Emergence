#pragma once
#include <gui/item.h>
#include <FL/Fl_PNG_Image.H>

class Toolbox_Item : public Item {
public:
	Toolbox_Item(int h, const char* text);
	Toolbox_Item(int h, const char* text, Fl_PNG_Image* icon);
	Toolbox_Item(int h, const char* text, const char* icon_path);
	virtual ~Toolbox_Item();
protected:
	Fl_PNG_Image* icon= nullptr;
	const char* text;
	virtual void draw()const override;
private:
	const bool own_icon;

	friend class Toolbox;
	friend class Toolbox_Category;
};
