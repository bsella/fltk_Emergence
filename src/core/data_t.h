#pragma once
#include <string>
#include <typeindex>
#include <vector>
#include <map>
class Node;

struct func_map_tree{
	void (*func)(Node**, void*);
	std::map<std::type_index, struct func_map_tree> next;
};

class Data_t{
public:
	static void add_func(const std::string&, void (*)(Node**, void*), const std::vector<std::type_index>&);
	static void (*get_func(const std::string&, const std::vector<std::type_index>&))(Node**, void*) ;
	static std::map<const std::string, func_map_tree> func_dictionary;
	virtual unsigned to_color()const=0;
	virtual ~Data_t();
};
