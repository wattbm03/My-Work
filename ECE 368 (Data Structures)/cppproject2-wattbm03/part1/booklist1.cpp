// Please add your name below
// Name: Breeanna Watters 
//ECE368 Data Structures 
// Proj2 part1
// booklist1.cpp: implementation of the booklist class

#include <iostream>
#include "booklist1.h"

// Constructor: initialize head
booklist::booklist() 
{ 
	head = NULL; 
}

// Destructor: traverse booklist and release memory for each node
booklist::~booklist() 
{
	for ( node* p=head; p!=NULL;)  
	{
		node* next = p->next_ptr;
		delete p; 
		p = next;
	}
}

// Print out information of books in booklist
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
	//------------------------------------------------------
	// TO-DO: Go through the booklist and search by given id
	// ------
	//  Make sure to handle the following cases:
	//	1. There is no node with the matching id
	//  2. A node with matching id is found	
	node* probe = head; // sets probe to head
    while ( probe != NULL ) // while probe not null
     {
       if( probe->book_ptr->get_id() == bookid ) // if probe reaches the id 
	   {
           break; // goes to return
	   }
       probe = probe->next_ptr; // moves probe to next one
     }
	if(probe==NULL) // if probe is at null
	{
    	return NULL; //return zero 
	}
   return probe->book_ptr;	// returns location of probe of that id
}
// Add a new book to the booklist
void booklist::add_book(book* b) 
{
	//--------------------------------------------------
	// TO-DO: Create a new node, store the node pointer, 
	//        then add the node to the end of booklist 
 node *newNode = new node(b);
   if ( head == NULL )// head will become the "new node" is head is empty.
   {
       head = newNode;
   }
   else
   {
       node* probe = head;
       while ( probe->next_ptr != NULL )// works when ptr_next does not equal null
          probe = probe->next_ptr; // moves probe to the next value
        probe->next_ptr = newNode; // set pointer to newNode
   }
}
// Remove a book from the booklist
//   Return true if found; otherwise return false
bool booklist::remove_book(unsigned int bookid) 
{
	//--------------------------------------------------
	// TO-DO: Remove a book node by bookid
	// ------
	//  Make sure to handle the following cases:
	//	1. There is no node with the matching id
	//  2. Node is found, and it is the head node
	//  3. Node is found, and it is not the head node
   if ( search_by_id(bookid) != NULL ) 
   {
       if ( head->book_ptr->get_id() == bookid ) // tests to see if the node is the head node and moves head node.   
	    {
           node *temp = head; // makes temp node the head node
           head = head->next_ptr; //points to new head pointer
           delete temp; // delete temp memory
           return true; // returns if done correctly
       }
       node *curr = head; //makes ptr of current and prev set to head value.
       node *prev = head;
       while ( curr->next_ptr != NULL )   // to find the node and it is not the head node
		{
           if ( curr->book_ptr->get_id() == bookid )// to say the curr node is the id needed
		   {
               break; // exit if statement to go to return
		   }
           prev = curr; // makes prev move to the current
           curr = curr->next_ptr; // makes the current move to the next 
       }
       if ( curr->next_ptr == NULL )  // if the pointer points to null 
	   {
           prev->next_ptr = NULL; // makes current null
           delete curr; // to delete the empty spot
       }
       else      
	   {
           prev->next_ptr = curr->next_ptr; // else tke prev pointing to next and make it equal to the curr to next
           delete curr; // delete the current
       }
       return true; // returns that it was removed
   }
   return false; // if no id is found	
}