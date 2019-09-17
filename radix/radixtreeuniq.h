#ifndef RADIXTREEUNIQ_H
#define RADIXTREEUNIQ_H

#include "radixunique.h"

using namespace radixnode_un;


class RadixTreeUniq
{
public:
    RadixTreeUniq();

    void push_back(std::string str);
    void lookup();
    void print_with_shorts();


    std::unique_ptr<RadixUnique> m_root;
private:

    void travers_tree(RadixUnique *node, int iDepth);

    void travers_by_name(RadixUnique *node, std::string accum);

    void push_to_node(RadixUnique *node, std::string str, int iend);
};

#endif // RADIXTREEUNIQ_H
