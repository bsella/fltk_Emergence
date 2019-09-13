#include <../plugins/plugin.h>
#include <core/type_manager.h>
#include "real_t.h"

class Real_t_Plugin : public _Plugin{
public:
	void init()const override;
};

CREATE_DESTROY_C(Real_t_Plugin)

void Real_t_Plugin::init()const{
	unsigned int real_id= get_type_id("real");
	set_func("to_color", &Real_t::to_color, {real_id});
	set_func("to_bool", &Real_t::to_bool, {real_id});
}
