#ifndef RADIXTREE_H
#define RADIXTREE_H

#include "rdxlistnode.h"
using namespace rdxlistnode;

class RadixTree
{
public:
    RadixTree();
    ~RadixTree();

    void insert(std::string str);
    void lookup();
    void look_for_shortest();
    std::string find_short(std::string str);
private:
    void insert(RdxListNode* nd, std::string str);
    void traverse(RdxListNode *node,int iDepth);
    std::string look_for_shortest(RdxListNode *node, std::string str);

    std::string travers_short(RdxListNode *node, std::string str, std::string strAccum);

    RdxListNode *m_rootNode;
};

#endif // RADIXTREE_H
