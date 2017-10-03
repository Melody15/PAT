#!/usr/bin/python3
# -*- coding: utf-8 -*-

N = int(input())
score = list(map(int, input().split()))
query = list(map(int, input().split()))

for j in range(1, query[0]+1):
    count = 0
    for i in range(N):
        if query[j] == score[i]:
            count += 1
    if j < query[0]:
        print(count, end = ' ')
    elif j == query[0]:
        print(count, end = '')

#testpoint 3 overtime
