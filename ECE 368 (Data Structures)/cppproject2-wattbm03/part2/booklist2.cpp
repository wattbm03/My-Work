// Please add your name below
// Name: Breeanna Watters
//ECE368 Data Structures 
// Proj2 part2 

// booklist2.cpp: implementation of the booklist class

#include <iostream>
#include "booklist2.h"

// constructor: initialize head
booklist::booklist() 
{ 
	head = NULL; 
}

// destructor: traverse booklist and release memory for each node
booklist::~booklist() 
{
	for ( node* p=head; p!=NULL;)  
	{
		node* next = p->next_ptr;
		delete p; 
		p = next;
	}
}

// print out information of books in booklist
void booklist::list_books() const
{
	// Set output to fixed point, left justified, precision 2
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::left, ios::adjustfield);
	cout.precision(2);

	// Set width of the Book Title label to be 54 characters with blank space fillers
	// to give room for lengthy book titles
	cout.fill(' ');
	cout.width(54);

	cout << "Book Title";

	// Do not impose a width requirement on further outputs
	cout.width(0);
	cout << "Price   " << "Copies  " << endl;

	// Set the width of the underline of the Book Title to 54 characters with blank
	// space fillers to match the text labels
	cout.width(54);
	cout << "----------";

	// Do not impose a width requirement on further outputs
	cout.width(0);
	cout << "-----   " << "------  " << endl;

	//Traverse through the booklist and print the books
	node* probe = head;
	while ( probe != NULL )
	{
		probe->book_ptr->print_info();
		probe = probe->next_ptr;
	}
}


// Search in booklist, find the book with given id
//	 Return the book pointer with matching id; otherwise return NULL
book* booklist::search_by_id(unsigned int bookid) const
{
	//-----------------------------------------------
	// Include implementation from part 1: 

	node* probe = head; 
	// sets probe to head
    while ( probe != NULL ) 
	// while probe not null
    {
    	if( probe->book_ptr->get_id() == bookid ) 
		// if probe reaches the id 
	   {
        	break; 
			// goes to return
	   }
       probe = probe->next_ptr; 
	   // moves probe to next one
    }
	if(probe==NULL) 
	// if probe is at null
	{
    	return NULL; 
		//return zero 
	}
   return probe->book_ptr;	
   // returns location of probe of that id	
}

// Calculate and return total price of the books in the booklist
double booklist::calculate_total_price() const
{
	//-----------------------------------------------
	// TO-DO: Go through the booklist and add total 
	//        price of all the books in the list
	// ------
	//   Make sure to multiply the unit price by number of copies

	double totalPrice = 0;  
	//sets variable
 	node* probe = head; 
	// points probe to the head
	while ( probe != NULL )
	// when probe not null
    {
       totalPrice = totalPrice + (probe->book_ptr->get_price()*probe->book_ptr->get_copies());
	   //takes totalprice and adda the multiplication of price and copies

       probe = probe->next_ptr;
	   //moves pointer to spot
    }
   return totalPrice; 
   //returns the final price	
}

// Add a new book to the booklist
void booklist::add_book(book* b) 
{
	//-----------------------------------------------
	// Include implementation from part 1: 

	node *newNode = new node(b);
	if ( head == NULL )
	// head will become the "new node" is head is empty.
	{
    	head = newNode;
	}
   else
   {
    	node* probe = head;
    	while ( probe->next_ptr != NULL )
		// works when ptr_next does not equal null
        {
			probe = probe->next_ptr; 
			// moves probe to the next value
		}
        probe->next_ptr = newNode; 
		// set pointer to newNode
   }	
}

// Remove a book from the booklist
//   Return true if found; otherwise return false
bool booklist::remove_book(unsigned int bookid) 
{
	//-----------------------------------------------
	// Include implementation from part 1: 

	if ( search_by_id(bookid) != NULL ) 
   {
       if ( head->book_ptr->get_id() == bookid ) 
	   // tests to see if the node is the head node and moves head node.   
		{
           node *temp = head; 
		   // makes temp node the head node
           head = head->next_ptr; 
		   //points to new head pointer
           delete temp; 
		   // delete temp memory
           return true; 
		   // returns if done correctly
    	}
       node *curr = head; 
	   //makes ptr of current and prev set to head value.
       node *prev = head;
       while ( curr->next_ptr != NULL )   
	   // to find the node and it is not the head node
		{
           if ( curr->book_ptr->get_id() == bookid )
		   // to say the curr node is the id needed
		   {
               break; 
			   // exit if statement to go to return
		   }
           prev = curr; 
		   // makes prev move to the current
           curr = curr->next_ptr; 
		   // makes the current move to the next 
       }
       if ( curr->next_ptr == NULL )  
	   // if the pointer points to null 
	   {
           prev->next_ptr = NULL; 
		   // makes current null
           delete curr; 
		   // to delete the empty spot
       }
       else      
	   {
           prev->next_ptr = curr->next_ptr; 
		   // else tke prev pointing to next and make it equal to the curr to next
           delete curr; 
		   // delete the current
       }
       return true; 
	   // returns that it was removed
   }
   return false; 
   // if no id is found	
}

// Search in booklist, find the book with given id, and add copies
//   return false if book with specified id cannot be found
bool booklist::add_book_copies(unsigned int bookid, unsigned int copies) 
{
	//-----------------------------------------------------
	// TO-DO: Add copies to the book with specified bookid
	// -----
	//  You can call the search_by_id function
	//  If book is found, then add copies;
	//  If not found, return false

	book *temp = search_by_id(bookid);
	// to point temp to id
	if ( temp != NULL )  
	// needed to tell if it is null 
	{      
    	int newCopies = copies + temp->get_copies();
		//calculates new copies
    	temp->set_copies(newCopies);
		//sets new amount of copies
    	return true;
		//if book is there
	}
	return false; 
	// if book is not there	
}

// Search in booklist, find the book with given id, and remove copies
//   return false if book with specified id cannot be found; or
//   the book with specified id is found but not enough copies to be removed
bool booklist::remove_book_copies(unsigned int bookid, unsigned int copies)
{
	//-----------------------------------------------------
	// TO-DO: Remove copies from the book with specified bookid
	// -----
	//  You can call the search_by_id function
	//  Make sure to handle the following cases:
	//   1. If book is found and with more copies, then reduce copies
	//   2. If book is found and the exact number of copies, remove the book from the list
	//   3. If book is found and not enough copies, return false
	//   4. If not found, return false
	
	book *temp = search_by_id(bookid);
	//searches for book id
	if ( temp != NULL && temp->get_copies()>=copies ) 
	{
    	int newCopies = temp->get_copies() - copies; 
		//calculates new copies
    	temp->set_copies(newCopies);
		//sets new copies
    	return true;
		//book there
	}
	return false; 
	//book not there
}


