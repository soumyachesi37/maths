#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
#define ORDER 4
int main()
{
    float ax[MAXN+1],ay[MAXN+1],diff [MAXN+1][ORDER+1],nr=1.0,dr=1.0,x,p,h,yp;
    int n,i,j,k;
    cout<<"Enter the value of n : ";cin>>n;
    cout<<"Enter the values of x,y : ";
    for(i=0;i<=n-1;i++) cin>>ax[i]>>ay[i];
    cout<<"Enter the value of x for which the value of y is needed : ";cin>>x;
    h=ax[1]-ax[0];
    
    //now making the difference table, calculating the 1st order of difference
    
    for(i=0;i<n-1;i++) diff[i][1]=ay[i+1]-ay[i];   
    
    //now calculating the 2nd order and higher order differences
    
    for(j=2;j<=ORDER;j++)
        for(i=0;i<=n+j;i++)
            diff[i][j]=diff[i+1][j-1]-diff[i][j-1];
    
    //now finding x0
    
    i=0;
    while(!(ax[i]>x)) i++;
    
    //now ax[i] is x0 and ay[i] is y0
    
    i--;
    p=(x-ax[i])/h;
    yp=ay[i];

    //now carrying out interpolation
    
    for(k=1;k<= ORDER;k++)
    {
        nr*=p-k+1;
        dr*=k;
        yp+=(nr/dr)*diff[i][k];
    }
    printf("When the value of x is %6.2f the value of y corresponding to it is : %6.2f",x,yp);
    return 0;
}
