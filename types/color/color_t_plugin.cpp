#include <../plugins/plugin.h>
#include <core/type_manager.h>
#include "color_t.h"

class Color_t_Plugin : public _Plugin{
public:
	void init()const override;
};

CREATE_DESTROY_C(Color_t_Plugin)

void Color_t_Plugin::init()const{
	add_type("color");
	unsigned int color_id= get_type_id("color");
	set_func("to_color", &Color_t::to_color, {color_id});
}
