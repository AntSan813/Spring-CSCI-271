/******************************************************************************
*  Antonio Santos
*  Spring CSCI 271 - Dr. Thacker
*  Program 6 - Due 4/24/17
******************************************************************************/
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;

class Node{
  private:
    string course;
    bool m;
    int outdegree; //#of nodes this node is pointing to
    int out_list[500]; //list of nodes this node is pointing to

    int indegree; //how many are pointing to this node/vertice
    int in_list[500]; //keep track of those nodes pointing toward this node

  public:
    Node(); //default
    Node(string); //parameter constructor

    bool is_marked();
    void mark();

    void insert_in_list(int);
    int* get_in_list();

    int get_indegree();
    void set_indegree(int);

    bool empty();

    void insert_out_list(int);
    int* get_out_list();

    void set_outdegree(int);
    int get_outdegree();

    void set_course(string);
    string get_course();
};

//default constructor
Node::Node(){
  outdegree = 0;
  indegree = 0;
  course = "FFFF";
  m = false;
}

//constructor that allows you to pass in course
Node::Node(string c){
  course = c;
  outdegree = 0;
  indegree = 0;
  m = false;
}

//check if empty
bool Node::empty(){
  if(course == "FFFF"){
    return true;
  }
  else{
    return false;
  }
}

//check if this node is marked
bool Node::is_marked(){
  return m;
}

//update mark
void Node::mark(){
  m = true;
}

//get indegree
int Node::get_indegree(){
  return indegree;
}

//update indegree
void Node::set_indegree(int i){
  indegree = i;
}

//insert into the indegree list
void Node::insert_in_list(int key){
  in_list[indegree] = key;
  indegree++;
}

//get list of keys that are pointing to this node
int* Node::get_in_list(){
  return in_list;
}

//set course
void Node::set_course(string c){
  course = c;
}

//get course
string Node::get_course(){
  return course;
}

//insert into the outdegree list
void Node::insert_out_list(int key){
  out_list[outdegree] = key;
  outdegree++;
}

//get list of keys that this node is pointing to
int* Node::get_out_list(){
  return out_list;
}

//get outdegree
int Node::get_outdegree(){
  return outdegree;
}

//update outdegree
void Node::set_outdegree(int x){
  outdegree = x;
}

#endif
