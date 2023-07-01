#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return cos(x)-x*exp(x);
}

int main()
{
    cout<<"Enter the end points of the interval (a,b) : ";double a,b,root;cin>>a>>b;
    cout<<"Enter the tolerable error value ";double t;cin>>t;
    if(f(b)*f(a)>0)
    {
        cout<<"Incorrect Interval. No root found in the given interval"<<endl;
        return 0;
    }
    cout<<"Root of the given equation in the interval ("<<a<<","<<b<<") with tolerable error of "<<t<<" is ";
    while ((b-a) >= t)
    {
      root = (a+b)/2;
      if (f(root) == 0.0)
         break;
      else if (f(root)*f(a) < 0)
         b = root;
      else
         a = root;
    }
    cout <<root<<endl;
    return 0;
}