#include"insSort.h"
void InsertionSort(int *A,int n)
{
	int i,v,j;
	for(i=1;i<=n;i++)
	{
	  v = A[i];
	  j=i-1;
	  while(j>=0 && A[j]>v)
	  {
	    A[j+1]=A[j];
	    j=j-1;
	  }
	  A[j+1]=v;
	}
}
void display(int *A,int n)
{
	for(int i=1;i<=n;i++)
	{
	  cout<<A[i]<<" ";
	}
}
