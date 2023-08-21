//42.C program to add two complex numbers

#include <stdio.h>
int main(){
	int real[2], img[2], sum[2];
	printf("\n---->Complex Number Addition<----\n");
	printf("Complex Number 1~\nReal value:");
	scanf("%d", &real[0]);
	printf("Imaginary value:");
	scanf("%d", &img[0]);
	printf("Complex Number 2~\nReal value:");
	scanf("%d", &real[1]);
	printf("Imaginary value:");
	scanf("%d", &img[1]);
	printf("Complex Number 1 = %d + %di\n", real[0],img[0]);
	printf("Complex Number 2 = %d + %di\n", real[1],img[1]);
	sum[0]= real[0] + real[1];
	sum[1]= img[0] + img[1];
	printf("Sum = %d + %di\n", sum[0],sum[1]);
}
