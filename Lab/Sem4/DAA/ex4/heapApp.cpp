#include"heapHead.h"
int main()
{
	int *arr,n,i;
	cout<<"\nThis application uses HEAPSORT to sort the elements\n";
	cout<<"Enter number of elements:";
	cin>>n;
	arr=new int[n];
	cout<<"Enter the required elements\n";
	for(i=0;i<n;i++)
	{
	  cin>>arr[i];
	}
	heapSort(arr, n);
	cout<<"Sorted array  \n";
	display(arr, n);
}
