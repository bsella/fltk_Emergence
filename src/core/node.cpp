#include "node.h"
Node::Node(int n){
    for(int i=0; i<n; i++)
        inodes.push_back(nullptr);
}
Node::~Node(){}
