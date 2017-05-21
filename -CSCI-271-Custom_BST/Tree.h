/*****************************************************************************
*  Antonio Santos
*  CSCI 271 - Spring 2017
*  Program 3 - Due 3/7/17
*  Customized binary sort tree.
*****************************************************************************/
#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

template<typename elem>
class Tree{
  private:
    Node<elem>* root;
    int treeCounter ;
    bool exists;

  public:
    //constructors
    Tree();
    Tree(const elem& val, int freq);
    ~Tree();

    //insert functions
    void insert(const elem&);
    Node<elem>* insertHelp(Node<elem>*, const elem&);

    //remove functions
    elem remove(const elem&);
    Node<elem>* removeHelp(Node<elem>*, const elem&);

    //find functions
    bool find(const elem&);
    elem findHelp(Node<elem>*, const elem&);

    //getmin && delete min functions
    Node<elem>* getMin(Node<elem>*);
    Node<elem>* deleteMin(Node<elem>*);

    //print functions
    void print_whole();
    void printHelp(Node<elem>*);

    //clear functions
    void clear();
    void clearHelp(Node<elem>*);

    //size
    int getSize();

    //---traverses---
    //inorder
    void inorder(void (*func)(elem));
    void inorderHelp(Node<elem>*, void (*func)(elem));

    //postorder
    void postorder(void (*func)(elem));
    void postorderHelp(Node<elem>*, void (*func)(elem));

    //preorder
    void preorder(void (*func)(elem));
    void preorderHelp(Node<elem>*, void (*func)(elem));
};

//default
template<typename elem>
Tree<elem>::Tree(){
  root = NULL;
  treeCounter = 0;
}

//leaf node constructor
template<typename elem>
Tree<elem>::Tree(const elem& val, int freq){
  root = new Node<elem>(val, freq);
  treeCounter = 1;
}

//deconstructor
template<typename elem>
Tree<elem>::~Tree(){
  this->clear();
}

//returns tree node counter
template<typename elem>
int Tree<elem>::getSize(){
  return treeCounter;
}

//gets the left-most node, which is the min of subtree
template<typename elem>
Node<elem>* Tree<elem>::getMin(Node<elem>* root){
	if(root->getlChild() == NULL)
		  return root;
	else return getMin(root->getlChild()); //keep going left
}

//deletes the leftmost node, which is the min of subtree
template<typename elem>
Node<elem>* Tree<elem>::deleteMin(Node<elem>* root){
  if(root->getlChild() == NULL) //when min is found
    return root->getrChild();
  else{	//go left
    root->setlChild(deleteMin(root->getlChild()));
    return root;
  }
}

//calls print help function
template<typename elem>
void Tree<elem>::print_whole(){
	 printHelp(this->root);
}

//prints tree inorder
template<typename elem>
void Tree<elem>::printHelp(Node<elem>* root){
  if(root == NULL)
    return;
  printHelp(root->getlChild());//keep going left until
  cout << root->getItem() << "   " << root->getFreq() << endl;
  printHelp(root->getrChild());
}

/******************************************************************
*       Function - clear
*       calls clearHelp function if tree has nodes
******************************************************************/
template<typename elem>
void Tree<elem>::clear(){
  if(root == NULL)
    cout << "\nData set is already empty. \n";
  else{
    clearHelp(this->root);
    cout << "\nHave a nice day!! \n"; //adios message
  }
}

/******************************************************************
*       Function - clearHelp
*       retores tree in a postorder traversal
******************************************************************/
template<typename elem>
void Tree<elem>::clearHelp(Node<elem>* root){
  if(root == NULL)
    return;
  clearHelp(root->getlChild()); //check left
  clearHelp(root->getrChild()); //check right
  delete root;
  treeCounter--;
}

/****************************************************************
*       Function - insert
*       calls insert help function
******************************************************************/
template<typename elem>
void Tree<elem>::insert(const elem& newItem){
  this->root = insertHelp(this->root, newItem);
}

/******************************************************************
*       Function - insertHelp
*       Finds appropriate place in tree to insert new value
******************************************************************/
template<typename elem>
Node<elem>* Tree<elem>::insertHelp(Node<elem>* root, const elem& newItem){
  if(root == NULL){ // if empty, add new node
    treeCounter++;
    return new Node<elem>(newItem, 1);
  }

  if(newItem > root->getItem()) //go right if new val is >
    root->setrChild(insertHelp(root->getrChild(), newItem));

  else if(newItem < root->getItem()) //go left is new val is <
    root->setlChild(insertHelp(root->getlChild(), newItem));

  else
    root->setFreq(root->getFreq() + 1);
}

