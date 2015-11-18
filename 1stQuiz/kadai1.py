#coding: utf-8

import math
import matplotlib.pyplot as plt
import numpy as np

efs = []

num = 13

def nextEf(pef, ef):
    nef = [0.0]*num
    for i in range(0, num-1):
        nef[i+1] += 2 * ef[i]
    for i in range(0, num):
        nef[i] -= pef[i]
    return nef

def calcEfs():
    pef = [1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
    ef = [0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
    efs.append(pef)
    for i in range(0, num):
        efs.append(ef)
        nef = nextEf(pef, ef)
        pef = ef
        ef = nef
    return

def chebyshev(x, n):
    res = 0.0
    for i in range(0, num):
        res += float(efs[n][i]) * math.pow(x,i)
    return res


calcEfs()

print("ここから")
print(chebyshev(-0.75, 2))
print(chebyshev(-0.5, 3))
print(chebyshev(-0.25, 4))
print(chebyshev(0, 5))
print(chebyshev(0.25, 6))
print(chebyshev(0.5, 7))
print(chebyshev(0.75, 8))

print("描画")
f = np.poly1d(reversed(efs[0]))
plt.plot()
plt.show()
