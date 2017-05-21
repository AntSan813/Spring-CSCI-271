/******************************************************************************
*   Antonio Santos
*   CSCI 271 Spring 2017
*   Program 2 - List Class
*******************************************************************************/
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"

template<class dtype>
class iter;

/******************************************************************************
*	 Class: list
*	 Description: encapsulates functions, an equal to overlaod, constructors and
*  data variables	to create an stl-like doubly linked list
******************************************************************************/
template<class dtype>
class list{
  private:
    //data variables
    //dtype data;
    int list_counter;

    //Node pointers
    Node<dtype>* head;
    Node<dtype>* trailer;
  public:
    //constructors
    list();
    list(list<dtype>&);

    //list functions
    bool empty(); //true if no items in list
    int size(); //returns list counter
    void erase(iter<dtype>&);//erases a position in list
    void clear(); //cleans list

    //insert functions
    void push_back(dtype); //inputs item in back
    void push_front(dtype); //inputs item in front

    void show_list(); //displays list

    //return functions
    dtype pop_front(); //returns first item and removes it
    dtype pop_back(); //returns last item and removes it
    dtype front(); //returns first item
    dtype back(); //returns last item
    iter<dtype> begin(); //returns iterator to position after head
    iter<dtype> end(); //returns iterator to trailer node (back plus one)

    //equal to overload
    void operator=(list<dtype>&);

    ~list();//deconstructor
};

//templated constructor
template<class dtype>
list<dtype>::list(){
  head = new Node<dtype>;
  trailer = new Node<dtype>;
  list_counter = 0;
  head->setNext(trailer);
  trailer->setPrev(head);
}

//copy constructor
template<class dtype>
  list<dtype>::list(list<dtype>& otherL){
  trailer = new Node<dtype>;
  head = new Node<dtype>;
  head->setNext(trailer);
  trailer->setPrev(head);
  list_counter = 0;

  Node<dtype>* holder = otherL.head->getNext();

  //copies the list and pushes into new list
  if(!otherL.empty()){
    while(holder->getItem() != otherL.trailer->getItem()){
      this->push_back(holder->getItem());
      holder = holder->getNext();
    }
  }
}

/******************************************************************************
*	list empty()
*	returns true if the list is empty, false if
*	otherwise
*****************************************************************************/
template<class dtype>
bool list<dtype>::empty(){
  if(head->getNext() == trailer)
    return true;
  else
    return false;
}

/******************************************************************************
*	list push_front(obj)
*	inserts a new node object into the beginning of the
*	list
******************************************************************************/
template<class dtype>
void list<dtype>::push_front(dtype obj){
  list_counter++;
  Node<dtype>* newObj = new Node<dtype>;
  newObj->setItem(obj);
  newObj->setNext(head->getNext());
  newObj->setPrev(head);

  if(list_counter == 1){
    head->setNext(newObj);
    trailer->setPrev(newObj);
  }
  else{
    head->getNext()->setPrev(newObj);
    head->setNext(newObj);
  }
}

/*****************************************************************************
*  list push_back(obj)
*  inserts a new node object into the end of the list
*****************************************************************************/
template<class dtype>
void list<dtype>::push_back(dtype obj){
  list_counter++;
  Node<dtype>* newObj = new Node<dtype>;
  newObj->setItem(obj);
  newObj->setNext(trailer);
  newObj->setPrev(trailer->getPrev());

  if(list_counter == 1){
    head->setNext(newObj);
    trailer->setPrev(newObj);
  }
  else{
    trailer->getPrev()->setNext(newObj);
    trailer->setPrev(newObj);
  }
}

/******************************************************************************
*	  list size()
*	  returns the counter
******************************************************************************/
template<class dtype>
int list<dtype>::size(){
  return list_counter;
}

/******************************************************************************
*	  list show_list()
*	  displays the list contents
******************************************************************************/
template<class dtype>
void list<dtype>::show_list(){
  int i = 1;
  Node<dtype> temp;
  temp = head->getNext();
  while(temp->getItem() != trailer->getItem()){
    cout << "item " << i << ": " << *temp << endl;
    i++;
    temp = temp->getNext();
  }
}

