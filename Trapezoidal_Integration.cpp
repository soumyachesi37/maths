#include <bits/stdc++.h>
using namespace std;
double f(double x)
{
    return (x * x) + (2 * x);
}

void calculate(double a, double b, int n)
{
    double sum=0, integral;
    double h;
    h = fabs (b-a) / n;
    for (int i = 1; i < n; i++) sum += f(a+ i*h);
    integral =(0.5*h)*(f(a) + f(b) + 2*sum); 
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