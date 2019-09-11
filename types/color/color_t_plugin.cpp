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
}
