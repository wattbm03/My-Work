// Please add your name below
// Name: Breeanna Watters 
// ECE 368

// FILE: table2.cpp
// CLASS IMPLEMENTED: ChainTable and QuadTable (see table2.h for documentation)

#include <iostream>
#include "table2.h" 

void ChainTable::insert(string key)
{
	//--------------------------------------------------------------
	// TO-DO: insert key into the chained hash table 
	// ------
	//   Modify from the implementation from part 1
	//   1. use hashcode function to calculate bucket index i
	//	 2. check if key is already in the list at datatable[i];
	//	    - if yes, increment the count by 1 
	//	    - if no, create a Record object from key and insert into 
	//				the list, increment total_records
  unsigned int i = hashcode(key);
  bool exists = false;
  //sets extists to false
  for (auto it = datatable[i].begin(); it != datatable[i].end(); ++it)
  //goes through the datatable from begining to end
  {
    if ( it->key == key )
	//if the key is already in table add to count
    {
      exists = true;
      it->count++;
      break;
    }
  }
  if ( not exists )
  //if not in table add to table then increment total records
  {
    datatable[i].push_back( Record(key, 1) );
    total_records++;
  }			
}

// print the Record with the highest count
void ChainTable::print_max()
{
	//-------------------------------------------------------------
	// TO-DO: go through the hash table, 
	//		find the record with the highest count, 
	//		and print out the information.
	// ------
	//   You can use ChainTable::print() from part 1 as a reference
	Record max_rec;
 	for ( unsigned int i=0; i < TABLE_SIZE; i++ )
	//in the table
 	{
    	if ( datatable[i].empty() )
		// if empty go on
    	{
    	  continue;
    	}    
    	for ( const auto value: datatable[i] )
		// when data value in table set max count
    	{
     		if ( value.count > max_rec.count )
			//to switch if there is a bigger on
      		{
       			max_rec = value;
      		}
    	}
  	}
  	cout << "The word that appears the most is '" << max_rec.key
   	<< "' and it shows up exactly " << max_rec.count 
   	<< " times. While testing in Chaining." << endl; 
   	//prints out the data for alice
}
//////////////////////////////////////////////////
void QuadTable::insert(string key)
{
	//--------------------------------------------------------------
	// TO-DO: insert key into the hash table using quadratic probing
	// ------
	//   Modify from the implementation from part 1
	//	 1. use hashcode function to calculate array index i
	//	 2. check if datatable[i] is empty
	//	    - if yes, create a Record object from key and sotre at datatable[i]
	//	    - if no, use quadratic probing with probe function c(i)=i^2,
	//		  if key is found, increment count; 
	//		  if key is not found, then look for an empty location,
	//		     insert key at that location, set count = 1, increment total_records
	//	 4. if datatable is full and key is new, do nothing and return
	unsigned int i = hashcode(key);
 	if ( full() && datatable[i].key != key )
	//if table is full end
  	{   
    	return;
  	}
  	if ( datatable[i].key == "" && datatable[i].count == 0 )
	//in record, if key empty and count 0 add new record
  	{  
    	datatable[i] = Record(key,1);
    	total_records++;
  	}
	else if(datatable[i].key== key)
	//if key is in the table increment count
  	{
    	datatable[i].count++;
  	}	
  	else
	//if not empty or equal to 0
  	{
    	long unsigned j = 0;
    	int new_index; 
    	while ( true )
    	{   
      		new_index= ( ( i + j * j) % TABLE_SIZE );
			//quadratic index changing
      		if ( datatable[new_index].key == key ) 
			//if new index equals key, add new count
      		{  
        		datatable[new_index].count++;
        		return;
      		} 
      		else if (datatable[new_index].key == "" && datatable[new_index].count == 0)
			// if new index key empty and count is 0, add new record
      		{  
       	 		datatable[new_index] = Record(key,1);
        		total_records++;
        		return ;
      		}      
      		j++;
    	}
  	}	
}

// print the Record with the highest count
void QuadTable::print_max()
{
	//-------------------------------------------------------------
	// TO-DO: go through the hash table, 
	//		find the record with the highest count, 
	//		and print out the information.
	// ------
	//   You can use QuadTable::print() from part 1 as a reference
	Record max_rec;
 	 for ( unsigned int i = 0; i < TABLE_SIZE; i++ )
  	//in the table
  	{
    	if ( datatable[i].key == "" && datatable[i].count == 0 )
		//if empty go on
    	{ 
     	 	continue;
    	}
    	if ( datatable[i].count > max_rec.count )
		//switch the max count record
    	{
     	 max_rec = datatable[i];
    	}    
  	}    
  	cout << "The word that appears the most is '" << max_rec.key 
  	<< "' and it shows up exactly " << max_rec.count 
  	<< " times. While testing in Quadradic." << endl;
  	//prints the output for the quadratic testing of alice.txt
		
}