#!/usr/bin/python3
# -*- coding: utf-8 -*-

maxProfit = 1.0
for i in range(3):
    maxNum = 0.0
    data = list(map(float, input().split()))
    tempIndex = -1
    for j in range(3):
        if data[j] > maxNum:
            maxNum = data[j]
            tempIndex = j
    maxProfit *= maxNum
    if tempIndex == 0:
        print("W", end = ' ')
    elif tempIndex == 1:
        print("T", end = ' ')
    elif tempIndex == 2:
        print("L", end = ' ')
maxProfit = (maxProfit * 0.65 -1) * 2
print("%.2f" % maxProfit)


