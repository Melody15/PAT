#!/usr/bin/python3
# -*- coding: utf-8 -*-

N = int(input())
result = [0 for x in range(37)]
friendnum = count = 0
data = list(map(int, input().split()))

for i in data:
    friendnum = 0
    temp = i
    while temp > 0:
        friendnum += (temp%10)
        temp = int(temp / 10)
    if result[friendnum] == 0:
        count+=1
        result[friendnum] = 1

print(count)

for i in range(37):
    if result[i] == 1 and count != 1:
        print(i, end = ' ')
        count -= 1
    elif result[i] == 1 and count == 1:
        print(i)
