//12.C program to find HCF of two numbers 

#include <stdio.h>
int main(){
	int i, j, num1, num2, factorsNum1[100], factorsNum2[200], index1=0, index2=0, hcf=0;
	printf("--->HCF finder<---\n");
	printf("Enter 1st Number:");
	scanf("%d", &num1);
	printf("\nEnter 2nd Number:");
	scanf("%d", &num2);
	for(i= 1; i<=num1; i++){
		if(num1%i == 0){
			factorsNum1[index1++] = i;
		}
	}
	for(i= 1; i<=num2; i++){
		if(num2%i == 0){
			factorsNum2[index2++] = i;
		}
	}
	printf("Factors of %d:", num1);
	for(i = 0; i<index1 ; i++)
		printf("%d ", factorsNum1[i]);
	printf("\nFactors of %d:", num2);
	for(i = 0; i<index2 ; i++)
		printf("%d ", factorsNum2[i]);
	for(i = 0; i<index1; i++)
		for(j = 0; j<index2; j++)
			if(factorsNum1[i]==factorsNum2[j])
				hcf= factorsNum1[i];
	printf("\nHCF = %d\n", hcf);
}
