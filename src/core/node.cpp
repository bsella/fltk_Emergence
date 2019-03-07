#include "node.h"
BaseNode::BaseNode(int n){
    for(int i=0; i<n; i++)
        inodes.push_back(nullptr);
}
BaseNode::~BaseNode(){}
