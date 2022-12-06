#ifndef RECORD_H
#define RECORD_H
#include <vector>
#include <list>
#include <iostream>
#include <map>
#include <sstream>
#include <iterator>
#include <fstream>
#include "Record.h"
using namespace std;

class Record{

private:
    string name;
    unsigned int amount;
    string date;
   
public:   
    Record(){};
    ~Record(){};
    Record(string name, unsigned int amount, string date);
    void readfile(string filename);
    unsigned int donAmount();
    void writefile(string filename);
    
};
istream& operator>>(istream &my, Record &r);
#endif