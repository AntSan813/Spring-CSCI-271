/*****************************************************************************
*  Antonio Santos
*  CSCI 271 - Spring 2017
*  Program 3 - Due 3/7/17
*  Customized binary sort tree.
*****************************************************************************/
#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template<typename elem>
class Node{
  private:
    Node<elem>* lChild;
    Node<elem>* rChild;
    int freq;
    elem data;

  public:
    //constructors
    Node();
    Node(elem,const int&);
    Node(elem, const int&, Node<elem>*, Node<elem>*);

    //setters
    void setrChild(Node<elem>*);
    void setlChild(Node<elem>*);
    void setItem(const elem&);
    void setFreq(const int&);

    //boolean function
    bool isLeaf();

    //getters
    Node<elem>* getrChild();
    Node<elem>* getlChild();
    elem getItem();
    int getFreq();
};

//default constructor
template<typename elem>
Node<elem>::Node(){
  lChild = NULL;
  rChild = NULL;
  freq = 0;
}

//leaf constructor
template<typename elem>
Node<elem>::Node(elem val, const int& f){
  data = val;
  freq = f;
  lChild = NULL;
  rChild = NULL;
}

//constructor for internal node
template<typename elem>
Node<elem>::Node(elem val, const int& f, Node<elem>* l, Node<elem>* r){
  data = val;
  freq = f;
  lChild = l;
  rChild = r;
}

//leaf checker
template<typename elem>
bool Node<elem>::isLeaf(){
  if((lChild == NULL) && (rChild == NULL))
    return true;
}

//set left child
template<typename elem>
void Node<elem>::setrChild(Node<elem>* x){
  rChild = x;
}

//set right child
template<typename elem>
void Node<elem>::setlChild(Node<elem>* x){
  lChild = x;
}

//set item
template<typename elem>
void Node<elem>::setItem(const elem& x){
	data = x;
}

//set freq
template<typename elem>
void Node<elem>::setFreq(const int& x){
  freq = x;
}

//get right
template<typename elem>
Node<elem>* Node<elem>::getrChild(){
  return rChild;
}

//get left
template<typename elem>
Node<elem>* Node<elem>::getlChild(){
  return lChild;
}

//get freq
template<typename elem>
int Node<elem>::getFreq(){
  return freq;
}

//get item
template<typename elem>
elem Node<elem>::getItem(){
  return data;
}

#endif