/****************************************
*	list pop_front()
*	returns and deletes the first item in the
*	list (if any)
****************************************/
template<class dtype>
dtype list<dtype>::pop_front(){
	//emptiness check
	if(this->empty()){
  	cout << "LIST IS EMPTY" << endl;
    throw 99;
	}

	else{//if not empty, then pop the front and fixate the pointers
    Node<dtype>* temp;
    dtype popped;
    temp = head->getNext();
    popped = temp->getItem();
    head->setNext(temp->getNext());
    delete temp;
    temp = NULL;
    list_counter--;
    return popped;
 	}
}

/******************************************************************************
*   list pop_back()
*   returns and deletes the last item in the list (if any)
******************************************************************************/
template<class dtype>
dtype list<dtype>::pop_back(){
	//emptiness checker
  if(this->empty()){
    cout << "LIST IS EMPTY" << endl;
    throw 99;
  }
  else{
    Node<dtype>* temp;
    dtype popped;
    temp = trailer->getPrev();
    popped = temp->getItem();
    trailer->setPrev(temp->getPrev());
    delete temp;
    temp = NULL;
    list_counter--;
    return popped;
  }
}

/******************************************************************************
*	list clear()
*	clears all items is in the list
******************************************************************************/
template<class dtype>
void list<dtype>::clear(){
  Node<dtype>* holder;
  holder = head->getNext();

  while(holder->getItem() != trailer->getItem()){
    delete holder;
    holder = holder->getNext();
    head->setNext(holder);
    list_counter--;
  }

  head->setNext(trailer);
  trailer->setPrev(head);
}

/******************************************************************************
*	void erase(it)
*	erases an item in a list at a given iterator
*	position
******************************************************************************/
template<class dtype>
void list<dtype>::erase(iter<dtype>& it){
	Node<dtype>* temp = it.iterator->getNext();
	it.iterator->getNext()->setPrev(it.iterator->getPrev());
	it.iterator->getPrev()->setNext(it.iterator->getNext());
	list_counter--;
	it.iterator = temp;
}

/*****************************************************************************
*	dtype front()
*	returns the item of the first item in the list
*****************************************************************************/
template<class dtype>
dtype list<dtype>::front(){
  return head->getNext()->getItem();
}

/******************************************************************************
*	dtype back()
*	returns the item of the last item in the list
*
******************************************************************************/
template<class dtype>
dtype list<dtype>::back(){
  return trailer->getPrev()->getItem();
}

/******************************************************************************
*	iter begin()
*	returns the iterator to the first item in the list
******************************************************************************/
template<class dtype>
iter<dtype> list<dtype>::begin(){
	iter<dtype> beginIter;
	beginIter.iterator = head->getNext();
	return beginIter;
}

/******************************************************************************
*	iter end()
*	returns the iterator to the trailer node pointer
******************************************************************************/
template<class dtype>
iter<dtype> list<dtype>::end(){
	iter<dtype> endIter;
	endIter.iterator = trailer;
	return endIter;
}

/******************************************************************************
*	deconstructor
*	deletes everything in list
******************************************************************************/
template<class dtype>
list<dtype>::~list(){
	Node<dtype>* temp;
	Node<dtype>* holder;
	temp = head->getNext();
	while(temp->getItem() != trailer->getItem()){
		holder = temp->getNext();
		delete temp;
		temp = holder;
		list_counter--;
	}
	delete head;
	delete trailer;
}

/******************************************************************************
*	overload operator=
*	overloads the equal to operator/ copies a list into another list
******************************************************************************/
template<class dtype>
void list<dtype>::operator=(list<dtype> &oldL){
	this->clear();
	
	iter<dtype> it = oldL.begin();
	while(it != oldL.end()){
		this->push_back(*it);
		it++;
	}
}

#endif
