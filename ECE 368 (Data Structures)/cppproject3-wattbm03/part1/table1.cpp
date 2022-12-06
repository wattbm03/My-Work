// Please add your name below
// Name: Breeanna Watters
//ECE 368 

// FILE: table1.cpp
// CLASS IMPLEMENTED: ChainTable and QuadTable (see table1.h for documentation)

#include <iostream>
#include "table1.h" 

void ChainTable::insert(string key)
{
	//-----------------------------------------------
	// TO-DO: insert key into the chained hash table 
	// ------
	//   1. use hashcode function to calculate bucket index i
	//	 2. check if key is already in the list at datatable[i];
	//	    - if yes, do nothing 
	//	    - if no, insert key into the list, increment total_records
	unsigned int i = hashcode(key);
  list<string> l = datatable[i];
  list<string>  :: iterator it;
  //variables are used because they are used in other parts of given code
              
  for(it = l.begin();it!=l.end();it++)
  //when l is not biggier than key
  {           
    string temp = *it;
    if(temp==key)
    // if key is already in the program
    {
      return;
    }             
  }
  datatable[i].push_back(key);
  //done so the first in is the main one
  total_records++;  
  // calculates total	
	
	
	
	
}

// visually print table contents 
void ChainTable::print()
{
	cout << "ChainTable content: \n";
	if (total_records==0) 
	{
		cout << "\t Empty!\n";
		return;
	}

	for (unsigned int i=0; i<TABLE_SIZE; i++)
	{	    
		if (datatable[i].empty()) 
			continue;

		cout << "\t Entry " << i << ": "; 
		for (list<string>::iterator it = datatable[i].begin(); it != datatable[i].end(); it++)
		{
			cout << (*it) << " -> ";
		}
		cout << "NULL\n";
	}
}

//////////////////////////////////////////////////
void QuadTable::insert(string key)
{
	//--------------------------------------------------------------
	// TO-DO: insert key into the hash table using quadratic probing
	// ------
	//   1. if hash table is full, do nothing and return
	//	 2. use hashcode function to calculate array index i
	//	 3. check if datatable[i] is empty
	//	    - if yes, insert key at datatable[i]
	//	    - if no, use quadratic probing until an empty location is found
	//		  insert key at that location
	//	 4. increment total_records
	//	 Note if key is already in the table, do nothing
unsigned int i = hashcode(key);
if(full())
  //if the table is full end
{
  return ;
}
  
if(datatable[i].empty())
  //if empty add in
{
  datatable[i] = key;
  total_records++;
  return ;
}
int new_index = i;
int j = 1;
if(datatable[i]==key) return;
//if key is there before incrementing
while(!datatable[new_index].empty())
{ 
  new_index = (i + j*j)%TABLE_SIZE;
  //sets new index
  if(datatable[new_index]==key) return;
  //if key is already in new spots
  j++;
  //increments j by 1
}
datatable[new_index] = key;
//sets new index data to key
total_records++;
  
return;
}

// visually print table contents 
void QuadTable::print()
{
	cout << "QuadTable content: \n";
	if (total_records==0) 
	{
		cout << "\t Empty!\n";
		return;
	}

	for (unsigned int i=0; i<TABLE_SIZE; i++)
	{	    
		if (datatable[i].empty()) 
			continue;

		cout << "\t Entry " << i << ": "; 
		cout << datatable[i] << endl;
	}
}