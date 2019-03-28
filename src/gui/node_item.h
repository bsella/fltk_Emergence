#pragma once
#include <vector>
#include "core/node.h"
#include "gui/item.h"
#include <FL/fl_draw.H>
class NodeItem : public Node, public Item{
public:
	NodeItem(int x, int y, int w, int h, int n);
	virtual ~NodeItem();

	void draw()const;
protected:
	virtual bool inside(int,int)const;

private:
	static const int socket_size, head_size;
	static int socket_hover, socket_x, socket_y;
	static bool socket_drag;
	virtual Fl_Color color()const;
	virtual void draw_body()const;

	void mouse_enter_event(int,int)override;
	void mouse_leave_event()override;
	void mouse_press_event(int,int)override;
	void mouse_move_event(int,int)override;
	void mouse_release_event()override;

	friend class Workspace;
};
