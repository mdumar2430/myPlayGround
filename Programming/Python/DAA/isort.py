def InsertionSort(l):
        n = len(l)
        for i in range(n):
                for j in range(n - 1):
                        if l[j] > l[j + 1]:
                                l[j], l[j + 1] = l[j + 1], l[j]
        print(l)


n = int(input("Enter size: "))
l = []
for _ in range(n):
        l.append(int(input()))
InsertionSort(l)