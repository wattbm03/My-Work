// Please add your name below
// Name: Breeanna Watters

#include <iostream>
#include "Person.h"

// ---------------------------------------------------------------------
// TO-DO: Add implementation of all the member functions of Person class 
// ---------------------------------------------------------------------
Person::Person (string name1, unsigned int age1)
{
    this->name=name1;
    this->age=age1;
}
void Person::setName(string name1)
{
    this->name =name1;
}
string Person::getName() const
{ 
  return this->name;
}
void Person::setAge(unsigned int age1){
    this->age =age1;
}

unsigned int Person::getAge() const
{ 
  return this->age;
}

void Person:: print() const
{
    cout<<"Name is "<< name<< " and age is "<< age<<".\n"<<endl;
}

