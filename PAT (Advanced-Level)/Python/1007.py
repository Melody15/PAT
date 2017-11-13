#!/usr/bin/python3
# -*- coding: utf-8 -*-

N = int(input())
sequence = list(map(int, input().split()))

tempsum = tempLeftIndex = 0
sum = -1
leftIndex = 0
rightIndex = N-1

for i in range(N):
    tempsum += sequence[i]
    if tempsum < 0:
        tempsum = 0
        tempLeftIndex = i+1
    elif tempsum > sum:
        sum = tempsum
        leftIndex = tempLeftIndex
        rightIndex = i

if sum < 0:
    sum = 0
print("%d %d %d" % (sum, sequence[leftIndex], sequence[rightIndex]))