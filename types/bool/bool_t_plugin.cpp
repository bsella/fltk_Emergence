#include <../plugins/plugin.h>
#include <core/type_manager.h>
#include "bool_t.h"

class Bool_t_Plugin : public _Plugin{
public:
	void init()const override;
};

CREATE_DESTROY_C(Bool_t_Plugin)

void Bool_t_Plugin::init()const{
	add_type("bool");
}
