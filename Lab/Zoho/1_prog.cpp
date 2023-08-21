#include <iostream>
#include <Cstring>
using namespace std;

int main(){
	int r = 0, c =0, count =0, a, b;
	cout<<"Enter no. of rows:";
	cin>> r;
	cout<<"Enter no. of cols:";
	cin>>c;
	char grid[r][c];
	cout<<"Enter grid:\n";
	for(int i =0; i<r; i++){
		for(int j =0; j<r; j++){
			cin>>grid[i][j];
		}
	}
	cout<<"Enter the word:";
	char key[20]="";
	cin>>key;
	for(int i =0; i<r; i++){
		a = i;
		for(int j=0; j<c; j++){
			b = j;
			if(grid[i][j] == key[0]){
				count =1;
				for(int k=1; k<strlen(key)-1; k++){
					if(grid[a+1,j] == key[k]){
						count++;
						a=a+1;
					}
					else if(grid[a-1,j]== key[k]){
						a = a-1;
						count++;
					}
					else if(grid[i,b-1] == key[k]){
						b = b-1;
						count++;
					}
					else if(grid[i,b+1] == key[k]){
						b = b+1;
						count++;
					}
					else
						break;
				}
			}
		}
	}
	if(count == strlen(key))
		cout<<"True";
	else
		cout<<"False";
}
