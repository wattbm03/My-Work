// Please add your name below
// Name: Breeanna Watters
//ECE 368 Data Structures proj 4 part 1

// FILE: huffman1.cpp
//   This file reads the probabilities of 26 English characters and 
//   build a Huffman tree and the corresponding Huffman code for each character.

#include <fstream>
#include <list>
#include <string>
#include <cassert>
#include "node.h"


void DFS( node* root, string code, string (&codearray)[26] )
//code to make the code for the probabilities of the alpheabet
{
  	if ( root->left ){DFS(root->left, code + "0", codearray);}
  	if  ( root->right ){DFS(root->right, code + "1", codearray);} 
  	if ( root->is_leaf() )
  	{
    	codearray[static_cast<int>(root->letter - 'A')] = code;
    	return;
  	}
}

int main()
{
////////////////////// Read Probability Data /////////////////////

	// Open the probability file for reading
	string probfilename = "probability.txt";
	ifstream probfile;
	probfile.open(probfilename.c_str(), ifstream::in);

	assert(probfile);

	// Read in letters and associated probabilities, create a list of nodes
	list<node*> node_list;
	for (unsigned int n=0; !probfile.eof(); n++)
	{
		char c;
		double p;
		probfile >> c >> p;
		node* newnode = new node(toupper(c), p);
		node_list.push_back(newnode);
	}

	// Close the probability file
	probfile.close();
	
/////////////////// Construct Huffman Coding Tree ////////////////////

	while ( node_list.size() > 1 ) 
	{		
		//---------------------------------------------------------------------
		//  TODO: Repeat the following...
		// --------------------------------------------------------------------
		//  - Sort node_list in ascending order of probability, can be done by: 
		//	  node_list.sort(comp_prob);
		//	- Extract the two nodes with the lowest probabilities, 
		//	  remove them from node_list, merge them to create a new node,
		//	  and insert the new node back into the list.
    
		node_list.sort(comp_prob);
		//comp prob compares the probability of the list
		node* first = node_list.front();
		// makes list front of first node
    	node_list.pop_front();
		//pops off the front data
		node* second = node_list.front();
    	node_list.pop_front();
		node* newnode = new node(first, second); 
		//makes new node
    	newnode->letter = '\0';
		//points newnode to the letter
    	node_list.push_back(newnode);	
		//pushes the newnode back into stack	
	
	}
	
/////////////////// Generate Huffman Codes ////////////////////////

	//------------------------------------------------------------------------
	//  TODO: Traverse the huffman tree to generate the huffman coding table.   
	// -----------------------------------------------------------------------
	// 	- Please create a string array, e.g., string codearray[26], 
	//	  to store the code string of each English character
	//  - Please also print out the code for each letter here
	

	node* root = node_list.front();
	//makes root in new list
    node_list.pop_front();
	//pops front of list for data
    string codearray[26];
    //sting array for the code
  
    DFS(root, "", codearray);
    //runs the traversal code for the root
    for ( char ch='A'; ch<='Z'; ++ch )
    //prints the letters out with there code
    {
      cout << ch << "\t" << codearray[static_cast<int>(ch - 'A')] << endl;
    }

  //---------------------------------------------
	//  TODO: Delete all the node objects.
	// --------------------------------------------
	// 	Please call clean(root), where root is the 
	//  root node of the huffman tree.
  
	clean(root);	
	return 0;
}