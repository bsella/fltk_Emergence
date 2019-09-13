#pragma once
#include <vector>
#include <string>

class Node;

typedef void (*func_t)(Node**, void*);

struct func_map_tree{
	func_t func= nullptr;
	struct func_map_tree* next= nullptr;
};

/// Add type
void add_type(const std::string&);

/// Get type ID
int get_type_id(const std::string&);

/// Add/Modify multimethod
void set_func(const std::string&, func_t, const std::vector<unsigned int>&);

/// Get multimethod using its name and input types
func_t get_func(const std::string&, const std::vector<unsigned int>&);
