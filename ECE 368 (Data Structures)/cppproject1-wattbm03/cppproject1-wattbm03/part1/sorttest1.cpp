// Please add your name below
// Name: Breeanna Watters

// FILE: sorttest1.cpp
//  This file reads a word list file, 
//  sorts the words, tests if the words are sorted, 
//  and prints the words in a new file. 

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cassert>

using namespace std;

// PROTOTYPE for functions used by main()
bool check_ordered(string data[], size_t n);
void bubblesort(string data[ ], size_t n);

int main(int argc, char** argv)
{
	string inputfilename; // input filename
	int size;
    int i=0;
    string line;


	cout << "Please specify the file with data to be sorted: ";
	getline(cin, inputfilename);

	ifstream inputfile; // file stream for input text file

	assert(inputfile);	// assert no file open errors
		
	//------------------------------------------------------------------
	// TO-DO: Read the words into a string array
	// ------
	//   Keep in mind that the first line in the file contains the number 
	//   of words, and each rest line contains a single word

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
	//------------------------------------------------------------------
	// TO-DO: Sort the string array in alphabetic order 
	// ------
	// Please call the bubblesort function here
	 bubblesort(words, size); // called sort function
	
	
	if (!check_ordered(words, size)) return 1; // Check if words array is sorted	
		
	cout << "Please specify a file name to hold the sorted data: ";
	string outputfilename;  // output filename
	getline(cin, outputfilename); 
	ofstream outputfile(outputfilename); // file stream for output text file
	
	// TO-DO: Write the sorted words into the file 
	// ------
	//   Please print one word per line. 
	//   Don't print the number of words in the first line. 
 if (outputfile.is_open()) {
     for(int i=0; i<=size-1; i++){
       outputfile<< words[i]<< endl; // to put into output file
     }}
	outputfile.close(); // close the output file

	return 0;
}

// Check whether a string array is sorted and print result
bool check_ordered(string data[], size_t n)
{    //------------------------------------------------------------------
	// TO-DO: Please include your implementation here
  for(size_t i=0; i < n-1; i++){
    if(data[i]>data[i+1]){
      return false;}
    else
      continue;
  }
  return true;
  }

//////////////// Bubble Sort ////////////////////////////
void swap(string & s1, string & s2)
{
	string temp;
	temp = s1;
	s1 = s2;
	s2 = temp;
}

void bubblesort(string data[ ], size_t n)
// Using bubble sort to sort elements of data in ascending order 
// i.e., data[0] <= data[1] <= ... <= data[n-1]
{
	size_t k = 0;
	bool switched = true;
	while (k < n-1 && switched) 
	{
		switched = false;
		k++;
		for (size_t i = 0; i < n-k; ++i) 
		{
			if (data[i] > data[i+1]) 
			{ 
				swap(data[i], data[i+1]);
				switched = true;
			}
		}
	}
}