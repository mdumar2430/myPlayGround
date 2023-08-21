def floyd(a):
        for k in range(len(a)):
                for i in range(len(a)):
                        for j in range(len(a)):
                                a[i][j] = min(a[i][j], (a[i][k] + a[k][j]))
        return a


def main():
        n = int(input("Enter the no of vertices:"))
        adj = []
        for i in range(0, n):
                ad = []
                for j in range(0, n):
                        e = int(input("Enter the weight of edge : "))
                        ad.append(e)
                adj.append(ad)
        # adj=[[0, 100, 3, 100], [2, 0, 100, 100], [100, 7, 0, 1], [6, 100, 100, 0]]
        print("Adjacent matrix: ", adj)

        d = floyd(adj)
        print("Shortest Path Matrix")
        for i in range(len(d)):
                for j in range(len(d)):
                        print(d[i][j], end=" ")
                print('')


main()

