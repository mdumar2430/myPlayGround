def qsort(A, l, r):
        if r - 1 <= l:
                return ()
        l1 = l + 1
        for l2 in range(l + 1, r):
                if A[l2] <= A[l]:
                        (A[l1], A[l2]) = (A[l2], A[l1])
                        l1 = l1 + 1
        (A[l], A[l1 - 1]) = (A[l1 - 1], A[l])
        qsort(A, l, l1 - 1)
        qsort(A, l1, r)


n = int(input("Enter size: "))
l = []
for i in range(n):
        l.append(int(input()))

qsort(l, 0, len(l))
print(l)