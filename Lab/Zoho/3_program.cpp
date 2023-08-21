#include<iostream>

using namespace std;
void findMaxPos(int[], int);
int main(){
	int n, maxpos=0,max=0;
	cout<<"Enter size:";
	cin>>n;
	int arr[n];
	cout<<"Enter numbers:\n";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<n;i++)
	{
		if(arr[i]>max){
			maxpos = i;
			max = arr[i];
		}
	}
	cout<<"Smallest number = "<<arr[++maxpos];
}
