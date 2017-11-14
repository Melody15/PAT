#!/usr/bin/python3
# -*- coding: utf-8 -*-

inputData = [0.0 for x in range(1000+1)]
result = [0.0 for x in range(2000+1)]

data = input().split()
for i in range(int(data[0])):
    a = int(data[2*i+1])
    b = float(data[2*i+2])
    inputData[a] = b

data = input().split()
for i in range(int(data[0])):
    a = int(data[2*i+1])
    b = float(data[2*i+2])
    for j in range(1001):
        result[j+a] += inputData[j]*b

count = 0
for i in result:
    if i != 0.0:
        count += 1
print(count, end = '')

for i in range(2000, -1, -1):
    if result[i] != 0.0:
        print(" %d %.1f" % (i, result[i]), end = '')

