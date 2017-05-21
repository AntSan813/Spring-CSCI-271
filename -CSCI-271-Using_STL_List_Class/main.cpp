/******************************************************************************
*  Author: Antonio Santos
*  Name: Program 1
*  Spring 2017 CSCI 271
*  description: this program takes in a list of people, sorts them by age,
*  takes in a list of clients, and then finds their matches based off of
*  gender preference and age.
*  Due Date: 1/24/17
******************************************************************************/
#include <iostream>
#include <list>
#include <fstream>

using namespace std;

/*****************************************************************************
  Struct: client
	description: this structure lets us store information about each client sent
  in.
******************************************************************************/
struct client{
  string name;
  char gender;
  int year;
	int gsize;
};

//the function below is an algo that finds the matches of a client based off
//special cases
list<client> findMatches(int,char,string,list<client>,int,int);

int main(){//start of main
  //variables
  client customer;
  client holder;
  list<client> master;
  list<client> matches;
  ifstream input;
  list<client>::iterator before_iter;
  list<client>::iterator iter;
  list<client>::iterator beg;
  int counter = 0;
  int mCount = 0;
  int fCount = 0;

	//read in the master list
	input.open("sample_data.txt", ios::binary);

  //existance check
  if(!input.is_open()){
    cout << "FATAL ERROR - THE FILE DNE!" << endl;
    return 0;
  }

/******************************************************************************
Following while reads in the information in the file opened into the client
structure. After each read in, the client is pushed into the master list. While
it is being read in and pushed into the list, we sort the list as we push in.
******************************************************************************/
	while((input >> customer.name) && (input.is_open())){
    input >> customer.gender;
    input >> customer.year;

		master.push_back(customer);
		if(customer.gender == 'M')
			mCount++;
		else
			fCount++;

		iter = master.end();
		iter--;//now it points to the actual end of list rather than end + 1

    before_iter = master.end();
    before_iter--;
    before_iter--;//points to the end of list - 1

		counter++;//We dont want to start sorting until we have 2 objects in the
              //list. This counter makes that check possible

		//following sorts the list by year
		if(counter > 1){

			beg = master.begin();
			beg--; //now it points to the begining - 1

			//following while sorts the list by year, by going down the list to see
      //if the previous objects year is greater than the objects year we just
      //pushed in iter is the iterator for the current object we just pushed in
			//before_iter is the iterator for the object before the object we just pushed in
    	while(before_iter != beg){

				//swap the objects if it is unsorted
				if((*before_iter).year > (*iter).year){
					holder.name = (*iter).name;
          holder.gender = (*iter).gender;
          holder.year = (*iter).year;

					(*iter).name = (*before_iter).name;
          (*iter).gender = (*before_iter).gender;
	        (*iter).year = (*before_iter).year;

					(*before_iter).name = holder.name;
          (*before_iter).gender = holder.gender;
          (*before_iter).year = holder.year;
				}
				iter--;
				before_iter--;
			}
	  }
    if(input.eof()){
      input.close();
    }
  }//end of while loop
	//following outputs the list to screen
  //--used to validate the algorithm above works--
	for(iter = master.begin(); iter != master.end(); ++iter){
		cout << (*iter).name << ' ' << (*iter).gender << ' ' << (*iter).year << endl;
	}

	//makes sure prev file is closed
	if(input.is_open())
		input.close();
	cout << endl;

	//opens the new file that contains the clients
	input.open("groups.txt", ios::binary);

	//checks if the file opened
	if(!input.is_open()){
		cout << "FATAL ERROR - THE FILE DNE!" << endl;
		return 0;
	}

	counter = 0;

/*                                                                            *
*  following while reads in the clients info and outputs them to the screen for
*  checking purposes. it then takes the passed in values and passes them through
*  the function which returns a list of matches.
*                                                                            */
	while((input >> customer.name) && (input.is_open())){
		input >> customer.gsize;
    input >> customer.gender;
		counter++;
    //output to screen
		cout << "Client " << counter  << " Info:" << endl
			<< "Name: " << customer.name << endl
			 << "Number of names wanted: " << customer.gsize << endl
			  << "Gender preference: " << customer.gender << endl;
		cout << endl;

		cout << "Matches found: " << endl;
		matches = findMatches(customer.gsize,customer.gender,customer.name,master,mCount,fCount);

		if(input.eof()){
			input.close();
		}

		//outputs the list of matches
    for(iter = matches.begin(); iter != matches.end(); iter++){
		  cout << (*iter).name << ' '
        << (*iter).gender
          << ' ' << (*iter).year << endl;
    }
		cout << endl << endl;
	}
  return 0;
} //end of main

