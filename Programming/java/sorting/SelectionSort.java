import java.util.*;
class SelectionSort
{
	public static void main(String... args)
	{
		Scanner in=new Scanner(System.in);
		System.out.print("Enter size of the array:");
		int size=in.nextInt();
		System.out.println("Enter the elements:");
		int[] arr=new int[size];
		for(int i=0;i<size;i++){
			arr[i]=in.nextInt();
		}
		System.out.println("Entered array is:");
                                     for(int i=0;i<size;i++){
			System.out.print(+arr[i]+"\t");
		}
		for(int i=0;i<size-1;i++)
		{
			int min=i;
			for(int j=i+1;j<size;j++)
			{
				if(arr[j]<arr[min])
					min=j;
			}
			int temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;		                   
		}
		System.out.println("\nSorted array using Selection sort:");
		for(int i=0;i<size;i++){
			System.out.print(+arr[i]+"\t");
		}	
	}
}