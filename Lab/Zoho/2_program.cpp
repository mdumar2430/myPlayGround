#include<iostream>

using namespace std;

int maxOf(int,int);

int maxOf(int a, int b){
	if(a>b)
		return a;
	return b;
}

int main(){
	int n = 0, k = 0, max = 0, balance=0, plots =0;
	cout<<"Enter no. of plots:";
	cin>> n;
	int prices[n];
	cout<<"Enter prices of the plots:\n";
	for(int i = 0; i < n; i++){
		cin>>prices[i];		
	}
	cout<<"Enter amount:";
	cin>> k;
	for(int i =0;i<n;i++){
		balance =k;
        plots =0;
		for(int j =i; j<n;j++){
			if(prices[j]>balance){
				continue;
			}
			else{
				balance = balance - prices[j];
				plots++;
			}
		}
		max = maxOf(max, plots); n
	}
	cout<<max;		
}
