#include <../plugins/plugin.h>
#include <core/type_manager.h>
#include "real_t.h"

unsigned int real_id;

class Real_t_Plugin : public _Plugin{
public:
	void init()const override;
};

CREATE_DESTROY_C(Real_t_Plugin)

void Real_t_Plugin::init()const{
	add_type("real");
	real_id= get_type_id("real");
}
