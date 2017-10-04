#!/usr/bin/python3
# -*- coding: utf-8 -*-

weight = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
checkM = ['1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2']
flag = 0

N = int(input())
for i in range(N):
    idStr = input()
    idSum = 0
    for j in range(17):
        idSum += (ord(idStr[j])-ord('0'))*weight[j]
    if checkM[idSum%11] != idStr[17]:
        flag = 1
        print(idStr)
if flag == 0:
    print("All passed")