#!/usr/bin/python3
# -*- coding: utf-8 -*-

import math  

def isPrime(N):  # judge whether
    for i in range(2, int(math.sqrt(N))+1, 1):  
        if N % i == 0:  
            return False  
    return True  

n = int(input())

'''count = 0
for i in range(3, n-1): # range(1, n) means from 1 to n-1
    if isPrime(i) and isPrime(i + 2):
        count = count + 1
print(count)
#overtime!!!
'''
#do not know why
result = [i for i in range(3, n-1) if isPrime(i) and isPrime(i+2)]  # put the suitable i in the list li
print(len(result)) 