/******************************************************************************
*  Function: findMatches(int, char, string, list<client>)
*  description: finds the matches of the client with the given values. this is
*  determined by the age that is nearest to the client.
******************************************************************************/
list<client> findMatches(int groupSize, char genPref, string name,
                            list<client> mas, int male, int female){
	//variables
	list<client> matches;
	list<client>::iterator up;
	list<client>::iterator down;
	list<client>::iterator it;
	list<client>::iterator beg;
	client cust;
	client holder;
	bool go_up = true;
	bool go_down = true;


	cust.name = name;
	it = mas.begin();
	beg = mas.begin();
	beg--;//points to the container before the beginning

	//following case is ig the customer is at the beginning of the master list
  if((*it).name == cust.name)
    cust.year = (*it).year;
	//if its not at the beginning of the master list, find it
	else{
		while(((*it).name != cust.name) && (it != mas.end())){
			it++;
			if((*it).name == cust.name)
			  cust.year = (*it).year;
		}
	}

	//to make sure we have the correct count of males and females, we include the
  //following if else statement
	if((*it).gender == 'M')
		male--;
	else
		female--;

/*
following cluster of if else statements checks to see what happens.
note that I put '-1' to the end of the group size because we are checking
the master list - the customer whos already in the list. We DO NOT want
to include the customer in the final list becuase it makes no sense to
say he/she is a match for his/herself
*/

  //case 1: if the group size is larger than the master list size, spit out an
  //error message
	if(((mas.size() < groupSize - 1) && (genPref == 'N')) ||
               ((genPref == 'M') && (groupSize > male)) ||
               ((genPref == 'F') && (groupSize > female))){
		cout << "The amount of people requested exceeds the amount of people in our database!" << endl;
		return matches;
	}
  //case 2: if the group size requested equals the size of the master list
	else if(((mas.size() == groupSize - 1) && (genPref == 'N')) ||
                  ((genPref == 'F') && (groupSize == female)) ||
                  ((genPref == 'M') && (groupSize == male))){
		matches = mas;
	}
  //case 3: if the group size is less than the size of the list, then we find
  //the matches in the list
	else if(groupSize - 1 < mas.size()){
		down = it;
		up = it;

		//while we go through the following while loop, the size of the final list
    //(AKA matches list) will be incremented.
		while(matches.size() != groupSize){
			//first and foremost we want to increment and decrement our iterators.
			//after the first go around in the while loop, only one of the following
      //if statements will be executed. the nested if else statement checks for
      //the gender preference
			if((down != mas.end()) && (go_down)){
				down++;
				if(genPref == 'N'){}
				else if((*down).gender != genPref){
					while(((*down).gender != genPref) && (down != mas.end()))
						down++;
				}
			}
			if((up != beg) && (go_up)){
				up--;
        if(genPref == 'N'){}
        else if((*up).gender != genPref){
          while(((*up).gender != genPref) && (up != mas.end()))
            up--;
        }
			}

			//if the down iterator has reached the end of its side, we only want to
      //use the top iterator here on out
			if(down == mas.end()){
				holder.name = (*up).name;
        holder.gender = (*up).gender;
        holder.year = (*up).year;
        go_up = true;
        go_down = false;
        matches.push_back(holder);
			}

			//same thing as previous comment, but vice versa
			else if(up == beg){
				holder.name = (*down).name;
        holder.gender = (*down).gender;
        holder.year = (*down).year;
        go_up = false;
        go_down = true;
        matches.push_back(holder);
			}

/*                                                                            *
logic used for the rest of the if else statements:
the up iterator is going up and the bottom iterator is going down visually.
but in the code, the up iterator is decrementing and the down iterator is
incrementing. Another way to look at this, is the down iterator is going towards
the people with the higher age and the up iterator is going to those with a
lower age than the client. With that being said, if the clients year/age - the
up iterator will give the difference in years between the client and the people
younger than the client, and vice versa for the people older than the client.
whoever has the shortes difference will be pushed into the matches list.
in the case that they both equal each other, then we choose the older person
(whoever the down iterator is at) when the person is chosen to be pushed into
the matches list, we will only increment or decrement the iterator that
contained the matched person (hence the use of boolean statements)
*                                                                            */
			else if(((*down).year - (*it).year) > ((*it).year - (*up).year)){
				holder.name = (*up).name;
        holder.gender = (*up).gender;
        holder.year = (*up).year;
				go_up = true;
				go_down = false;
				matches.push_back(holder);
			}
			else if(((*down).year - (*it).year) == ((*it).year - (*up).year)){
        holder.name = (*down).name;
        holder.gender = (*down).gender;
        holder.year = (*down).year;
				go_down = true;
				go_up = false;
        matches.push_back(holder);
      }
			else{
        holder.name = (*down).name;
        holder.gender = (*down).gender;
        holder.year = (*down).year;
				go_down = true;
				go_up = false;
        matches.push_back(holder);
			}
		}//end of while
	}
	return matches;
}//end of function
