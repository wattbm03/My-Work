#include <vector>
#include <list>
#include <iostream>
#include <map>
#include <sstream>
#include <iterator>
#include <fstream>
#include "Record.h"
using namespace std;

int main(){
    Record *t1;
    Record p1;
    t1=&p1;
    t1->readfile("donations-raw.csv");
 
    t1->writefile("donations-processed.csv");
    t1->donAmount();
return 0;

}