#!/usr/bin/python3
# -*- coding: utf-8 -*-

N_sequence = list(map(int, input().split()))
sumTime = presentFloor = previousFloor = 0

for i in N_sequence[1:]:
    presentFloor = i
    if presentFloor > previousFloor:
        sumTime += (presentFloor - previousFloor)*6
    elif presentFloor < previousFloor:
        sumTime += (previousFloor - presentFloor)*4
    sumTime += 5
    previousFloor = i
    
print(sumTime)
