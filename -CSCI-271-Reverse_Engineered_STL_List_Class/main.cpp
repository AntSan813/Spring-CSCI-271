/******************************************************************************
*  Antonio Santos
*  CSCI 271 - Spring 2017
*  Program 2 - Due 2/9/17
*  This program is my way of reverse engineering the list STL class.
******************************************************************************/
#include "list.h"
#include <iostream>
#include "iter.h"

int main()
{
  list<int> listint;
  iter<int> iterint;
  listint.push_back(4);
  listint.push_back(5);
  listint.push_front(3);
  listint.push_front(2);
  listint.push_back(7);

/* List Push and Pop Test */
  cout<<"list after some pushfronts and backs"<<endl;
  cout<<"this will also test begin, end, * and ++"<<endl;
  cout<<"should be "<<endl;
  cout<<"2 3 4 5 7"<<endl;
  for (iterint=listint.begin(); iterint!=listint.end(); ++iterint)
    cout<<*iterint<<" ";

  cout<<endl;

  iterint=listint.begin();
  iterint++;
  iterint++;

/* List Erase Test */
  cout<<endl<<"testing erase"<<endl;
  listint.erase(iterint);
  cout<<"should be"<<endl;
  cout<<"2 3 5 7"<<endl;
  for (iterint=listint.begin(); iterint!=listint.end(); ++iterint)
    cout<<*iterint<<" ";

  cout<<endl;
  cout<<endl;

/* List Copy Constructor Test */
  cout<<endl<<"testing copy constructor"<<endl;
  cout<<"should be"<<endl;
  cout<<"2 3 5 7"<<endl;
  list<int> list2(listint);
  for (iterint=list2.begin(); iterint!=list2.end(); ++iterint)
    cout<<*iterint<<" ";

  cout<<endl;

/* List Assignment Test */
  listint.push_front(1);
  listint.push_back(10);
  cout<<endl<<"testing list assignment"<<endl<<"right side"<<endl;;
  list2 = listint;
  cout<<"should be"<<endl;
  cout<<"1 2 3 5 7 10"<<endl;
  for (iterint=listint.begin(); iterint!=listint.end(); ++iterint)
    cout<<*iterint<<" ";
  cout<<endl;
  cout<<"left side"<<endl;
  cout<<"should be"<<endl;
  cout<<"1 2 3 5 7 10"<<endl;
  for (iterint=list2.begin(); iterint!=list2.end(); ++iterint)
    cout<<*iterint<<" ";
  cout<<endl;

/* List Empty Test */
  list<int> list3;
  cout<<endl<<"testing empty"<<endl;
  cout<<"should get"<<endl;
  cout<<"empty"<<endl;
  if (list3.empty())
    cout<<"empty"<<endl;
  else
    cout<<"not empty"<<endl;
  cout<<endl<<"testing empty"<<endl;
  cout<<"should get"<<endl;
  cout<<"not empty"<<endl;
  if (list2.empty())
    cout<<"empty"<<endl;
  else
    cout<<"not empty"<<endl;

/* List Size Test */
  cout<<endl<<"testing size"<<endl;
  cout<<"should get"<<endl;
  cout<<"6  0  6"<<endl;
  cout<<listint.size()<<"  "<<list3.size()<<"  "<<list2.size()<<endl;

/* List Front Test */
  cout<<endl<<"testing front"<<endl<<"should get"<<endl;
  cout<<"1"<<endl;
  cout<<listint.front()<<endl;

/* List Pop Front Test */
  cout<<endl<<"testing pop_front"<<endl<<"should get"<<endl;
  cout<<"2"<<endl;
  listint.pop_front();
  cout<<listint.front()<<endl;

/* List Back Test */
  cout<<endl<<"testing back"<<endl<<"should get"<<endl;
  cout<<"10"<<endl;
  cout<<listint.back()<<endl;

/* List Pop Back Test */
  cout<<endl<<"testing pop_back"<<endl<<"should get"<<endl;
  cout<<"7"<<endl;
  listint.pop_back();
  cout<<listint.back()<<endl;

/* List Pre ++ Test */
  cout<<endl<<"testing pre ++"<<endl<<"should get"<<endl;
  cout<<"2 2"<<endl;
  iter<int> it2,it3;
  it2=list2.begin();
  it3=++it2;
  cout<<*it2<<" "<<*it3<<endl;

/* List Post ++ Test */
  cout<<endl<<"testing post ++"<<endl<<"should get"<<endl;
  cout<<"2 1"<<endl;
  it2=list2.begin();
  it3=it2++;
  cout<<*it2<<" "<<*it3<<endl;

/* List Pre -- Test */
  cout<<endl<<"testing pre --"<<endl<<"should get"<<endl;
  cout<<"7 7"<<endl;
  iter<int> it4,it5;
  it4=list2.end();
  it4--;
  it5=--it4;
  cout<<*it4<<" "<<*it5<<endl;

/* List Post -- Test */
  cout<<endl<<"testing post --"<<endl<<"should get"<<endl;
  cout<<"7 10"<<endl;
  it4=list2.end();
  it4--;
  it5=it4--;
  cout<<*it4<<" "<<*it5<<endl;

  return 0;
}
