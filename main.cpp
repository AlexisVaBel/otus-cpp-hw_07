#include <iostream>
#include <algorithm>
#include <string>

#include <memory>


#include "radix/radixtreeuniq.h"



int main (int argc, char ** argv){

    std::unique_ptr<RadixTreeUniq> m_tree(new RadixTreeUniq());

    for(std::string line; std::getline(std::cin,line);){
        m_tree->push_back(line);
    }

    m_tree->lookup();
    m_tree->print_with_shorts();


    return 0;
}