/******************************************************************
*       Function - find
*       calls findhelp function
******************************************************************/
template<typename elem>
bool Tree<elem>::find(const elem& target){
    return findHelp(this->root, target);
}

/******************************************************************
*       Function - findHelp
*       Finds where a value is and returns it
******************************************************************/
template<typename elem>
elem Tree<elem>::findHelp(Node<elem>* root, const elem& target){
  if(root == NULL){ //empty tree
    exists = false;
    return NULL;
  }

  if(target < root->getItem()) //go left
    return findHelp(root->getlChild(), target);

  else if(target > root->getItem()) //go right
    return findHelp(root->getrChild(), target);

  else	//once found, return found value
    return root->getItem();
}

/******************************************************************
*       Function - Remove
*       Calls findHelp to find a value and then removes that value
******************************************************************/
template<typename elem>
elem Tree<elem>::remove(const elem& target){
	elem temp = findHelp(root, target); //find it
  if(exists != false){ //now remove it
    root = removeHelp(root, target);
    treeCounter--;
  }
  return temp;
}

/******************************************************************
*       Function - RemoveHelp
*       goes to target value. once found, we delete it and swap
*       Node values around in the appropriate manner
******************************************************************/
template<typename elem>
Node<elem>* Tree<elem>::removeHelp(Node<elem>* root, const elem &target){
  if(root == NULL) //empty
    return NULL;

  else if(target < root->getItem()) //go left
    root->setlChild(removeHelp(root->getlChild(), target));

  else if(target > root->getItem()) //go right
    root->setrChild(removeHelp(root->getrChild(), target));

  else{ //FOUND IT...
    Node<elem>* temp = root; //...now time to delete

    if(root->getlChild() == NULL){ //check if theres only right child
      root = root->getrChild();
      delete temp;
    }

    else if(root->getrChild() == NULL){ //check if theres only left child
    	root = root->getlChild();
      delete temp;
    }

    else{ //if both children are there, we know we are removing a
        //internal node. Therefore, we need to perform a swap
        //get the min of whatever subtree youre in...
      Node<elem>* temp = getMin(root->getrChild());
      //...now copy its values into root...
      root->setFreq(temp->getFreq());
      root->setItem(temp->getItem());
      //now set set new child
      root->setrChild(deleteMin(root->getrChild()));
      delete temp;
    }

    return root;
	}
}

/******************************************************************
*       Function - preorder
*       calls the preorder helper
******************************************************************/
template<typename elem>
void Tree<elem>::preorder(void (*func)(elem)){
  preorderHelp(this->root, func);
}

/******************************************************************
*       Function - PreorderHelper
*       Takes in root node and a function. This method goes to
*       root first, then visits children recursively from left
*       to right.
******************************************************************/

template<typename elem>
void Tree<elem>::preorderHelp(Node<elem>* root, void (*func)(elem)){
  if(root == NULL)
    return;

  func(root->getItem());
  preorderHelp(root->getlChild(), func);
  preorderHelp(root->getrChild(), func);
}

/******************************************************************
*     Function - postorder
*     calls the postorder helper
******************************************************************/
template<typename elem>
void Tree<elem>::postorder(void (*func)(elem)){
  postorderHelp(this->root, func);
}

/******************************************************************
*       Function - PostorderHelper
*       Takes in root node and a function. This method goes to
*       left child first and then to parents value, and then to
*       right child in a recursive manner.
******************************************************************/
template<typename elem>
void Tree<elem>::postorderHelp(Node<elem>* root, void (*func)(elem)){
  if(root == NULL)
    return;

  postorderHelp(root->getlChild(), func);//keep going left until
  postorderHelp(root->getrChild(), func);
  func(root->getItem());
}

/******************************************************************
*       Function - Inorder
*       calls the inorder helper
******************************************************************/
template<typename elem>
void Tree<elem>::inorder(void (*func)(elem)){
  inorderHelp(this->root, func);
}

/******************************************************************
*       Function - InorderHelper
*       Takes in root node and a function. This method goes to
*       children first, and then to parent node in a recursive
*       manner.
******************************************************************/
template<typename elem>
void Tree<elem>::inorderHelp(Node<elem>* root, void (*func)(elem)){
  if(root == NULL)
    return;

  inorderHelp(root->getlChild(), func);
  func(root->getItem());
  inorderHelp(root->getrChild(), func);
}

#endif
