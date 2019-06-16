#pragma once
#include <gui/item.h>
#include <FL/Fl_PNG_Image.H>

class Toolbox_Item : public Item {
public:
	Toolbox_Item(int h, const char* text, const char* icon_path);
	virtual ~Toolbox_Item();
protected:
	Fl_PNG_Image* icon;
	const char* text;
	virtual void draw()const override;

	friend class Toolbox;
	friend class Toolbox_Category;
};
