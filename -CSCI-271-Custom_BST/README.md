# Custom_BST
Instructor: Dr. Thacker

University: Winthrop

Spring 2017 - CSCI 271

Due Monday, April 24 5PM

# Problem:

Read in words from a large file.  Count the frequency of words.  Print out the words in alphabetical order with their frequency.  Remove all the words that contain the letter 'e'.  Print out the remaining words in alphabetical order with their frequency.  We will use a templated binary sort tree for this problem.

# Project input:

Your program should expect a file of text.  The data for our project will be win.thackerw/271/lyrics.txt .  The issue with a plain text file is the punctuation.  You need to remove nonletters from the words you read in.

# Processes

For your main, the data stored in each node will be a character string of at most 30 characters.  You should make your tree class templated, so your class will handle any data type for future different mains.   Then the data is read in and if the value exists, the counter is incremented by one.  If it does not exist, then it is inserted with a counter of 1.  You need to include the three traversal methods that take a function as an argument (what to do with each node visited).  Of course, you will need a remove method.  Feel free to include other helper methods or appropriate tree methods.

# Project output:

You will output the sorted list with frequencies to the file all.out

You will output the sorted list with values without 'e' to the file noE.out
