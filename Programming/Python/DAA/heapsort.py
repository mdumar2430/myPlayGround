import time


def makeHeap(arr, size, iterator):
        largest = iterator
        left = 2 * iterator + 1
        right = 2 * iterator + 2
        if left < size and arr[largest] < arr[left]:
                largest = left

        if right < size and arr[largest] < arr[right]:
                largest = right

        if largest != iterator:
                arr[iterator], arr[largest] = arr[largest], arr[iterator]  # swap
                makeHeap(arr, size, largest)


def heapSort(arr):
        size = len(arr)
        for iterator in range(size // 2 - 1, -1, -1):
                makeHeap(arr, size, iterator)
        for iterator in range(size - 1, 0, -1):
                arr[iterator], arr[0] = arr[0], arr[iterator]  # swap
                makeHeap(arr, iterator, 0)


a = []
n = int(input("Enter size: "))
for i in range(n):
        a.append(int(input()))
print("Unsorted Array: ", a)
heapSort(a)
print("Sorted array: ", a)

print(time.process_time())
