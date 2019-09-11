#include "type_manager.h"
#include <map>
#include <list>

/// Map every function name to its corresponding multimethod tree
std::map<const std::string, func_map_tree> multimethods;

/// All defined type names
std::list<std::string> typenames;

void add_type(const std::string& type){
	typenames.push_back(type);
}

int get_type_id(const std::string& type){
	int ret= 0;
	for(auto& t: typenames){
		if(t==type) return ret;
		ret++;
	}
	return -1;
}

void set_func(const std::string& name, func_t func, const std::vector<unsigned int>& types){
	const unsigned int types_count = typenames.size();
	if(multimethods.find(name) == multimethods.end())
		multimethods[name]= func_map_tree{nullptr, new func_map_tree[types_count]};
	func_map_tree* current= &multimethods.at(name);
	for(auto type : types){
		if(current->next == nullptr)
			current->next= new func_map_tree[types_count];
		current= &current->next[type];
	}
	current->func= func;
}

func_t get_func(const std::string& name, const std::vector<unsigned int>& types){
	if(multimethods.find(name) == multimethods.end())
		return nullptr;
	func_map_tree* current= &multimethods.at(name);
	for(auto type : types){
		if(current->next == nullptr)
			return nullptr;
		current= &current->next[type];
	}
	return current->func;
}
