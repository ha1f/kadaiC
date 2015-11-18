#coding: utf-8
a = [[2.0,  1.0, -1.0], [6.0,  6.0, -1.0], [-4.0,  4.0,  3.0]]
unitMatrix = lambda n: [[(1 if i==j else 0) for j in range(0,n)] for i in range(0,n)]
l = unitMatrix(3)
u = unitMatrix(3)
for j,row in enumerate([[line[j] for line in a] for j in range(0, len(a))]):
    for i,value in enumerate(row):
        (u if i<= j else l)[i][j] = (value - sum([l[i][k] * u[k][j] for k in range(0, j)]))/u[j][j]
print(l)
print("-------")
print(u)


"""
a < 5 ? a : 0

"""
