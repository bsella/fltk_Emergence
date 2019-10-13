#include <core/node.h>
#include <vector>
class Fl_Shared_Image;

class Image_Node : public Node{
public:
	Image_Node(std::istream*);
    ~Image_Node()override;
	void set_image(const char*);
	static Node* make(std::istream*);
	static void get_pixel(Node**, void*);
	Fl_Shared_Image* image= nullptr;
private:
	void update_types()override;
	void update_cache()override;
	inline const char* id()const override;
};
