#ifndef NODE_H
#define NODE_H

namespace radixnode {

struct node{
    char *label;
    int  is_end;
    node *childs;
};

}

#endif // NODE_H
