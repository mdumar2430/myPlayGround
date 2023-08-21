import java.util.Scanner;
public class InsertionSort{  
    public static void insertionSort(int array[]) {  
        int n = array.length;  
        for (int j = 1; j < n; j++) {  
            int key = array[j];  
            int i = j-1;  
            while ( (i > -1) && ( array [i] > key ) ) {  
                array [i+1] = array [i];  
                i--;  
            }  
            array[i+1] = key;  
        }  
    }  
       
    public static void main(String a[]){    
        Scanner in=new Scanner(System.in);
        System.out.print("Enter size of the array:");
        int size=in.nextInt();
        System.out.println("Enter the elements:");
        int[] arr1=new int[size];
        for(int i=0;i<size;i++){
	arr1[i]=in.nextInt();
        }
        System.out.println("Entered array is:");
        for(int i=0;i<size;i++){
	System.out.print(arr1[i]+"\t");
        }    
        System.out.println();    
        insertionSort(arr1);    
           
        System.out.println("After Insertion Sort");    
        for(int i=0;i<size;i++){    
            System.out.print(arr1[i]+"\t");    
        }    
    }    
}