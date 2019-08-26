#ifndef RDXLISTNODE_H
#define RDXLISTNODE_H

#include <string>
#include <list>

#include <strhelper.h>

#include <iostream>

namespace rdxlistnode {



struct RdxListNode{

   int is_end;
   std::string m_ptrLabel;

   std::list<RdxListNode *>  m_sisters; //


   RdxListNode(std::string str):m_ptrLabel(str), is_end(1){

   }

   ~RdxListNode(){
       auto it = m_sisters.begin();
       while( it != m_sisters.end() ){
           auto toDelete = *it;
           ++it;
           delete toDelete;
       }
   }


   RdxListNode * insertSister(RdxListNode *node){
       m_sisters.push_back(node);
       return node;
   }


   RdxListNode * getSister(std::string str){
       auto it = m_sisters.begin();
       while(it != m_sisters.end()){
           if(!(get_matched((*it)->m_ptrLabel,str)).empty()) return (*it);
           ++it;
       }
       return nullptr;
   }



   void removeSister(RdxListNode *node){
       m_sisters.remove(node);
   }

   bool hasNoSister(){
       return m_sisters.begin() == m_sisters.end();
   }

};

}
#endif // RDXLISTNODE_H
