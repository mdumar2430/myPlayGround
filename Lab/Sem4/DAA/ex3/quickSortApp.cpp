#include"quickSort.h"
int main()
{
	int *a,n,p,q;
	cout<<"\nSorting using QUICK SORT\n";
	cout<<"\nEnter the number of terms needed:";
	cin>>n;
	a=new int[n];
	cout<<"\nNow enter the elements\n";
	for(int i=1;i<=n;i++)
	{
	  cin>>a[i];
	}
	cout<<"\nElements before performing quick sort\n";
	display(a,n);
	cout<<"\nElements after performing quick sort\n";
	p=1;q=n;
	quickSort(a,p,q,n);
	display(a,n);
}
