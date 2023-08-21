#include"quickSort.h"
void quickSort(int *a,int p, int q,int n)
{
	int temp; 
	if(p<q)
	{
	  temp = partition(a,p,q,n);
	  quickSort(a,p,temp-1,n);
	  quickSort(a,temp+1,q,n);
	}
}
int partition(int *a,int p,int q,int n)
{
	int pivot,temp1,start=0,end=n;
	pivot = a[p];
	start = p;  //start to move towards RHS
	end = q;   //end to move towards LHS
	while(start < end)
	{
	  while(a[start] <= pivot && start < end)
	  {
	    start = start + 1;
	  }
	  while(a[end] > pivot)
	  {
            end = end - 1;
	  }
	  if(start < end)
	  {
	    temp1 = a[start];
	    a[start] = a[end];
	    a[end] = temp1;
	  }
	}
	a[p]=a[end];
	a[end]=pivot;
	return end;
}
void display(int *a,int n)
{
	for(int i=1;i<=n;i++)
	{
	  cout<<a[i]<<" ";
	}
	cout<<endl;
}
