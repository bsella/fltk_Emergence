#include <vector>
#include "core/node.h"
class NodeItem : public Node{
public:
	NodeItem(int x, int y, int w, int h, int n);
	virtual ~NodeItem();
	inline int x(){return _x;}
	inline int y(){return _y;}
	inline int w(){return _w;}
	inline int h(){return _h;}
private:
	int _x,_y, _w,_h;
	const int width, height;
	static NodeItem* hover;
	static int socket_hover, socket_x, socket_y;
	void draw()const;
	virtual void draw_body()const;
	int inside(int,int)const;
	bool inside(int,int,int,int)const;
	void set_pos(int,int);
	void move(int,int);
	void scale(float);
	friend class Workspace;
};
