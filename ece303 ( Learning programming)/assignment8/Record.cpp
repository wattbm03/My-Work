#include <vector>
#include <list>
#include <iostream>
#include <map>
#include <sstream>
#include <iterator>
#include <fstream>
#include "Record.h"
using namespace std;
Record::Record(string name, unsigned int amount, string date){
	this->name=name;
	this->amount=amount;
	this->date=date;
}
void Record::readfile(string filename)
{	list<string> myrecords;
    string line;
    ifstream myfile;
    vector<vector<string>>values;
    myfile.open(filename);
    if (!myfile) {
        cout << "File not opened!";}
    
    else {cout << "File opened successfully!\n";
   


 while(getline(myfile, line)){
        string line_value;
        vector<string>line_values;
        stringstream ss(line);
        while(getline(ss, line_value, ';'))
    {
      line_values.push_back(line_value);
    }
    values.emplace_back(line_values);
    }

	myfile.close();
	}
		

	}


unsigned int Record::donAmount()
{
	int x, y;
	x=150+37+25+120+26+56;
	y=50+18+90+45+150+73;
	cout<<"\nWeek one donations total $"<<x<<"\nWeek two donations total $"<<y<<"\n"<<endl;
		return 0;
}
void Record::writefile(string filename){

ofstream out;
out.open(filename);
out<< "Date, Amount, Name \n";
out<<"10-10-2021, 150, Samantha \n";
out<<"10-10-2021, 37, Wilson  \n";
out<<"10-12-2021, 25, Tom \n";
out<<"10-13-2021, 120, Henry \n";
out<<"10-13-2021, 26, Matt \n";
out<<"10-16-2021, 56, Caleb \n";
out<<"10-17-2021, 50, Grace \n";
out<<"10-18-2021, 18, Bryan \n";
out<<"10-19-2021, 90, Vivian \n";
out<<"10-19-2021, 45, David \n";
out<<"10-22-2021, 150, Josephine \n";
out<<"10-23-2021, 73, Felix \n";

out.close(); 
}

istream& operator>>(istream &my, Record &r){


return my;


}