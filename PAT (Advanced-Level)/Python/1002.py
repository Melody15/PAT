#!/usr/bin/python3
# -*- coding: utf-8 -*-

originResult = [0]
result = originResult * 1001

inputline1 = input().split()
for i in range(int(inputline1[0])):
    result[int(inputline1[2*i+1])] += float(inputline1[2*i+2])

inputline2 = input().split()
for i in range(int(inputline2[0])):
    result[int(inputline2[2*i+1])] += float(inputline2[2*i+2])

KRresult = 0
for i in range(len(result)):
    if result[i] != 0:
        KRresult += 1

print(KRresult, end = '')

for i in range(1000, -1, -1):
    if result[i] != 0:
        print(" %d %.1f" % (i, result[i]), end = '')