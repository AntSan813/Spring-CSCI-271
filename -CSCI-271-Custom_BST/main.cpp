/*****************************************************************************
*  Antonio Santos
*  CSCI 271 - Spring 2017
*  Program 3 - Due 3/7/17
*  Customized binary sort tree.
*****************************************************************************/
#include "Node.h"
#include "Tree.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

//prints out what is in the BST
void print(const string);

int main(){
	Tree<string> test;
  string word;
  int choice;
	char repeat;
	//STEP 1 --- READ IN FROM DESIGNATED FILE
	char hold;
	ifstream file;

	file.open("lyrics.txt");

	//flag for file not opening
	if(!file.is_open()){
		cout << "File did not open." << endl;
	}

	while(!file.eof()){
		file.get(hold); //grab a char
		//if char is what im looking for...
		while((hold != ' ') && (hold != '\n')){
			if(isalpha(hold)){
				//...then I put it in to temp string
				word.push_back(hold);
			}
			file.get(hold);
		}
		test.insert(word); //when while kicks out, I know it
		//completed grabbing word
		//now erase what I have in temp string
		word.erase(word.begin(), word.end());
	}//end of tree input

	file.close(); //close file
	cout << endl; //for readability

	do{ //outter do-while repeats menu if wanted
		do{ //inner do-while checks for correct input
			//Menu of tests
			cout << "\nPlease select what you would like to test:\n"
			<< "\n1. Display using Inorder Traversal"
			<< "\n2. Display using Preorder Traversal"
			<< "\n3. Display using Postorder Traversal"
			<< "\n4. Remove from tree"
			<< "\n5. Display all with freq"
			<< "\n6. Get size"
			<< "\n7. Clear tree" << endl;
			cin >> choice;
		}while((choice > 7) && (choice < 1));

		//executes desired test based off input
		switch(choice){
			case 1: test.inorder(print);//goes to all children
			//'in order' and outputs them.
			//LCR
			break;
			case 2: test.preorder(print);//goes to left child, then
			//to right child, then checks root
			//LRC
			break;
			case 3: test.postorder(print);//checks root, then goes
			//left, then right
			//CLR
			break;
			case 4:{ //remove value from BST
				cout  << "Please enter a word you"
				<< "want to delete from tree: ";
				cin >> word;
				test.remove(word);
			}
			break;
			case 5:	test.print_whole(); //print everything together
			break;
			//output size of tree
			case 6: cout << "Size of tree: " << test.getSize() << endl;
			break;
			//clear tree
			case 7:{
				cout << "Size of tree: " << test.getSize() << endl;
				cout << "Clearing..." << endl;
				test.clear();
				cout << "New size of tree: " << test.getSize() << endl;
			}
		}

		cout << "Run again? (Y/N)" << endl;
		cin >> repeat;

		//converts user input to uppercase
		if(islower(repeat))
			repeat = toupper(repeat);

	}while((repeat == 'Y') && (choice != 7));

	return 0;
}

//used to pass into traverse functinos in the tree class
void print(const string x){
	cout << x << endl;
}
