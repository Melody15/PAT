#!/usr/bin/python3
# -*- coding: utf-8 -*-

N, use = input().split()
N = int(N)

if N%2 == 0:
    row = int(N/2)
else:
    row = int(N/2)+1

for j in range(row):
    if j == 0 or j == row-1:
        for i in range(N):
            print(use, end = '')
        print("")
    else:
        k = 0
        while k < N:
            if k == 0 or k == N-1:
                print(use, end = '')
            else:
                print(" ", end = '')
            k += 1
        print("")