// Please add your name below
// Name: Breeanna Watters
//ECE368 Data Structures 
// Proj2 part1

// FILE: catalog.cpp
//  This file reads from a booklist text file, prints the catalog,
//  then print a book's information given user input book id

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cassert>
#include <sstream>
#include "book.h"
#include "booklist1.h"

using namespace std;

// PROTOTYPE for functions used by main()
void fill_catalog(booklist& books, string bookfilename);

int main( )
{
	booklist catalog; 

	// Fill the catalog with books information
	fill_catalog(catalog, "booklist.txt");

	// Print the catalog
	cout << "Welcome to BookSea\n";
	catalog.list_books();

	// Test search_by_id
	char choice;
	cout << "Test search by book id? [y/n] ";
	cin >> choice;
	while (choice == 'y' || choice == 'Y')
	{
		// enter book id
		unsigned int bookid;
		cout << "Please enter a book id: ";
		cin >> bookid;
	
		book* bookfound = catalog.search_by_id(bookid);
	
		if (bookfound!=NULL) {
			cout << "Book found: \n";
			bookfound->print_info();
			
			cout << "Remove from the list? [y/n] ";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				// test remove_book
				if (catalog.remove_book(bookid)) {
					cout << "This book is successfully removed\n";
					cout << "Updated catalog: \n";
					catalog.list_books();
				}
				else
				{
					cout << "Cannot remove this book from catalog.\n";
					break;
				}
			}
		}
		else {
			cout << "Book not found!\n";
		}
		
		cout << "Search another book by id? [y/n] ";
		cin >> choice;
	} 
	
	return 0;
}

// Creates the default book catalog
void fill_catalog(booklist& books, string bookfilename)
{
	unsigned int id = 0, copy = 0; // initialize the given data to be inserted
  	string name;
  	double price;
  	string rawLine; // set string for 1st getline
	
	// Open the booklist file for read
	ifstream bookfile;
	bookfile.open(bookfilename.c_str(), ifstream::in);
	assert(bookfile);
	
	while (!bookfile.eof())
	{
		while(getline(bookfile,rawLine,'\n')) // reads line by line
    	{
			istringstream line{rawLine}; // used to set the read individual things in a line
			string element; // adds a string to read each element
			getline(line, element, '\t'); // reads first element
			id = stoul(element); // sets id as first element by changing string to unsigned int
			getline(line, element, '\t'); // reads next element
			name = element; // sets name 
			getline(line, element, '\t'); // reads next element
			price = stod(element); // sets price by changing string to double
			getline(line, element, '\t'); // reads final element
			copy = stoul(element); // sets copies by changing string to unsigned int
			book *book1 = new book(id, name, price, copy); // makes new book and inputs the elements
			books.add_book(book1); // adds book to catalog
    	}
	}
	bookfile.close(); // close file
}
