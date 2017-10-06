#!/usr/bin/python3
# -*- coding: utf-8 -*-

pNum = 0
tNum = 0
sum = 0
patset = input()
for i in range(len(patset)):
    if patset[i] == 'T':
        tNum += 1
for i in range(len(patset)):
    if patset[i] == 'P':
        pNum += 1
    if patset[i] == 'T':
        tNum -= 1
    if patset[i] == 'A':
        sum = (sum +((pNum * tNum) % 1000000007)) % 1000000007
print(sum, end = '')

#testpoint 2 overtime
