#coding: utf-8
import time

start = time.time()
a=[]
for i in range(0,10000000):
    a.append(i)
elapsed_time = time.time() - start
print(("elapsed_time:{0}".format(elapsed_time)) + "[sec]")
