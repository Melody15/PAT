#!/usr/bin/python3
# -*- coding: utf-8 -*-
M, N, A, B, replaceNum = input().split()
M = int(M)
N = int(N)
A = int(A)
B = int(B)
replaceNum = int(replaceNum)

for i in range(M):
    data = list(map(int, input().split()))
    for j in range(N):
        temp = data[j]
        if data[j] >= A and data[j] <= B:
            temp = replaceNum
        print("%03d" % temp, end = '')
        if j == N-1:
            print()
        else:
            print(" ", end = '')

#testpoint3 overtime