# include <iostream>

using namespace std;
 
int main()
{
    int a, b, i, j, p;
 
    cout << "Enter lower bound of the interval and then upper: ";
    cin >> a >> b; // Take input

    //cout << "\nPrime numbers between "
      //   << a << " and " << b << " are: ";
      freopen("output.txt","w",stdout);
    for (i = a; i <= b; i++) 
    {
        if (i == 1 || i == 0)
            continue;
        // p variable to tell if prime
        p = 1;
 
        for (j = 2; j <= i / 2; ++j)
         {
            if (i % j == 0) 
            {
                p = 0;
                break;
            }
        }
        // p = 1 means i is prime and p=0 is not
        if (p == 1)
            cout << i << " ";
    }
    return 0;
}