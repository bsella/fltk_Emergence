#pragma once
#include <gui/node_item.h>
class Fl_Image;

class Image_Node_Item : public Node_Item{
public:
	Image_Node_Item(int,int, const char*);
	~Image_Node_Item()override;
	static Node_Item* make(int,int,void*);
	void set_image(const char*);
private:
	Fl_Image* image= nullptr;
	void draw_body()const override;
	void scale(float s)override;
	bool settle()override;
	void context_menu(std::vector<Fl_Menu_Item>& menu);
};
