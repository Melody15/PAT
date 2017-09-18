#!/usr/bin/python3
# -*- coding: utf-8 -*-

data = input().split()
times1 = data[0].count(data[1])
times2 = data[2].count(data[3])
PA = PB = ''

if times1 == 0:
    PA += '0'
else: 
    while times1 > 0:
        PA += data[1]
        times1 -= 1
if times2 == 0:
    PB += '0'
else:
    while times2 > 0:
        PB += data[3]
        times2 -= 1

print(int(PA) + int(PB))