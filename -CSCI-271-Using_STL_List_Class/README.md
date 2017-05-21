# Using_Iterators

Instructor: Dr. Thacker

University: Winthrop

Spring 2017 - CSCI 271 

Due Thursday, Jan. 26

# Purpose

Work with the STL - list type

# Problem Statement

We are creating a proof of concept feature for a dating service.  Clients enter some information about themselves.  For our concept assignment, we will just be interested in first name, gender and age.  This information is in a master file.  Later other clients pay to find "people like them".  Our definition of "like them" will be close to their age.  Our clients can restrict selections based on gender if they wish.  Our clients pay for the number of names they get, so they can order 10 names for one price or 6 names for a smaller price.

# Details

You will read the master list from the file /home/win.thackerw/271/peer/master.dat.  In this file will be a person's first name (at most 20 characters) and their gender (either a 'M' or 'F' character), and then their age (a real number, i.e. 26.25 for someone that is 25 and 1/4 years old (not years.months) each separated by white space.  You will insert these values into a doubly linked list in age order.

Next you will read from /home/win.thackerw/271/peer/groups.dat (repeatedly until end of file) a name, and a group size (an integer) based on their payment, and a gender preference ('F', 'M' or 'N' for no preference).   You will then find this person on your master list and print out the "group size" number of people that have the closest ages to his/her age that meet the gender preference criterion.  The group may not be symmetrical.  For a group of size 10, there may be 3 people with higher ages than the one we are considering and 7 with lower ages and having these be the 10 closest grades. Use the STL List class, which is a doubly linked list. Also, there may not be enough people in the master list to satisfy the requested number of results.

# Implementation

You will implement a function that is passed the master linked list, the name, the size of the group and the gender preference. The function will return a list with all the items that meet the criteria.  The main will be repeatedly reading from the groups file and calling this function then printing out the list returned.  It is here that it will be reported if we could not fulfill the number of requested results.

The person that is the basis for the peer group will  be counted as one of the group members.

If when adding the last person to the group there is a tie (a lower age and a higher age the same difference from the person read in from groups.dat), then use the person with the higher age.

# What to turn in

You are to email me your program with the code as an attachment.  You may tar it if you wish.  Also, turn in a printout of your program. 2 points (out of 20) penalty for each day late.  It is due at the beginning of class on the due date.
