#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

inline bool exists(const string& name) {
    ifstream f("primes".c_str());
    return f.good();}

primes::primes()
{
    CC = g++
    CCOPTS = -g -Wall
    OBJECTS = primes.cpp 

    primes: $(OBJECTS)
	$(CC) $(CCOPTS) $(OBJECTS) -o primes.exe
    primes: primes.cpp
    $(CC) $(CCOPTS) -o primes.cpp
    clean:
	    rm -f *.cpp *.exe
}

int main(){
    ifstream A;
    ifstream B;
    ofstream File3;
    string line,line2;
string name;

A.open("output.txt");
B.open("correct_output.txt");
File3.open("Result.txt");
if(A.fail()){ cerr<<"Error opening file !!"<<endl;exit(1);}
if(B.fail()){ cerr<<"Error opening file !!"<<endl;exit(1);}



while(!A.eof())
  {
        getline(A,line);
    getline(B,line2);
     if(line==line2){
    File3<<"0"<<endl;
     }
     else{
         File3<<"1"<<endl;
    }

  }
ifstream File;
File.open("Result.txt");
File>> name;
cout<< name\n\n<< endl;
cout<<"wattbm03, Existence Y, Complie Y, Compare Y<<endl;

    }



