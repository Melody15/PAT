#!/usr/bin/python3
# -*- coding: utf-8 -*-

data = input().split()
i = 1
while 2*i*i-1 <= int(data[0]):
    i += 1
i -= 1
remain = int(data[0])-2*i*i+1
j = 2*i-1
max = j

while j > 0:
    tem = i
    for k in range(tem, int((max+1)/2)):
        print(" ", end = '')
    for k in range(j, 0, -1):
        print(data[1], end = '')
    print("\n", end = '')
    i -= 1
    j = 2*i-1

i += 2
j = 2*i-1
while j <= max:
    tem = i
    for k in range(tem, int((max+1)/2)):
        print(" ", end = '')
    for k in range(j, 0, -1):
        print(data[1], end = '')
    print("\n", end = '')
    i += 1
    j = 2*i-1

print(remain, end = '')
