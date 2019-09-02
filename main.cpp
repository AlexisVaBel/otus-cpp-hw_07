#include <iostream>
#include <algorithm>
#include <string>

#include <memory>


#include "radix/radixtree.h"
#include "radix/radixtreeuniq.h"



int main (int argc, char ** argv){


    // array implementation
    std::unique_ptr<RadixTreeUniq> m_tree(new RadixTreeUniq());

    for(std::string line; std::getline(std::cin,line);){
        line.erase(std::remove_if(line.begin(),
                                  line.end(),
                                  [](unsigned char x){return std::isspace(x);}),
                   line.end());
        std::transform(line.begin(), line.end(), line.begin(),
            [](unsigned char c){ return std::tolower(c); });
        m_tree->push_back(line);
    }

    m_tree->lookup();
    m_tree->print_with_shorts();

    // list implementation
//    std::unique_ptr<RadixTree> m_tree(new RadixTree());

//    for(std::string line; std::getline(std::cin,line);){
//        m_tree->insert(line);
//    }

//    m_tree->lookup();
//    m_tree->look_for_shortest();
    return 0;
}
