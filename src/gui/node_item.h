#pragma once
#include <vector>
#include "gui/item.h"
#include "core/node.h"
class Fl_Menu_Item;
class Node_Item;
typedef Node_Item* (*make_node_item_t)(int,int,void*);

class Node_Item : public Item{
public:
	Node_Item(int x, int y, int w, int h, Node* n);
	virtual ~Node_Item();

	void draw()const;
	static make_node_item_t dnd_node_factory;
	void connect(int, Node_Item*);
	void disconnect(int);
	bool is_looping(Node_Item*)const;

protected:
	Node* core_node;
	virtual void context_menu(std::vector<Fl_Menu_Item>&);
	virtual bool inside(int,int)const;
	virtual void draw_body()const;

private:
	bool hover=false, selected=false;
	inline int input_size()const{return core_node->inodes.size();}
	inline bool hasOutput()const{return core_node->hasOutput;}
	std::vector<Node_Item*> inodes;
	static const int socket_size, head_size;
	static int socket_hover, socket_x, socket_y;
	static bool socket_drag;
	virtual unsigned int color()const;

	void mouse_enter_event(int,int)override;
	void mouse_leave_event()override;
	void mouse_move_event(int,int)override;
	void mouse_click_event(int,int,int)override;

	virtual bool settle();

	friend class Workspace;
};
