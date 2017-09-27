#!/usr/bin/python3
# -*- coding: utf-8 -*-

N, p = list(map(int, input().split()))
num = list(map(int, input().split()))
num.sort()

count = temp = 0
for i in range(N - count):
    if count == N:
        break
    for j in range(i+count, N):
        if j == N-1 or num[j+1] > num[i]*p:
            if num[j] <= num[i] * p:
                temp = j-i+1
                if temp > count:
                    count = temp
            break

print(count)