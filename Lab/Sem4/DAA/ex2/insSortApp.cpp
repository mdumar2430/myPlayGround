#include"insSort.h"
int main()
{
	int *A,n,i;
	cout<<"\nThis application performs 'INSERTION SORT' for a given array";
	cout<<"\nNow enter the required number of terms:";
	cin>>n;
	A=new int[n];
	cout<<"\nNow enter the values one by one\n";
	for(i=1;i<=n;i++)
	{
	  cin>>A[i];
	}
	cout<<"\nArray before performing insertion sort\n";
	display(A,n);
	InsertionSort(A,n);
	cout<<"\nArray after performing insertion sort\n";
	display(A,n);
	cout<<endl;
}
