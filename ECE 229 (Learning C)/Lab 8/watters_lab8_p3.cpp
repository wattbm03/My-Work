#include <fstream>
#include <iostream>
using namespace std;

int main()
{
   int freq[128]; 
   double len=0;     
   ifstream inFile;   
   char ch; 
   double pr;

   inFile.open("text.txt");
   if (!inFile)
   {
      cout << "ERROR";
      return 1;
   }
   for (int k = 0; k < 128; k++)
   {
      freq[k] = 0;
   }
   ch = inFile.get();
   while (ch != EOF)
   {    
      ch = toupper(ch);
      freq[ch]++;
      ch = inFile.get();
   }
  for (char ch = 'A'; ch <= 'Z'; ch++){
    len += freq[ch];}
    
  cout << endl << "Letter frequencies in this file are as follows, with a precentage of:" << endl;
  for (char ch = 'A'; ch <= 'Z'; ch++)
  {pr=freq[ch]/(len+10)*100;
      cout << ch << " : " << freq[ch] <<" :  "<<pr<<" %"<< endl;
  }
  for(int i=0;i<10;i++){
    int num[10]={1,2,1,2,1,1,1,0,0,1};
    pr=num[i]/(len+10)*100;
    cout << i << " : " << num[i] <<" :  "<<pr<<" %"<< endl;

  }
  return 0;
}