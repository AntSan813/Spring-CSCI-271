# -CSCI-271-Hashing_Studies
Instructor: Dr. Thacker

University: Winthrop

Spring 2017 - CSCI 271

Due Tue. April 11

# Problem:

Study the effects of different hash table sizes on the search time.  The study will consist of creating a hash class (with a hash table, an insert function and a search function (feel free to add more main and class functions that you find necessary and/or helpful).   The size of the hash table must be easily modified (preferably via the constructor).  All functions that are based on the table size (such as the hash function) must be aware of any changes to the table size.

Read 200,000 values from the file /home/win.thackerw/271/sort.dat inserting them into the hash table.  Then read ALL values from /home/win.thackerw/271/search.dat and search for those values.  Use this process for table sizes of 400,000,  300,000, 270,000, 220,000.  This will give us different  % full in order to see the changes for different sizes.  Time each of these runs.  Since the tables are all different sizes, there will be a different load factor for each experiment.

# Our project input:
The input will be character strings of length less than or equal to 30 characters.

# Our project output:

Your program will print out the average number of probes for all the searches, the number of searches that were successful and the number of searches that were unsuccessful.  A probe is when you look at a value in the array.  The number of Unsuccessful probes should be the same for all the different table sizes since we are always searching for the same items (similarly, the number of successful searches will be the same for all table sizes; this is just a check of correctness for your program.  If you don't have the same numbers throughout each of these columns then something is wrong).  

Additionally, you will record the times it takes for the programs to run for each of the table sizes.  You get the time by using the time function in Unix.  If your program is called p5, then instead of issuing the command p5 to run your program, you use time p5.  This will run your program and report system, cpu, and wallclock times.  The time of interest for us is cpu+system.

Your project should produce a table that gives the following at table sizes of 400,000, 300,000, 270,000, and 220,000:
Table Size
Load Factor
TIME
Probes
Avg. Probes (#Probs/(unsuccessful+successful) )
Unsuccessful (searches)
Successful (searches)

Definitions: Search - looking for an item (may take 1 or several probes).  Probe - looking in the table (may have to look more than once for a particular search).

# Project Options

You may use any hash function you can develop.  It needs to be "good".   You are to use linear probe for collision handling.  For extra credit, you may use separate chaining (using appropriate table sizes) and report the timings and average probes for it.
