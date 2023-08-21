import time


def shiftTable(p):
        table = {}
        m = len(p)
        for i in range(len(p) - 1):
                table[p[i]] = m - i - 1
        return table


def horspool(t, p):
        table = shiftTable(p)
        m = len(p)
        n = len(t)
        i = m - 1
        while i <= n - 1:
                k = 0
                while k <= m - 1 and p[m - 1 - k] == t[i - k]:
                        k = k + 1
                if k == m:
                        return i - m + 1
                else:
                        if t[i] in table:
                                i = i + table[t[i]]
                        else:
                                i = i + m
        return -1


def main():
        text = input("Enter the Text: ")
        pattern = input("Enter the pattern: ")
        index = horspool(text, pattern)
        if index == -1:
                print("The Pattern is not Found.")
        else:
                print("The Pattern found at index: ", index)


main()
# t2=time.localtime()
for i in range(5):
       print(i)
