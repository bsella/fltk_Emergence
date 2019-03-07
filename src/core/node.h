#include <vector>
class BaseNode{
public:
	BaseNode(int);
	~BaseNode();
protected:
    std::vector<BaseNode*> inodes;
};
