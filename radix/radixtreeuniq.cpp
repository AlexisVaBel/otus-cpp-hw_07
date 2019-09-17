#include "radixtreeuniq.h"


#include <iostream>
#include <strhelper.h>
#include <cstring>

RadixTreeUniq::RadixTreeUniq()
{
    m_root = std::unique_ptr<RadixUnique>(nullptr);
}

void RadixTreeUniq::push_back(std::string str)
{
    if(m_root.get() == nullptr){
        m_root = std::unique_ptr<RadixUnique>(new RadixUnique());        
        m_root->m_lbl = str;
        m_root->is_end = 1;
    }else
        push_to_node(m_root.get(), str, 1);
}


void RadixTreeUniq::push_to_node(RadixUnique *node, std::string str, int iend)
{
    if(str.empty()) return;
    if( !m_root->m_lbl.empty()){
        node->addChild(get_head_str(m_root->m_lbl), m_root->m_lbl, 1);
        m_root->is_end = 0;
        m_root->m_lbl.clear();
    };

    auto existNode = node->getNode(get_head_str(str));
    if(existNode != nullptr ){
        if(!existNode->m_lbl.empty()){
            std::string strExist    = existNode->m_lbl;

            std::string strMathced  = get_matched(strExist,str);
            std::string strMiss1    = get_mismatched(strExist,str);
            std::string strMiss2    = get_mismatched(str,strExist);

            existNode->m_lbl.clear();
            existNode->m_lbl = strMathced;

            if(!strMiss1.empty()){


                // grab all childs from existNode

                auto chlds =std::move (existNode->m_childs);
                push_to_node(existNode, strMiss1, existNode->is_end);
                if(!chlds.empty()) {
                    std::swap(existNode->getNode(get_head_str(strMiss1))->m_childs,chlds);                    
                }
            };

            if( !strMiss1.empty() &&  !strMiss2.empty() &&  !strMathced.empty() && (strMathced.compare(str) != 0) ){
                existNode->is_end = 0;
            }
            else
                if( (strMathced.compare(str) == 0) ){
                    existNode->is_end = 1;
                }
            push_to_node(existNode, strMiss2, 1);
            return;
        }
    }

    node->addChild(get_head_str(str), str, iend);

}


void RadixTreeUniq::lookup()
{
    travers_tree(m_root.get(),0);
}

void RadixTreeUniq::print_with_shorts()
{
    travers_by_name(m_root.get(),"");
}

void RadixTreeUniq::travers_tree(RadixUnique* node, int iDepth)
{
    if(node == nullptr) return;
    if(!node->m_lbl.empty()) {
        auto iDotPrint = iDepth;
        while(iDotPrint > 0){
            std::cout <<"-";
            --iDotPrint;
        }
        std::cout <<"+"<< node->m_lbl;
        if(node->is_end) std::cout << "$";
        std::cout<< std::endl;
    }

    for (auto i = 0 ; i < MAX_CNT_CHILDS; ++i) {
      travers_tree(node->m_childs[i].get(),iDepth + 1);
    };
}

void RadixTreeUniq::travers_by_name(RadixUnique *node, std::string accum)
{    
    if(node == nullptr) return;

    if(node->is_end){        
        std::cout << accum << node->m_lbl;
        if(!node->hasChildren())
            std::cout<< " " << accum << get_head_str(node->m_lbl);
        else
            std::cout<< " " << accum << node->m_lbl;
        std::cout << std::endl;
    }        
    for (size_t i = 0 ; i < MAX_CNT_CHILDS; ++i) {
      travers_by_name(node->m_childs[i].get(),accum+node->m_lbl);
    };
}

