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
#include <gui/workspace.h>
#include <gui/binary_save.h>

class Image_Plugin : public _Plugin{
public:
	void init()const override;
	void init_gui()const override;
};

CREATE_DESTROY_C(Image_Plugin)

void Image_Plugin::init()const{
	int real_id= get_type_id("real");
	set_func("get_pixel", &Image_Node::get_pixel, {(unsigned)real_id, (unsigned)real_id});
}
void Image_Plugin::init_gui()const{
	map_id_to_node_item("image", &Image_Node_Item::make);

	menu_bar->add("Insert/Other/Image", 0, &Workspace::insert, (void*)&Image_Node_Item::make);

	Toolbox_Category* cat= Toolbox::add_category("Other");
	cat->add(new Toolbox_Node_Item("Image",RELATIVE("plugins/image/image.png"),&Image_Node_Item::make));
}
