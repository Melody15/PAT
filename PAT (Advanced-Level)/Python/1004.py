#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys

N, M = map(int, input().split())
nodes = [[] for i in range(N+1)]
level = [-1 for x in range(N+1)]
level[1] = 0
for i in range(M):
    data = list(map(int, input().split()))
    for j in data[2:]:
        nodes[data[0]].append(j)

maxlevel = 0
for i in range(1, N+1):
    for j in nodes[i]:
        level[j] = level[i]+1
        if maxlevel < level[j]:
            maxlevel = level[j]

count = 0
for i in range(maxlevel+1):
    count = 0
    for j in range(1, N+1):
        if level[j] == i:
            if len(nodes[j]) == 0:
                count += 1
    if i < maxlevel:
        print(count, end = ' ')
    else:
        print(count)