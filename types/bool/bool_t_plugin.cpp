#include <../plugins/plugin.h>
#include <core/type_manager.h>
#include "bool_t.h"

class Bool_t_Plugin : public _Plugin{
public:
	void init()const override;
};

CREATE_DESTROY_C(Bool_t_Plugin)

void Bool_t_Plugin::init()const{
	unsigned int bool_id= get_type_id("bool");
    set_func("to_color", &Bool_t::to_color, {bool_id});
	set_func("to_bool", &Bool_t::to_bool, {bool_id});
}
