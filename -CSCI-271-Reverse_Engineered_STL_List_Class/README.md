# Custom_Iterators

Instructor: Dr. Thacker

University: Winthrop

Spring 2017 - CSCI 271

Due Thursday, Feb 9

# Purpose

Reverse engineer the list STL class

# Problem Statement

Now that you are experienced with the List STL, you will create your own list template class to use in place of the list STL class.  I will provide a main later for you to test with.

the main that you can use for testing is:

/home/win.thackerw/271/p2main.cpp

Because of implementation difficulties, your STL-like list class will be a little different.  One significant difference is that the iterator class will be a templated class of its own, not a class within the list class.  So to get a list of cars, you would say:  list<cars> mylist;  However, there is a builtin class called iterator (different from the list<..>::iterator class).  So, we cannot use iterator as the name of our iterator class.  We will use iter.  to get an iterator to a node within a list of cars, you would use: iter<cars> myiterator;


# Details

You are to call your  class  List and have the following member functions.  You may use additional ones if you wish/need, but they must look and act like list stl methods.  Of course, you will need to create 3 classes, one for the linked list, one for the node and one for the iterator.

constructor	Create the list.  You will probably want head and tail nodes and pointers.
copy constructor	allows you to do List A(B) so that you create A as a copy of B.  This is a little involved as it is NOT just copying the values of the head pointers.
destructor	removes and deletes all the nodes (including head an tail nodes)
operator =	Copies one linked list into another (requires creating a new set of nodes)
bool empty()	true if there are no values in the list
int size()	returns the number of values in the list
iter begin()	returns an iterator to the first item in the list
iter end()	returns an iterator to after the last item in the list
Type front()	returns a reference to the first item in the list
Type back()	returns a reference to the last item in the list
void clear()	removes all items from the list
void erase(iter)	removes the item iterator indicates from the list
void push_back(value)	insert value at the end
void push_front(value)	insert value at the beginning
void pop_front()	removes the first value in the list
void pop_back()	 removes the last value in the list
++iter	move iterator to the next and return the modified value of the iterator
iter++	move iterator to the next and returns the original value of the iterator
iter--, --iter	move iterator to the previous, post and pre.
*iter	return the value in the node pointed to by the iterator
Again, feel free to add any methods that you wish.

I suggest you implement just the constructors, the push_back, the begin and the ++ methods so you can write a main that simply creates a list and prints it out.  Get this working before continuing with the design of the other methods.

# Turn in

Email me your code as attachments (you may use a tar file if you wish or multiple attachments; also make files will make me happy).  Additionally, you are to hand in a printout of your code.

# Late Penalty

There will be a 20% penalty for each day late.

