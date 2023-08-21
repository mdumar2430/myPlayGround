import java.util.*;

class BubblesSort {
	public static void main(int j, String... args) {
		Scanner in = new Scanner(System.in);
		System.out.print("Enter size of the array:");
		int size = in.nextInt();
		System.out.println("Enter the elements:");
		int[] arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = in.nextInt();
		}
		System.out.println("Entered array is:");
		for (int i = 0; i < size; i++) {
			System.out.print(+arr[i] + "\t");
		}
		for (int i = 0; i < size - 1; i++) {
			for (int k = 0; k < size - 1; k++) {
				int temp = 0;
				if (arr[k] > arr[k + 1]) {
					temp = arr[i];
					arr[i] = arr[k];
					arr[k] = temp;
				}
			}
		}
		System.out.println("\nSorted array using Bubble sort:");
		for (int i = 0; i < size; i++) {
			System.out.print(+arr[i] + "\t");
		}
	}
}