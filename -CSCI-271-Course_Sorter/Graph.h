/******************************************************************************
*  Antonio Santos
*  Spring CSCI 271 - Dr. Thacker
*  Program 6 - Due 4/24/17
******************************************************************************/
#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <queue>
#include "Node.h"
#include <string>
#include <stdlib.h>

using namespace std;
const int TABLE_SIZE = 500;
class Graph{
  private:
    Node graph[TABLE_SIZE]; //hash table
    int keys[TABLE_SIZE]; //list of keys
    int num_vert; //vertice counter
    int num_edges; //edge counter

  public:
    Graph();
    void insert_first(string);
    void insert_rest(string, string);

    int h(string); //hash function
    void display(Node); //display courses
    void topo_sort(); //display courses in topological order
    bool search(string);
    void get_details();
};

//default constructor
Graph::Graph(){
  num_vert = 0;
  num_edges = 0;
  Node x("FFFF");
  for(int i = 0; i < TABLE_SIZE; i++){
    graph[i] = x;
  }
}

/******************************************************************************
*  function: insert_first(string)
*  this function is used to insert a node that is noted as a main course
******************************************************************************/
void Graph::insert_first(string s){
  int key = h(s); //get key
  if(!graph[key].empty()){} //if it already exists, ignore
  else{ //insert the node if it dne already
    Node new_node(s); //make new node with the course passed in
    graph[key] = new_node; //insert
    keys[num_vert] = key; //record the key
    num_vert++; //we just added a node(vertice), so increment our vertex count
  }
}

/******************************************************************************
*  function: insert_rest(string, string)
*  this function is used to insert all courses following a main course.
*  in other words, this function inserts prerequisites.
******************************************************************************/
void Graph::insert_rest(string main_c, string prereq){
  int key = h(main_c); //get main key
  int other_key = h(prereq);//get prereq key

  if(graph[other_key].empty()){ //if this node dne, create it
    Node new_node(prereq); //create new node
    graph[other_key] = new_node; //add new node into graph
    keys[num_vert] = other_key; //add this new node's key into the key list
    num_vert++; //increase num vertices since we added a new node
  }

  //increase indegree count
  graph[key].insert_in_list(other_key);
  graph[other_key].insert_out_list(key);
  num_edges++; //increase edges
}

/******************************************************************************
*  function: h(string)
*  this function creates a hash key for our courses. this hash key is
*  found through getting last 3 chars from string and converting them to ints
******************************************************************************/
int Graph::h(string s){
  int x = s.size(); //get size of string

  //get last 3 chars
  char a = s.at(x-1);
  char b = s.at(x-2);
  char c = s.at(x-3);

  //put last 3 chars into char array
  char temp[3] = {c, b, a};

  //convert last 3 chars into an int
  int key = atoi(temp);

  return key % TABLE_SIZE; //return making sure its in table size
}

//displays a nodes course
void Graph::display(Node dis){
  cout << dis.get_course() << endl;
}


/******************************************************************************
*  function: topo_sort()
*  this function goes through the graph and prints the nodes in
*  topological order
******************************************************************************/
void Graph::topo_sort(){
  Node temp;
  queue<Node> zero_list;
  int edge_count = num_edges;
  int iter = num_edges;
  int key;

  //as we go through the following, we are essentially 'erasing' edges, Which
  //lowers the count of edges we have in our graph. The amount of edges
  //represents the amount of directed connections we have, which is why we use
  //the number of edges as our conditional
  while(iter != 0){
    for(int i = 0; i < num_vert; i++){ //get all that have an indegree of 0
      if((!graph[keys[i]].is_marked())
          && (graph[keys[i]].get_indegree() == 0)){
        zero_list.push(graph[keys[i]]);
        graph[keys[i]].mark(); //mark as pushed onto top stack
      }
    }
    //go through the list of nodes that have 0 indegree, and decrement all of
    //the nodes' indegree's that they point to (if any), then print the node
    //and 'delete it' from the graph (or technically dont have anything
    //point to or from it)
    for(int x = 0; x < zero_list.size(); x++){
      temp = zero_list.front(); //pop front
      display(temp); //display
      zero_list.pop();
      int* hold = temp.get_out_list(); //get the list of keys that this node
                                       //points to
      //decrease indegree of those that this node is pointing to
      for(int y = 0; y < temp.get_outdegree(); y++){
        graph[hold[y]].set_indegree(graph[hold[y]].get_indegree() - 1);
      }
    }
    iter--; //decrement edge count since we theoretically got rid of it
  }
}

/******************************************************************************
*  Function: search(string)
*  used to make sure the graph was working and efficiently assigning
*  prerequisites to courses (if any)
******************************************************************************/
bool Graph::search(string s){ //
  int key = h(s); //get the key for this course
  cout << graph[key].get_course() << endl; //print out the main course

  if(!graph[key].empty()){ //if something exists, do following
    int* hold = graph[key].get_in_list(); //get list of keys that this node
                                          //points to

    //print out the keys that are in the indegree list
    for(int i = 0; i < graph[key].get_indegree(); i++){
      cout << "Prerequisite " << i + 1 << ": " << graph[hold[i]].get_course() << endl;
    }
    return true;
  }
  else{ //search failed - the target string dne
    return false;
  }
}

void Graph::get_details(){
  cout << "Number of Edges: " << num_edges << endl;
  cout << "Number of Vertices/Courses: " << num_vert << endl;
}
#endif
