#pragma once
#include <vector>
#include <gui/item.h>
#include <core/node.h>
class Fl_Menu_Item;
class Node_Item;

class Node_Item : public Item{
public:
	Node_Item(double w, double h, Node* n);
	virtual ~Node_Item();

	void draw()const override;
	void connect(int, Node_Item*);
	void disconnect(int);
	void disconnect_all();
	bool is_looping(Node_Item*)const;
	inline Data_t* cache(){return core_node->cache;}
	virtual void scale(double);

	void save(std::ostream&)const;

protected:
	Node* core_node;
	virtual void context_menu(std::vector<Fl_Menu_Item>&);
	virtual bool inside(int,int)const override;
	virtual void draw_body()const;

private:
	double pos_x, pos_y;
	const double width, height;
	bool hover=false, selected=false;
	inline int input_size()const{return core_node->inodes.size();}
	inline bool hasOutput()const{return core_node->hasOutput;}
	std::vector<Node_Item*> inodes;
	std::list<Node_Item*> onodes;
	static const int socket_size, head_size;
	static int socket_hover, socket_x, socket_y;
	static bool socket_drag;
	virtual unsigned int color()const;

	void mouse_enter_event(int,int)override;
	void mouse_leave_event()override;
	void mouse_move_event(int,int)override;

	virtual bool settle();

	friend class Workspace;
};
