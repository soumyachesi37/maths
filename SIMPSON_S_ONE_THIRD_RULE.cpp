#include <bits/stdc++.h>
using namespace std;
double f(double x)
{
    return (x * x) + (2 * x);
}

void calculate(double a, double b, int n)
{
    double integral,sum_odd=0,sum_even=0;
    double h;
    h = fabs (b-a) / n;
    for (int i = 1; i < n; i++)
    {
        if(i%2) sum_odd+=f(a+ i*h);
        else sum_even+=f(a+ i*h);
    } 
    integral =(h/3)*(f(a) + f(b) + 2*sum_even + 4*sum_odd); 
    cout<<"The integral for the interval ("<< a << "," << b << ") is " << integral << endl;
}

int main()
{
    int i, n;
    double a, h, b, sum = 0, integral; 
    cout<<"input the limits of the integral and the number of intervals: ";
    cin>>a>>b>>n; 
    h = fabs (b-a) / n;
    for (int i = 1; i <=n; i++) calculate(a, a + h*i,i); 
    return 0;
}