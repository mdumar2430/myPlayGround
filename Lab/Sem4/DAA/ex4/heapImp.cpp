#include"heapHead.h"
void heapArrange(int arr[], int n, int i)
{
	int largest=i;
	int l = 2*i +1;
	int r = 2*i +2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		heapArrange(arr,n,largest);
	}
}

void heapSort(int arr[], int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapArrange(arr, n, i);
	for (int i = n - 1; i >= 0; i--) {
		int t=arr[0];
		arr[0]=arr[i];
		arr[i]=t;
		heapArrange(arr,i,0);
	}
}

void display(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}
