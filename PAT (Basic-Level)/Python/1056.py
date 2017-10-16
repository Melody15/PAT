#!/usr/bin/python3
# -*- coding: utf-8 -*-

data = list(map(int, input().split()))
sum = 0
for i in range(1, data[0]+1):
    for j in range(i+1, data[0]+1):
        if i != j and data[i] != data[j]:
            sum += data[i]*10+data[j]
            sum += data[j]*10+data[i]
        elif i != j and data[i] == data[j]:
            sum += data[i]*10+data[j]
print(sum)
