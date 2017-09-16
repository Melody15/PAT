#!/usr/bin/python3
# -*- coding: utf-8 -*-

import math

def isPrime(N):  # judge whether
    for i in range(2, int(math.sqrt(N))+1, 1):  
        if N % i == 0:  
            return False  
    return True  

nums = list(map(int, input().split()))

index = 0
num = 2
while index < nums[0]-1 :
    if isPrime(num):
        num += 1
        index += 1
    else:
        num += 1

count = 0
while index < nums[1]:
    if isPrime(num):
        count += 1
        if count%10 == 0: 
            if index == nums[1]-1:
                print(num, end = '')
            else:
                print(num, end = '\n')
        else:
            if index == nums[1]-1:
                print(num, end = '')
            else:
                print(num, end = ' ')
        num += 1
        index += 1
    else:
        num += 1

#testpoint 4 overtime
