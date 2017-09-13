#!/usr/bin/python3
# -*- coding: utf-8 -*-

N_M = input().split()
num = list(map(int, input().split()))

for i in range(int(N_M[1])):
    num.insert(0, num.pop()) 
    #pop() remove the last element by defaule, so pop() and insert it into list's head(index = 0) M times

result = ''                   #for print as demand
for i in num:
    result += str(i) + ' '

print(result.strip())  
