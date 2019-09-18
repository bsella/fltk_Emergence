#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <gui/toolbox/toolbox_node_item.h>
#include <gui/toolbox/toolbox_category.h>
#include <FL/Fl_Menu_Bar.H>
#include "image_node.h"
#include "image_node_item.h"
#include <resources.h>
#include <core/type_manager.h>

class Image_Plugin : public _Plugin{
public:
	void init()const override;
	void init_gui(Main_Window*)const override;
};

CREATE_DESTROY_C(Image_Plugin)

void Image_Plugin::init()const{
	int real_id= get_type_id("real");
	set_func("get_pixel", &Image_Node::get_pixel, {(unsigned)real_id, (unsigned)real_id});
}
void Image_Plugin::init_gui(Main_Window*)const{
	Toolbox_Category* cat= Toolbox::add_category("Other");
	cat->add(new Toolbox_Node_Item("Image",RELATIVE("plugins/image/image.png"),&Image_Node_Item::make));
}