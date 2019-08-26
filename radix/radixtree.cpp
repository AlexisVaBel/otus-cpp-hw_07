#include "radixtree.h"

#include "strhelper.h"

#include <iostream>

RadixTree::RadixTree():m_rootNode(nullptr)
{

}

RadixTree::~RadixTree()
{
    delete m_rootNode;
}

void RadixTree::insert(std::string str)
{
    insert(m_rootNode, str);
}


void RadixTree::insert(RdxListNode *nd, std::string str)
{
    if(str.empty())return;
    if(m_rootNode == nullptr) {
        m_rootNode = new RdxListNode(str);
        return;
    }
    if(! m_rootNode->m_ptrLabel.empty() ){
        m_rootNode->insertSister(new RdxListNode(m_rootNode->m_ptrLabel));
        m_rootNode->m_ptrLabel.clear();
        m_rootNode->is_end = 0;
    }

    auto node       = nd;
    auto nodeNext   = nd;
    auto tmpStr     = str;
    while (node != nullptr) {


        if(node->getSister(tmpStr) == nullptr) break;
        nodeNext = node->getSister(tmpStr);

        std::string strMatch = get_matched(nodeNext->m_ptrLabel, tmpStr);
        std::string strMiss1 = get_mismatched(nodeNext->m_ptrLabel, tmpStr);
        std::string strMiss2 = get_mismatched(tmpStr,nodeNext->m_ptrLabel);
        if(!strMatch.empty()){
            if(strMatch.compare(nodeNext->m_ptrLabel) == 0){
                nodeNext->is_end = 0;
                insert(nodeNext, strMiss1.empty() ? strMiss2 : strMiss1);
                return;
            }else{
                auto prntNode = nodeNext;
                node->removeSister(nodeNext);
                node = node->insertSister(new RdxListNode(strMatch));
                node->is_end = 0;
                prntNode->m_ptrLabel = strMiss1;
                node->insertSister(new RdxListNode(strMiss2));
                node->insertSister(prntNode);
            return;
            }
        }else
            tmpStr = get_tail_str(tmpStr);
    }

    node->insertSister(new RdxListNode(str));
}


void RadixTree::lookup()
{
    traverse(m_rootNode,-1);
}

void RadixTree::look_for_shortest()
{
    look_for_shortest(m_rootNode,"");
}

std::string RadixTree::find_short(std::string str)
{
    return travers_short(m_rootNode, str, "");
}


void RadixTree::traverse(RdxListNode *node,int iDepth)
{
    if(node == nullptr) return;
    auto itmp = iDepth;
    while (itmp > 0) {
        std::cout << "| ";
        --itmp;
    }

    if(!node->m_ptrLabel.empty())std::cout <<"+"<< node->m_ptrLabel;
    if (node->is_end == 1) std::cout << "$" ;
    std::cout << std::endl;
    auto it = node->m_sisters.begin();
    while(it != node->m_sisters.end()){
        traverse(*it,iDepth+1);
        ++it;
    }
}

std::string RadixTree::look_for_shortest(RdxListNode *node, std::string str){

    if(node == nullptr) return  str;
    if(node->is_end == 1) std::cout << str <<" "<< find_short(str) << std::endl;
    auto it     = node->m_sisters.begin();
    auto itend  = node->m_sisters.end();
    while(it != itend){
        look_for_shortest(*it, str+(*it)->m_ptrLabel);
        ++it;
    }
    return "";
}


std::string RadixTree::travers_short(RdxListNode *node, std::string str, std::string strAccum)
{
    if(node == nullptr || str.empty()) return strAccum;
    if(node->hasNoSister()) return str;
    if(node->getSister(str) != nullptr){
        node = node->getSister(str);
        if(node->hasNoSister() && node->m_ptrLabel.compare(str) == 0) return strAccum.append(node->m_ptrLabel.substr(0,1));
        return travers_short(node, get_mismatched(str,node->m_ptrLabel), strAccum.append(node->m_ptrLabel) );
    }else {
        return  strAccum;
    }
}
