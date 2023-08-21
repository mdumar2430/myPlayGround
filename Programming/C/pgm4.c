//32. C Program to accept list of numbers and display it in reverse order
#include <stdio.h>
int main(){
	int capacity=0, i;
	printf("Enter Capacity:");
	scanf("%d", &capacity);
	int arr[capacity];
	printf("\nEnter Values one by one:\n");
	for(i=0; i<capacity; i++)
		scanf("%d", &arr[i]);
	printf("\nBefore Reversing: ");
	for(i=0; i<capacity; i++)
		printf("%d ", arr[i]);
	printf("\nAfter Reversing: ");
	for(i=capacity-1; i>=0; i--)
		printf("%d ", arr[i]);
	printf("\n");
}
