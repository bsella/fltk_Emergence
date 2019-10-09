#include <core/node.h>
#include <vector>
class Fl_Shared_Image;

class Image_Node : public Node{
public:
	Image_Node(const char*);
    ~Image_Node()override;
	void set_image(const char*);
	static Node* make(void*);
	static void get_pixel(Node**, void*);
	Fl_Shared_Image* image= nullptr;
private:
	void update_types()override;
	void update_cache()override;
};
