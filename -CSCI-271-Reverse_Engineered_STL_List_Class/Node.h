/****************************************
*       Antonio Santos
*       CSCI 271 Spring 2017
*	Program 2 - Node Class
****************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

/****************************************
*	class node
*	encapsulates all data variables, functions, 
*	and constructors to create an stl-like
*	doubly linked list node class
****************************************/
template<class dtype>
class Node{
        private:
                dtype data;
                Node* next;
		Node* previous;
        public:
                Node(); // constructor

		//setters
                void setItem(dtype x);
                void setNext(Node* x);
		void setPrev(Node* x);

		//getters
		Node<dtype>* getPrev();
                Node<dtype>* getNext();
                dtype getItem();
};

/****************************************
*	default constructor 
*	creats the node with null pointers
*
****************************************/
template<class dtype>
Node<dtype>::Node(){
        next = NULL;
	previous = NULL;
}

/****************************************
*	void setItem(x)
*	sets item 
*
****************************************/
template<class dtype>
void Node<dtype>::setItem(dtype x){
        data = x;
}

/****************************************
*	void setNext(x)
*	sets next pointer
*
****************************************/
template<class dtype>
void Node<dtype>::setNext(Node* x){
        next = x;
}

/****************************************
*	Node* getNext()
*	returns the next pointer
*
****************************************/
template<class dtype>
Node<dtype>* Node<dtype>::getNext(){
        return next;
}

/****************************************
*	void setPrev(x)
*	sets previous pointer 
*
****************************************/
template<class dtype>
void Node<dtype>::setPrev(Node* x){
	previous = x;
}

/****************************************
*	Node* getPrev()
*	returns previous pointer
*
****************************************/
template<class dtype>
Node<dtype>* Node<dtype>::getPrev(){
	return previous;
}

/****************************************
*	dtype getItem()
*	returns the item that is inside the node
*
****************************************/

template<class dtype>
dtype Node<dtype>::getItem(){
        return data;
}

#endif
