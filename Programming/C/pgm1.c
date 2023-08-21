//C program to find prime numbers between two Limits

#include <stdio.h>

int main(){
	int start, end, i, j, count=0;
	printf("\nEnter range~\nSTART:");
	scanf("%d", &start);
	printf("END:");
	scanf("%d", &end);
	printf("\nPrime Numbers found are~\n");
	for(i= start; i<=end; i++){
		for(j=1; j<=i; j++){
			if(i%j == 0){
				count++;
			}
		}
		if(count == 2){
			printf("%d \n",i);
		}
		count=0;
	}
}
