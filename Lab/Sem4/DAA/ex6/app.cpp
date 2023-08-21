#include<iostream>
#include"Head.h"
using namespace std;
int main()
{
        int r,c,x,y,a[10][10],j;
        cout<<"Enter the row\n";
        cin>>r;
        cout<<"Enter the column\n";
        cin>>c;
        cout<<"Enter the matrix elements\n";
        for(int i=1;i<=r;i++)
        {
                for(j=1;j<=c;j++)
                {
                        cin>>a[i][j];
                }
        }
        cout<<"After the elements are updated by using floyds algorithm\n";
        floyd(a,r,c);
        for(int k=1;k<=r;k++)
        {
                for(j=1;j<=c;j++)
                {

                        cout<<a[k][j];
                        cout<<"\t";
                }
                cout<<"\n";
        }

}