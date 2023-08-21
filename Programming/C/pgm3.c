//22. C program to find sum of Series : 1^2 + 2^2 + 3^2 + 4^2 + …. + N^2

#include <stdio.h>
int main(){
	int num, i, sum=0, sqr=0;
	printf("\nEnter no. of terms:");
	scanf("%d", &num);
	for(i=1; i<=num; i++){
		sqr = i*i;
		sum = sum + sqr;
	}
	printf("Sum = %d\n", sum);
}
