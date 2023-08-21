#include <stdio.h>

int main(){
	int i, num;
	printf("\nEnter number values:");
	scanf("%d", &num);
	int arr[num];
	printf("Enter values one by one~\n");
	for(i=0; i<num; i++)
		scanf("%d", &arr[i]);
	for(i=0; i<num; i++)
		if(arr[i]%2 == 0)
			arr[i]=1;
		else
			arr[i]=0;
	for(i=0; i<num; i++)
		printf("%d ", arr[i]);

}
