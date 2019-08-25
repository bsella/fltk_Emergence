#include "data_t.h"
#include <stdlib.h>

Data_t::~Data_t(){}

std::map<const std::string, func_map_tree> Data_t::func_dictionary;

void Data_t::add_func(const std::string& name, void (*func)(Node**, void*), const std::vector<std::type_index>& types){
	if(func_dictionary.find(name) == func_dictionary.end())
		func_dictionary[name]= func_map_tree{nullptr, std::map<std::type_index, struct func_map_tree>()};
	func_map_tree* current= &func_dictionary.at(name);
	for(auto type : types){
		if(current->next.find(type) == current->next.end())
			current->next[type]= func_map_tree{nullptr, std::map<std::type_index, struct func_map_tree>()};
		current= &current->next[type];
	}
	current->func= func;
}

void (*Data_t::get_func(const std::string& name, const std::vector<std::type_index>& types))(Node**, void*) {
	if(func_dictionary.find(name) == func_dictionary.end())
		return nullptr;
	func_map_tree* current= &func_dictionary.at(name);
	for(auto type : types){
		if(current->next.find(type) == current->next.end())
			return nullptr;
		current= &current->next[type];
	}
	return current->func;
}
