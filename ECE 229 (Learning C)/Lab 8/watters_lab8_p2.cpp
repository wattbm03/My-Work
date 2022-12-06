//Breeanna Watters
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
int i=0, r1, r2, Answer, input;
for(i=0; i<10; i++)
{srand(time(NULL));
r1=1+rand()%10;
r2=1+rand()%10;
Answer=r1*r2;
cout<<"What is "<<r1<<" * "<<r2<<"?"<<endl;
cin>>input;
if(input!=Answer){
cout<<"No. Please try again."<<endl;
continue;
}
else
cout<<"Correct!"<<endl;}
  return 0;
}