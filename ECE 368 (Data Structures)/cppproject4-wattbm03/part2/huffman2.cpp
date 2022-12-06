// Please add your name below
// Name: Breeanna Watters
//ECE 368 Data Structures proj 4 part 2

// FILE: huffman2.cpp
#include "node.h"

#include <fstream>
#include <list>
#include <string>
#include <cassert>
#include <cctype>

// Depth First Search traversal method implementation
void DepthFirstSearch( node* root, string code, string (&codearray)[26] )
{
	if ( root->left )
    {
      DepthFirstSearch(root->left, code + "0", codearray);
    }
	
	if ( root->right )
    {
      DepthFirstSearch(root->right, code + "1", codearray);
    }
    
	if ( root->is_leaf() )
    {
      codearray[static_cast<int>(root->letter - 'A')] = code;
      return;
    }
}

int main()
{
//////////////////////   Read Probability Data   /////////////////////

	// Open the probability file for reading
	string probfilename = "probability.txt";
	ifstream probfile;
	probfile.open(probfilename.c_str(), ifstream::in);

	assert(probfile);

	// Read in letters and associated probabilities, create a list of nodes
	list<node*> node_list;
	for ( unsigned int n=0; !probfile.eof(); n++ )
	{
		char c;
		double p;
		probfile >> c >> p;
		node* newnode = new node(toupper(c), p);
		node_list.push_back(newnode);
	}

	// Close the probability file
	probfile.close();
	
///////////////////   Construct Huffman Coding Tree ////////////////////

	while ( node_list.size() > 1 ) 
	{		
		//-------------------------------------
		// Include implementation from Part 1
		//--------------------------------------

    // Sort node_list in ascending order of probability
		node_list.sort(comp_prob);

    // Extraction and removal of the 1st node with the lowest prob
		node* firstnode = node_list.front();
    node_list.pop_front();

    // Extraction and removal of the the 2nd node with the 2nd lowest prob
		node* secondnode = node_list.front();
    node_list.pop_front();

    // Merge and insertion phase
		node* newnode = new node(firstnode, secondnode); 
    newnode->letter = '\0';
    node_list.push_back(newnode);		
	}

		
///////////////////   Generate Huffman Codes ////////////////////////

	//-------------------------------------
	// Include implementation from Part 1 
	//-------------------------------------

  // Huffman tree root retrieval
	node* root = node_list.front();
  node_list.pop_front();

  // Creation of string array, codearray[26]
  string codearray[26];
	  
  // Depth First Search traversal 
  DepthFirstSearch(root, "", codearray);

  // Code print out for each letter
  for ( char ch='A'; ch<='Z'; ++ch )
  {
    cout << ch << "\t" << codearray[static_cast<int>(ch - 'A')] << endl;
  }	
		
	
/////////////////////////   Encode Input File   ////////////////////////////////

	// Open the text file for reading
	string textfilename = "input.txt";
	ifstream textfile;
	textfile.open(textfilename.c_str(), ifstream::in);

	assert(textfile);

	// Open the file for writing encoded text
	string encodedfilename = "encoded.txt";
	fstream encodedfile;
	encodedfile.open(encodedfilename.c_str(), fstream::out | fstream::in | fstream::trunc);

	assert(encodedfile);
	
	if ( encodedfile.is_open() )
	{
		// Input and encode each character from the input file one by one
		// and output them to the output file
		while ( !textfile.eof() ) 
		{
			// Read the character and convert it to uppercase
			char c;
			textfile.get(c);
			c = toupper(c);
			if ( ( c >= 'A') && (c <= 'Z') )
			{      
				//-----------------------------------------
				// TODO: 
        // Find the code string s for character c
        //-----------------------------------------
				
        // declare 's' as string
        string s;

        // alphabet letter verification [a-z]
        // replace some given letter with its respective code
        if ( isalpha(c) )
				{
					s += codearray[static_cast<int>(c - 'A')];
				}
				
				if (!s.empty())
					encodedfile << s;
        
				else 
				{
					cout << "Error: cannot find the code for " << c << endl;
					return 0;
				}
			}

			else 
				encodedfile << c;
		}
	} 
	else
	{
		cout << "Error: output file cannot be opened!\n";
		textfile.close();
		return 0;
	}

	// Close the text file
	textfile.close();

//////////////////////// Decode the Encoded File ///////////////////////////

	// Reset the encoded text file for reading
	encodedfile.clear();
	encodedfile.seekg(0, ios::beg);

	// Open the file for writing decoded text
	string decodedfilename = "decoded.txt";
	ofstream decodedfile;
	decodedfile.open(decodedfilename.c_str(), ofstream::out);

	assert(decodedfile);

	if ( decodedfile.is_open() )
	{
		node* currentnode = root;
    while ( !encodedfile.eof() )
		{             
			char c;
			encodedfile.get(c);
			
			if ( (c != '0') && (c != '1') )
			{
				decodedfile << c;
				continue;
			}
			
			//------------------------------------------------
			// TODO: 
      // Using the Huffman tree, keep reading or 
			// converting the code to the matching character 
			// and print to decodedfile
      //------------------------------------------------
      


      // TWO CASES
      
      // Case 1:
      // If our character equals to 0, left traversal is triggered
			if ( c == '0' )
			{
				currentnode = currentnode->left;
			}
      
      // Case 2:
      // If our character equals to 1, right traversal is triggered
      if ( c == '1' )
			{
				currentnode = currentnode->right;
			}
		
			
      // Print specified letter to our decode file
      if (currentnode->letter != '\0')
			{
				decodedfile << currentnode->letter;
				currentnode = root;
			}
		}
	}
	else 
	{
		cout << "Output decoded file cannot be opened!\n";
		encodedfile.close();
		return 0;
	}

	// Close the input and output files for decoding
	encodedfile.close();
	decodedfile.close();

	//----------------------------------------
	// TODO: 
  // Delete all the node objects
  // Please call clean(root), where root is 
  // the root node of the huffman tree  
	// ----------------------------------------
  clean(root);
    
	return 0;
}