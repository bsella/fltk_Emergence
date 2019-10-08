#include <../plugins/plugin.h>
#include <core/type_manager.h>
#include "complex_t.h"

class Complex_t_Plugin : public _Plugin{
public:
	void init()const override;
};

CREATE_DESTROY_C(Complex_t_Plugin)

void Complex_t_Plugin::init()const{
	unsigned int complex_id= get_type_id("complex");
	set_func("to_color", &Complex_t::to_color, {complex_id});
}
