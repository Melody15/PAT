#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys

N, M, origin, target = map(int, input().split())
sumTempNum = [0 for x in range(N)]
pathNum = [0 for x in range(N)]
dist = [0 for x in range(N)]
S = [0 for x in range(N)]
#temp = [sys.maxsize for x in range(N)]
#arc = [temp]*N -> error
#just create 3 reference to temp, so once the temp changed, 3 list of arc would all change!
#the right way to create dyadic array
arc = [[sys.maxsize for i in range(N)] for i in range(N)]

rescueTemNum = list(map(int, input().split()))
sumTempNum[origin] = rescueTemNum[origin]
pathNum[origin] = 1

for i in range(M):
    m, n, data = map(int, input().split())
    arc[m][n] = data
    arc[n][m] = data

S[origin] = 1
for i in range(N):
    if i != origin:
        dist[i] = arc[origin][i]
        if dist[i] < sys.maxsize:
            pathNum[i] = 1
            sumTempNum[i] = sumTempNum[origin] + rescueTemNum[i]
        else:
            pathNum[i] = 0
            sumTempNum[i] = 0

for i in range(N):
    if i != origin:
        min = sys.maxsize
        v = -1
        for k in range(N):
            if S[k] == 0 and dist[k] < min:
                v = k
                min = dist[k]
        if v == -1:
            break
        S[v] = 1
        for k in range(N):
            if S[k] == 0 and arc[v][k] != sys.maxsize:
                if min < dist[k] - arc[v][k]:
                    dist[k] = min + arc[v][k]
                    pathNum[k] = pathNum[v]
                    sumTempNum[k] = sumTempNum[v] + rescueTemNum[k]
                elif min == dist[k] - arc[v][k]:
                    pathNum[k] = pathNum[k] + pathNum[v]
                    if sumTempNum[v] + rescueTemNum[k] > sumTempNum[k]:
                        sumTempNum[k] = sumTempNum[v] + rescueTemNum[k]

print("%d %d" % (pathNum[target], sumTempNum[target]), end = '')
