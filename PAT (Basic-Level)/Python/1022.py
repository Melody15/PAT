#!/usr/bin/python3
# -*- coding: utf-8 -*-

A, B, D = list(map(int, input().split()))
result = [0 for x in range(100)]
sum = A + B

if sum == 0:
    print("0", end = '')
    exit(0)

index = 0
while sum != 0:
    result[index] = int(sum % D)
    index += 1
    sum = int(sum / D)

for j in range(index-1, -1, -1):
    print(result[j], end = '')    
