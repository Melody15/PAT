#!/usr/bin/python3
# -*- coding: utf-8 -*-

N = int(input())
infoData = {}

for i in range(N):
    tempData = input().split()
    if tempData[0] in infoData:
        infoData[tempData[0]] += int(tempData[1])
    else:
        infoData[tempData[0]] = int(tempData[1])

result = sorted(infoData.items(), key  = lambda item:item[1], reverse = True)

print(result[0][0], result[0][1])

#testpoint 3 overtime
