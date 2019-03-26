#pragma once
#include <vector>
#include "core/node.h"
#include "gui/item.h"
class NodeItem : public Node, public Item{
public:
	NodeItem(int x, int y, int w, int h, int n);
	virtual ~NodeItem();

	void draw()const;
protected:
	virtual bool inside(int,int)const;

private:
	static int socket_hover, socket_x, socket_y;
	virtual void draw_body()const;

	void mouse_enter_event()override;
	void mouse_leave_event()override;
	bool mouse_press_event(int,int)override;
	void mouse_move_event(int,int)override;
	void mouse_release_event()override;

	friend class Workspace;
};
