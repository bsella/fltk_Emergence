#include <vector>
#include "core/node.h"
class BaseNodeItem : public BaseNode{
public:
	BaseNodeItem(int x, int y, int w, int h, int n);
	virtual ~BaseNodeItem();
	inline int x(){return _x;}
	inline int y(){return _y;}
	inline int w(){return _w;}
	inline int h(){return _h;}
private:
	int _x,_y, _w,_h;
	const int width, height;
	static BaseNodeItem* hover;
	void draw()const;
	virtual void draw_body()const;
	bool inside(int,int)const;
	void set_pos(int,int);
	void move(int,int);
	void scale(float);
	friend class Workspace;
};
