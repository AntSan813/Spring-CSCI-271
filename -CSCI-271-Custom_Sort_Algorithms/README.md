# Custom_Sort_Algorithms
Instructor: Dr. Thacker

University: Winthrop

Spring 2017 - CSCI 271

Due Monday March 27

# Problem:

Compare an O(n2) sort with an O(n log n) sort.  To do this, you will program the insertion sort and the merge sort.  You will not need to use classes in this project, but you can if you wish.

# Our project input:

The input will be character strings of length less than or equal to 30 characters.  They will come from the file /home/win.thackerw/271/sort.dat.

You will run these programs with several different input and array sizes.  You can pass arguments from the command line to your program.  For example you should be able to type into the command line "p4 20000" and the executable "p4" is executed passing the argument 20000 to the program.  To see how to access the argument(s) check out : http://www.site.uottawa.ca/~lucia/courses/2131-05/labs/Lab3/CommandLineArguments.html

# Our project output:

The program should print out the sorted array to a file "sorted.dat"

You will need to measure the time it takes the computer to perform each sort.  You get the time by using the time function in Unix.  If your program is called p4 then instead of issuing the command p4 to run your program, you use time p4.  This will run your program and report system (sys), user, and real times.  The time of interest for us is user time and sys time added together.  You (not your program) should produce a table of the form:

Table Size	Time for insertion Sort	Time for merge Sort

2,000	 	 

4,000	 	 

10,000	 	 

20,000	 	 

50,000	 	 

100,000	 	 

Additionally, you must graph the results.  Also, do the merge Sort on data of size 1,000,000 and 10,000,000.  Some of these arrays may be too big for static declaration.  Instead you can use the NEW command to create an array of appropriate size.  This gets the data from the heap and not from static area (which is more limited).

Produce a prediction for the time it will take to do an insertion sort for 1,000,000 and 10,000,000 items.  Justify your estimate.

A major part of the grade is your report.  Doing this well will take a little time.  Do not think that getting the programs working is the end of the project, it is just the beginning.

# Project Options

For extra credit, you may do one additional O(n2) sort (ex. bubble, selection) AND one additional O(n log n) sort (ex., quick sort, heap sort).
