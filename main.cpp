#include <iostream>
#include <algorithm>
#include <string>

#include <memory>


#include "radix/radixtree.h"



int main (int argc, char ** argv){


    std::unique_ptr<RadixTree> m_tree(new RadixTree());

    for(std::string line; std::getline(std::cin,line);){
        m_tree->insert(line);
    }

    m_tree->lookup();
    m_tree->look_for_shortest();
    return 0;
}
