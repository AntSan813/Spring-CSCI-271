# -CSCI-271-Course_Sorter
Using the Graph Data Structure, this program takes in a list of courses along with their prerequisites and outputs the order in which you should take the courses to graduate.

# Problem:

Given the courses needed for graduation and their prerequisites, create a list of courses in an order that will allow the student to progress successfully.

# Our project input:

The input will be character strings of length less than or equal to 10 characters.   Each string will represent a course.  The first course on each line will be the base course.  The rest of the courses on the same line will be the prerequisite courses that must be completed before the base course can be taken.  There will be a # sign at the end of each line to make input easier. A course may have no prerequisites.

There will be no more than 500 courses to consider.

# Here is a sample input

CSCI311 CSCI211 MATH261 #

CSCI470 CSCI311 MATH201 #

CSCI101 #

CSCI211 CSCI208 CSCI101 #

CSCI208 CSCI207 MATH261 #

MATH261 #

MATH201 #

CSCI207 #

# Our project output:

You will print out a list of courses such that the prerequisites for every course appear before that course.  You must implement this solution in the most efficient (for the computer) way possible.

We talked about making the topological sort algorithm fast.  One method used linked lists.  You may use the STL linked list class or your own.

Another problem with this project is given a course name string, find where it is in the array.  Linear search is inefficient, binary search requires keeping the array sorted.  You need to come up with a VERY efficient way of finding which item in the array corresponds to a particular course string.
