#include "binary_save.h"
#include <map>

static std::map<const std::string, make_node_item_t> makefuncs;

void map_id_to_node_item(const std::string& name, make_node_item_t make){
	makefuncs[name]= make;
}
make_node_item_t get_node_item(const std::string& name){
	auto ret= makefuncs.find(name);
	if(ret != makefuncs.end())
		return ret->second;
	return nullptr;
}
