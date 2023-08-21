#include"Head.h"
int min(int x,int y)
{
        if(x>y)
                return y;
        else
                return x;
}
int floyd(int d[10][10],int r,int c)
{
        for(int k=1;k<=r;k++)
        {
                for(int i=1;i<=r;i++)
                {
                        for(int j=1;j<=c;j++)
                        {
                                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                        }
                }
        }
}