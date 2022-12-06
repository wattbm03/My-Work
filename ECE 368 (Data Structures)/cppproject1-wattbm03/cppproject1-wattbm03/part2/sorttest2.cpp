// Please add your name below
// Name: Breeanna Watters

// FILE: sorttest2.cpp
// This file tests and compares different sorting algorithms

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include "sort.h"

using namespace std;

// PROTOTYPES for functions used by main
void print_menu( ); 
char get_user_command( ); 
bool check_ordered(string data[], size_t n);

int main()
{
	string inputfilename; // input filename
	int size;
    int i=0;
    string line;
	cout << "Please specify the file with data to be sorted: ";
	getline(cin, inputfilename);

	ifstream inputfile(inputfilename); // file stream for input text file

	assert(inputfile);	// assert no file open errors
	
	//------------------------------------------------------------------
	// Include implementation from part 1: 
	//	- Read the words into the words array
 inputfile.open(inputfilename);
  getline(inputfile, line);
  size=stoi(line); // set size to what line 1 says
  string words[size]; // done to define size of array as right value
  inputfile.close(); // done to make sure data is rightfully recored in the spots
  inputfile.open(inputfilename); // to re-open file
    if (inputfile.is_open()) { // if file is actually open
        getline(inputfile, line); // done to get rid of number line
      int i=0; // set i to be extra variable
      while (inputfile >> line) {
          words[i] = line; // to write the word to a spot in the array
          i++;}      
        }
  inputfile.close(); // close the input file
	
	print_menu( ); // print menu
	char choice = get_user_command( ); // get user selection
	
	// Record the start time
	clock_t nStart = clock();

	// call sort function based on user selection
	switch (choice)
    {
		case '1': 
			bubblesort(words, size);
			break;
		case '2':
			selectionsort(words, size);
			break;
        case '3': 
			insertionsort(words, size);
            break;
        case '4': 
			shellsort(words, size);
            break;
        case '5': 
			quicksort(words, size);
            break;
		case '6': 
			mergesort(words, size);
			break;
        default:  
			cerr << choice << " is invalid. Sorry." << endl;
			return 1;
    }
	
	// Record the end time
	clock_t nEnd = clock();

	// Print out total execution time for sorting
	cout << "Time elapsed: " << (nEnd-nStart)*1.0/CLOCKS_PER_SEC*1000 << " msec.\n";
	
		
	if (!check_ordered(words, size)) return 1; // Check if words array is sorted	
	
	cout << "Please specify a file name to hold the sorted data: ";
	string outputfilename;  // output filename
	cin.ignore();
	getline(cin, outputfilename); 
	ofstream outputfile(outputfilename); // file stream for output text file
 	
	//------------------------------------------------------------------
	// Include implementation from part 1: 
	// print all words, one a line, to the output file
	
	if (outputfile.is_open()) {
     for(int i=0; i<=size-1; i++){
       outputfile<< words[i]<< endl; // to put into output file
     }}
	
	
	
	outputfile.close(); // close the output file
	return 0;
}

// Print menu choices to cout
void print_menu( )
{
	cout << endl; // Print blank line before the menu
	cout << "The following choices are available: " << endl;
	cout << " 1   Run bubblesort" << endl;
	cout << " 2   Run selectionsort" << endl;
	cout << " 3   Run insertionsort" << endl;
	cout << " 4   Run shellsort" << endl;
	cout << " 5   Run quicksort" << endl;
	cout << " 6   Run mergesort" << endl;
}

// Get user menu selection from cin
char get_user_command( )
{
	char command;

	cout << "Enter choice: ";
	cin >> command; // Input of characters skips blanks and newline character

	return command;
}

// Check whether a string array is sorted and print result
bool check_ordered(string data[], size_t n)
{
	//------------------------------------------------------------------
	// Include implementation from part 1
	//------------------------------------------------------------------
	// TO-DO: Please include your implementation here
  for(size_t i=0; i < n-1; i++){
    if(data[i]>data[i+1]){
      return false;}
    else
      continue;
  }
  return true;

	
}
