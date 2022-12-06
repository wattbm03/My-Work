// Breeanna Watters
#include<iostream>
using namespace std;
 
class Time
{
    private :
        int hour;
        int minute;
        int second;
    public :
        Time(int h = 0, int m  = 0, int s = 0);
        void setTime(int h, int m, int s);
        void print1();
        void print2();
        int sec(int h, int m, int s);
        bool equals(Time);
};
 
Time :: Time(int h, int m, int s)
{ hour = h;
    minute = m;
    second = s; 
   
}
 
void Time :: setTime(int h, int m, int s)
{int i;
    hour = h;
    minute = m;
    second = s; 
   
  if(s<60)
  {second = s;}
  else 
  {second=s%60;
  i=s/60;
  m=m+i;}
  if(m<60)
  minute=m;
  else{minute=m%60;
  i=m/60;
  h=h+i;}
    hour = h;     
}        
void Time :: print1()
{
    cout << "t1 equals "<< hour << ":"
        << minute << ":"
         << second << "\n";    
}
 void Time :: print2()
{
    cout << "t2 equals "<< hour << ":"
        << minute << ":"
         << second << "\n";    
}
int sec(int h, int m, int s)
{
  int tSec;
  tSec = s+(m*60)+(h*60*60);
  return tSec;
}

bool Time :: equals(Time otherTime)
{
    if(hour == otherTime.hour && 
        minute == otherTime.minute && 
        second == otherTime.second)
        return true;
    else
        return false;
}
 
int main()
{int h, m, s, Total1, Total2, diff;
cout <<"Input hours, minutes, and seconds:\n";
cin>>h>>m>>s;
    Time t1, t2;
    t1.setTime(h, m, s);
    Total1=sec( h,  m,  s);
    t1.print1();
    
    cout <<"Input hours, minutes, and seconds for time 2:\n";
    cin>>h>>m>>s;  
    t2.setTime(h, m, s); 
    Total2=sec( h,  m,  s);
    t2.print2(); 
    if(Total1>Total2)
    diff=Total1-Total2;
    else
      diff=Total2-Total1;
  cout << "\n"<<"The difference is "<< diff<<" seconds"<<endl;
    if(t1.equals(t2))
        cout << "Two objects are equals\n";
    else
        cout << "Two objects are not equals\n";    
  
    return 0;}
