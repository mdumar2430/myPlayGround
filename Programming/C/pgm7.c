//Stack implementation

#include <stdio.h>
int top=-1, cap=0;

int isFull(){
	if(top+1==cap)
		return 1;
	return 0;
}

int isEmpty(){
	if(top==-1)
		return 1;
	return 0;
}
int push(int *arr, int ins){
	if(!isFull()){
		arr[++top]=ins;
		return 1;
	}
	else
		return -1;
}

int pop(int *arr){
	if(!isEmpty()){
		arr[top--]=-1;
		return 1;
	}
	else
		return -2;
}

int main(){
	int i, ch, pushVal, res;
	printf("\nEnter Capacity: ");
	scanf("%d", &cap);
	int arr[cap];
	for(i=0; i<cap; i++)
		arr[i]= -1;
	do{
		printf("\n1.PUSH an element\n2.POP an element\n3.Display\nEnter your choice:");
		scanf("%d", &ch);
		switch(ch){
			case 1:{//Push
					printf("\nEnter a value:");
					scanf("%d", &pushVal);
					res = push(arr, pushVal);
					if(res== 1)
						printf("\nValue Inserted\n");
					else
						printf("\nStack full. Insertion failed\n");
			       }break;
			case 2:{//POP
				       res = pop(arr);
				       if(res==1)
					       printf("\nTop value pop'd\n");
				       else
					       printf("\nStack Empty - Pop failed\n");
			       }
			case 3:{//Display Stack
				       if(!isEmpty()){
				       		printf("\nStack:");
				       		for(i= top; i>=0; i--)
					       		printf("%d ", arr[i]);
						printf("\n");
				       }
				       else
					       printf("Stack Empty - No Elements to Display");
			       }
		}
	}while(ch<4);
}
