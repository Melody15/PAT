#!/usr/bin/python3
# -*- coding: utf-8 -*-

num = list(map(int, input().split()))
result = []

if len(num) == 0 or len(num) == 2 and num[1] == 0:
    print("0 0")
    
else:
    for i in range(int(len(num)/2)):
        if num[2*i] != 0 and num[2*i+1] == 0:
            pass
        elif num[2*i] == 0 and num[2*i+1] == 0:
            result.append(0)
            result.append(0)
        else:
            result.append(num[2*i]*num[2*i+1])
            result.append(num[2*i+1]-1)

    for i in range(int(len(result)) - 1):
        print(result[i], end = ' ')
    print(result[int(len(result)) - 1])
