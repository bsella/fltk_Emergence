#pragma once
#include <istream>
#include <string>
class Node_Item;

typedef Node_Item* (*make_node_item_t)(std::istream*);

void map_id_to_node_item(const std::string&, make_node_item_t);
make_node_item_t get_node_item(const std::string&);
