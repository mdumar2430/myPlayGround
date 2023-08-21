import math


def bruteForce(a):
    res = {"p1": a[0], "p2": a[1], "d": math.sqrt((a[0][0] - a[1][0]) ** 2 + ( a[0][1] - a[1][1]) ** 2)}  # create dictionary with "pt1", "pt2", "d" as key and their respective values

    for i in range(len(a) - 1):
        for j in range(i + 1, len(a)):
            dist = math.sqrt((a[i][0] - a[j][0]) ** 2
                             + (a[i][1] - a[j][1]) ** 2)  # find the distance between other pairs of points
            if dist < res["d"]:  # To find if the distance found is the minimum of the distance stored in the dictionary
                res["p1"] = a[i]
                res["p2"] = a[j]
                res["d"] = dist
    return res

n = int(input("Enter Size: "))
arr = []
for i in range(n):
    a = int(input("Enter x coordinate: "))
    b = int(input("enter y coordinate: "))
    arr.append([a,b])
bf = bruteForce(arr)
print(bf["p1"], "," , bf["p2"], "," , bf["d"])