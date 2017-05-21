/****************************************************************************
*  Antonio Santos
*  CSCI 271 Spring 2017
*	 Program 2 - Iter Class
****************************************************************************/
#ifndef ITER_H
#define ITER_H

#include <iostream>
#include "Node.h"

using namespace std;

template<class dtype>
class list; //class declaration

/******************************************************************************
*	class iter
*	encapsulates all the data variables, functions,
*	and overload operators to create an stl iterator-like
*	class
******************************************************************************/
template<class dtype>
class iter{
  private:
    Node<dtype>* iterator;
    int pos;
  public:
    iter(); //constructor

    const iter<dtype>& operator++(); //pre
    iter<dtype> operator++(int); //post
    const iter<dtype>& operator--(); //pre
    iter<dtype> operator--(int); //post
    iter<dtype>& operator=(const iter<dtype>&); //equal to overload
    bool operator!=(iter<dtype>); //not equal to overload
    dtype operator*(); //asterik overload

    friend class list<dtype>; //lets the list class be able to
                              //access all private and public
                              //parts of the iter class
};

//default constructor
template<class dtype>
iter<dtype>::iter(){
        iterator = NULL;
}

/******************************************************************************
*	operator overload ++
*	post increment. returns the item the iter is
*	pointing to and then moves to next one
******************************************************************************/
template<class dtype>
iter<dtype> iter<dtype>::operator++(int x){
	iter<dtype> temp = *this;
	++(*this);
	return temp;
}

/******************************************************************************
* operator overload ++
* pre increment. moves and returns the next item
*	the iter is pointing to
******************************************************************************/
template<class dtype>
const iter<dtype>& iter<dtype>::operator++(){
	iterator = iterator->getNext();
	return *this;
}

/******************************************************************************
*       operator overload --
*       pre decrement. returns the item the iter is
*       pointing to and then moves to previous one
******************************************************************************/
template<class dtype>
const iter<dtype>& iter<dtype>::operator--(){
  iterator = iterator->getPrev();
  return *this;
}

/******************************************************************************
*   operator overload --
*   post decrement. moves and returns the item
*	  the iter is pointing to
******************************************************************************/
template<class dtype>
iter<dtype> iter<dtype>::operator--(int x){
  iter<dtype> temp = *this;
  --(*this);
  return temp;
}

/******************************************************************************
*   operator overload *
*   dereferences iterator means to return the
*	  item in the node it is pointing to
******************************************************************************/
template<class dtype>
dtype iter<dtype>::operator*(){
	return iterator->getItem();
}

/******************************************************************************
*  operator overload =
*  copies the iterator pointers
******************************************************************************/
template<class dtype>
iter<dtype>& iter<dtype>::operator=(const iter<dtype>& rightIter){
	this->iterator = rightIter.iterator;
  return *this;
}

/******************************************************************************
*  operator overload !=
*  boolean statement that says if the iterator
*	 is equal to another iterator
******************************************************************************/
template<class dtype>
bool iter<dtype>::operator!=(iter<dtype> rightIter){
	if(*rightIter == *(*this))
		return false;
	else
		return true;
}

#endif
