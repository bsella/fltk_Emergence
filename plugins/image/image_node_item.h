#pragma once
#include <gui/node_item.h>
class Fl_Image;
class Fl_Widget;

class Image_Node_Item : public Node_Item{
public:
	Image_Node_Item(std::istream*);
	~Image_Node_Item()override;
	static Node_Item* make(std::istream*);
private:
	Fl_Image* image= nullptr;
	void draw_body()const override;
	void scale(double)override;
	bool settle()override;
    void context_menu(std::vector<Fl_Menu_Item>& menu)override;
	
	static void change_image(Fl_Widget*,void*);
};
