// Please add your name below
// Name: Breeanna Watters
//ECE368 Data Structures 
// Proj2 part2

// storeUI.cpp: A user interactive program for the bookstore
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cassert>
#include <sstream>
#include "book.h"
#include "booklist2.h"

using namespace std;

// PROTOTYPES for functions used by main
void fill_catalog(booklist& books, string bookfilename);
void print_menu();
char get_choice( );
void checkout(const booklist& books);

int main( )
{
  unsigned int id = 0, copy = 0; // initialize the given data to be inserted
  string name;
  double price;
  
	booklist catalog; // a book catalog for the book store
	booklist cart; // a list of books in the cart

	// Fill the list of books with the default catalog of books
	fill_catalog(catalog, "booklist.txt");

	// Print the menu
	cout << "Welcome to BookSea\n";
	print_menu();

	// Read in choice until the user inputs 'Q' or 'q'
	char choice;
	do
	{
		choice = toupper(get_choice( ));
		switch (choice)
		{
			// Perform the command entered by the user
			case 'L':
			{
				// List the books in the catalog
				catalog.list_books();
				
				// Print the menu
				print_menu();
				
				break;
			}
			case 'A':   
			{
				// Get the book ID of the book to be added
				unsigned int add_book_id;
				cout << "Book ID? ";
				cin >> add_book_id;
				assert(add_book_id>0);

				// Get the number of copies
				unsigned int addcopies;
				cout << "How many copies? ";
				cin >> addcopies;
				assert(addcopies>0);

				//----------------------------------------------------------
				// TO-DO: Search the book in the catalog and add to the cart
				// ------
				// Make sure to handle the following cases:
				//  1. if id not found in catalog
				//  2. If id found in catalog, but not enough copies
				//  3. If id found in catalog, update both cart and catalog
				//	   	In addition, if all copies are added to the cart, then 
				//		the book should be removed from the catalog
				book* bookfound = catalog.search_by_id(add_book_id);
				//sets new point to id of book
       			if (bookfound!=NULL)
				//checks if there
        		{
          			if(addcopies<=bookfound->get_copies())
					//if copies being added are less or equal to copies in Catalog
          			{
           				id=bookfound->get_id();
           				name=bookfound->get_title( );
           				price= bookfound->get_price(); 
            			book *book1 = new book(id, name, price, addcopies);
						//sets new book id from catalog
            			if(cart.search_by_id(id) != NULL)
						//checks to see if in cart, if it is
              			{
                			book* bookfound2 = cart.search_by_id(id);
							//points to data already in cart
                			copy=addcopies+bookfound2->get_copies();
							//calculates new copy
               	 			book *book2 = new book(id, name, price, copy);
							//creates the new book
                			cart.remove_book(id);
							//remove book from cart to re-add with new copies
                			cart.add_book(book2);
              			}
            			else
						//if not in cart add the book
            			{
              				cart.add_book(book1);            
            			}
            			catalog.remove_book_copies(id, addcopies);
						//remove the book copies from catalog
            			book* bookfound3 = catalog.search_by_id(add_book_id);
            			if(bookfound3->get_copies() == 0)
						//if copies in catalog = 0 rmove that book
            			{
              				catalog.remove_book(id);
            			}
          			}           
          			else
          			{
           				cout<<"\n\n\n\n\nNot enough copies in Catalog!!\n\n\n\n\n";
						//test that it is not enough copies in Catalog
          			}				
        		}
        		else 
        		{
			    	cout << "\n\n\n\n\nBook not found in Catalog!\n\n\n\n\n";
					//test that it is not in Catalog
        		}
				// Print the cart content
				cout << "\nItems in cart:\n" << endl;
				cart.list_books();

				// Print the menu
				print_menu();
				
				break;
			}
			case 'R':   
			{
				// Get the book ID of the book to be removed
				unsigned int remove_book_id;
				cout << "Book ID? ";
				cin >> remove_book_id;
				assert(remove_book_id>0);
                
				// Get the number of copies
				unsigned int removecopies;
				cout << "How many copies? ";
				cin >> removecopies;
				assert(removecopies>0);
				
				//----------------------------------------------------------
				// TO-DO: Search book in the cart and return to the catalog
				// ------
				// Make sure to address the following cases:
				//  1. if id not found in cart
				//  2. If id found in cart, but not enough copies
				//  3. If id found in cart, update both cart and catalog
				//	   	In addition, if all copies are removed from the cart, then 
				//		the book should be removed from the cart;
				//		Also, if catalog does not already have the corresponding 
				//		book entry, a new book record (node) should be added

				book* bookfound = cart.search_by_id(remove_book_id);
				if (bookfound!=NULL)
				//checks if there
				{
					if(removecopies<=bookfound->get_copies())
					//if copies less then or equal
					{
						id=bookfound->get_id();
						name=bookfound->get_title( );
						price= bookfound->get_price(); 
						book *book1 = new book(id, name, price, removecopies);
						//sets new book 
						if(catalog.search_by_id(id) != NULL)
						//if book there in catalog
						{
							book* bookfound2 = catalog.search_by_id(id);
							copy=removecopies+bookfound2->get_copies();
							book *book2 = new book(id, name, price, copy);
							catalog.remove_book(id);
							catalog.add_book(book2);
							//adds new book in catalog because not in catalog
						}
						else
						//if not in catlog add the book
						{
							catalog.add_book(book1);            
						}
						cart.remove_book_copies(id, removecopies);
						//remove the book copies from cart
						book* bookfound3 = cart.search_by_id(id);
						if(bookfound3->get_copies() == 0)
						//if copies in cart = 0 rmove that book
						{
							cart.remove_book(id);
						}
					}
					else
					{
						cout<<"\n\n\n\n\nNot enough copies in Cart!!\n\n\n\n\n";
						//test that it is not enough copies in Cart
					}				
				}
				else 
				{
					cout << "\n\n\n\n\nBook not found in Cart!\n\n\n\n\n";
					//test that it is not in Cart
				}
				// Print the cart content
				cout << "\nItems in cart:" << endl;
				cart.list_books();
				
				// Print the menu
				print_menu();
				
				break;
			}
			case 'C':
			{
				// Check out and show the total price and savings
				checkout(cart);
				return 0;
			}
			case 'Q':
			{
				cout << "Goodbye!" << endl;
				break;
			}
			default:
				cout << choice << " is not a valid input." << endl;
		}
	} while (choice != 'Q');

	return 0;
}


// Read from book list and create book catalog
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

// Print menu options
void print_menu() 
{
	// Display the menu of commands 
	cout << "=========================" << endl;
	cout << "Menu:" << endl;
	cout << "[L]ist all books" << endl;
	cout << "[A]dd a book to cart" << endl;
	cout << "[R]emove a book from cart" << endl;
	cout << "[C]heckout" << endl;
	cout << "[Q]uit" << endl;
	cout << "=========================" << endl;
}

// Read the command choice of the user
char get_choice( ) 
{
	// Get input command and return the input character
	char command;
	cout << "\nCommand: ";
	cin >> command;
	return command;
}

// Calculate and display the total cost and savings of the books in cart
void checkout(const booklist& books) 
{
	// Output the items in the cart
	cout << "Items in cart:";
	books.list_books();

	// Add up the total price and sale savings
	double total_price = books.calculate_total_price();

	cout << "Total price: $" << total_price << endl;
	cout << "Thanks for shopping with BookSea!" << endl;
	cout << "Goodbye!" << endl;
}